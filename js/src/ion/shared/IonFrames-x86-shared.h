/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim: set ts=4 sw=4 et tw=79:
 *
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code, released
 * March 31, 1998.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   David Anderson <dvander@alliedmods.net>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
#ifndef js_ion_frame_layouts_x86_h__
#define js_ion_frame_layouts_x86_h__

namespace js {
namespace ion {

class IonCommonFrameLayout
{
  private:
    uint8 *returnAddress_;
    uintptr_t descriptor_;

    static const uintptr_t FrameTypeMask = (1 << FRAMETYPE_BITS) - 1;

  public:
    static size_t offsetOfDescriptor() {
        return offsetof(IonCommonFrameLayout, descriptor_);
    }
    static size_t offsetOfReturnAddress() {
        return offsetof(IonCommonFrameLayout, returnAddress_);
    }
    FrameType prevType() const {
        return FrameType(descriptor_ & FrameTypeMask);
    }
    void changePrevType(FrameType type) {
        descriptor_ &= ~FrameTypeMask;
        descriptor_ |= type;
    }
    size_t prevFrameLocalSize() const {
        return descriptor_ >> FRAMESIZE_SHIFT;
    }
    void setFrameDescriptor(size_t size, FrameType type) {
        descriptor_ = (size << FRAMESIZE_SHIFT) | type;
    }
    uint8 *returnAddress() const {
        return returnAddress_;
    }
};

class IonJSFrameLayout : public IonCommonFrameLayout
{
    void *calleeToken_;
    uintptr_t numActualArgs_;

  public:
    CalleeToken calleeToken() const {
        return calleeToken_;
    }
    void replaceCalleeToken(void *value) {
        calleeToken_ = value;
    }

    static size_t offsetOfCalleeToken() {
        return offsetof(IonJSFrameLayout, calleeToken_);
    }
    static size_t offsetOfNumActualArgs() {
        return offsetof(IonJSFrameLayout, numActualArgs_);
    }
    static size_t offsetOfActualArgs() {
        IonJSFrameLayout *base = NULL;
        // +1 to skip |this|.
        return reinterpret_cast<size_t>(&base->argv()[1]);
    }

    Value *argv() {
        return (Value *)(this + 1);
    }
    uintptr_t numActualArgs() const {
        return numActualArgs_;
    }

    // Computes a reference to a slot, where a slot is a distance from the base
    // frame pointer (as would be used for LStackSlot).
    uintptr_t *slotRef(uint32 slot) {
        return (uintptr_t *)((uint8 *)this - (slot * STACK_SLOT_SIZE));
    }

    static inline size_t Size() {
        return sizeof(IonJSFrameLayout);
    }
};

class IonEntryFrameLayout : public IonJSFrameLayout
{
  public:
    static inline size_t Size() {
        return sizeof(IonEntryFrameLayout);
    }
};

class IonRectifierFrameLayout : public IonJSFrameLayout
{
  public:
    static inline size_t Size() {
        return sizeof(IonRectifierFrameLayout);
    }
};

// The callee token is now dead.
class IonBailedRectifierFrameLayout : public IonRectifierFrameLayout
{
  public:
    static inline size_t Size() {
        return sizeof(IonBailedRectifierFrameLayout);
    }
};

// GC related data used to keep alive data surrounding the Exit frame.
class IonExitFooterFrame
{
    const VMFunction *function_;
    IonCode *ionCode_;

  public:
    static inline size_t Size() {
        return sizeof(IonExitFooterFrame);
    }
    inline IonCode *ionCode() const {
        return ionCode_;
    }
    inline IonCode **addressOfIonCode() {
        return &ionCode_;
    }
    inline const VMFunction *function() const {
        return function_;
    }
};

class IonNativeExitFrameLayout;

class IonExitFrameLayout : public IonCommonFrameLayout
{
    inline uint8 *top() {
        return reinterpret_cast<uint8 *>(this + 1);
    }

  public:
    static inline size_t Size() {
        return sizeof(IonExitFrameLayout);
    }
    static inline size_t SizeWithFooter() {
        return Size() + IonExitFooterFrame::Size();
    }

    inline IonExitFooterFrame *footer() {
        uint8 *sp = reinterpret_cast<uint8 *>(this);
        return reinterpret_cast<IonExitFooterFrame *>(sp - IonExitFooterFrame::Size());
    }

    // argBase targets the point which precedes the exit frame. Arguments of VM
    // each wrapper are pushed before the exit frame.  This correspond exactly
    // to the value of the argBase register of the generateVMWrapper function.
    inline uint8 *argBase() {
        JS_ASSERT(footer()->ionCode() != NULL);
        return top();
    }
    inline IonNativeExitFrameLayout *nativeExit() {
        // see CodeGenerator::visitCallNative
        JS_ASSERT(footer()->ionCode() == NULL);
        return reinterpret_cast<IonNativeExitFrameLayout *>(footer());
    }
};

class IonNativeExitFrameLayout
{
    IonExitFooterFrame footer_;
    IonExitFrameLayout exit_;
    uintptr_t argc_;
    Value calleeResult_;

  public:
    static inline size_t Size() {
        return sizeof(IonNativeExitFrameLayout);
    }

    static size_t offsetOfResult() {
        return offsetof(IonNativeExitFrameLayout, calleeResult_);
    }
    inline Value *vp() {
        return &calleeResult_;
    }
    inline uintptr_t argc() const {
        return argc_;
    }
};

class IonOsrFrameLayout : public IonJSFrameLayout
{
  public:
    static inline size_t Size() {
        return sizeof(IonOsrFrameLayout);
    }
 };

// An invalidation bailout stack is at the stack pointer for the callee frame.
class InvalidationBailoutStack
{
    double      fpregs_[FloatRegisters::Total];
    uintptr_t   regs_[Registers::Total];
    IonScript   *ionScript_;
    uint8       *osiPointReturnAddress_;

  public:
    uint8 *sp() const {
        return (uint8 *) this + sizeof(InvalidationBailoutStack);
    }
    IonJSFrameLayout *fp() const;
    MachineState machine() {
        return MachineState::FromBailout(regs_, fpregs_);
    }

    IonScript *ionScript() const {
        return ionScript_;
    }
    uint8 *osiPointReturnAddress() const {
        return osiPointReturnAddress_;
    }

    void checkInvariants() const;
};

}
}

#endif // js_ion_frame_layouts_x86_h__

