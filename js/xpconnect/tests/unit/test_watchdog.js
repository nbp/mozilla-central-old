/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

//
// Pref management.
//

const Cc = Components.classes;
const Ci = Components.interfaces;
const Cu = Components.utils;

var gPrefs = Cc["@mozilla.org/preferences-service;1"].getService(Ci.nsIPrefBranch);

function setWatchdogEnabled(enabled) {
  gPrefs.setBoolPref("dom.use_watchdog", enabled);
}

function isWatchdogEnabled() {
  return gPrefs.getBoolPref("dom.use_watchdog");
}

//
// Utilities.
//

function busyWait(ms) {
  var start = new Date();
  while ((new Date()) - start < ms) {}
}

function do_log_info(aMessage)
{
  print("TEST-INFO | " + _TEST_FILE + " | " + aMessage);
}

// We don't use do_execute_soon, because that inserts a
// do_test_{pending,finished} pair that gets screwed up when we terminate scripts
// from the operation callback.
function executeSoon(fn) {
  var tm = Cc["@mozilla.org/thread-manager;1"].getService(Ci.nsIThreadManager);
  tm.mainThread.dispatch({run: fn}, Ci.nsIThread.DISPATCH_NORMAL);
}

//
// Asynchronous watchdog diagnostics.
//
// When running, the watchdog wakes up every second, and fires the operation
// callback if the script has been running for >= one second. As such, a script
// should never be able to run for two seconds or longer without servicing the
// operation callback. We wait 3 seconds, just to be safe.
//

function checkWatchdog(expectInterrupt, continuation) {
  var lastWatchdogWakeup = Cu.getWatchdogTimestamp("WatchdogWakeup");
  setOperationCallback(function() {
    // If the watchdog didn't actually trigger the operation callback, ignore
    // this call. This allows us to test the actual watchdog behavior without
    // interference from other sites where we trigger the operation callback.
    if (lastWatchdogWakeup == Cu.getWatchdogTimestamp("WatchdogWakeup")) {
      return true;
    }
    do_check_true(expectInterrupt);
    setOperationCallback(undefined);
    // Schedule our continuation before we kill this script.
    executeSoon(continuation);
    return false;
  });
  executeSoon(function() {
    busyWait(3000);
    do_check_true(!expectInterrupt);
    setOperationCallback(undefined);
    continuation();
  });
}

var gGenerator;
function continueTest() {
  gGenerator.next();
}

function run_test() {

  // Run async.
  do_test_pending();

  // Instantiate the generator and kick it off.
  gGenerator = testBody();
  gGenerator.next();
}

function testBody() {

  // Before munging any prefs, check that we properly implement whatever behavior
  // is specified by the default profile for this configuration.
  checkWatchdog(isWatchdogEnabled(), continueTest);
  yield;

  // Toggle the watchdog, and check that state.
  var was = isWatchdogEnabled();
  setWatchdogEnabled(!isWatchdogEnabled());
  do_check_true(was != isWatchdogEnabled());
  checkWatchdog(isWatchdogEnabled(), continueTest);
  yield;

  // Now, make sure the watchdog is on.
  setWatchdogEnabled(true);
  do_check_true(isWatchdogEnabled());
  checkWatchdog(true, continueTest);
  yield;

  //
  // Now, check hibernation.
  //

  // It's unlikely that we've ever hibernated at this point, but the timestamps
  // default to 0, so this should always be true.
  var now = Date.now() * 1000;
  var startHibernation = Cu.getWatchdogTimestamp("WatchdogHibernateStart");
  var stopHibernation = Cu.getWatchdogTimestamp("WatchdogHibernateStop");
  do_log_info("Pre-hibernation statistics:");
  do_log_info("now: " + now / 1000000);
  do_log_info("startHibernation: " + startHibernation / 1000000);
  do_log_info("stopHibernation: " + stopHibernation / 1000000);
  do_check_true(startHibernation < now);
  do_check_true(stopHibernation < now);

  // When the watchdog runs, it hibernates if there's been no activity for the
  // last 2 seconds, otherwise it sleeps for 1 second. As such, given perfect
  // scheduling, we should never have more than 3 seconds of inactivity without
  // hibernating. To add some padding for automation, we mandate that hibernation
  // must begin between 2 and 5 seconds from now.
  var timer = Cc["@mozilla.org/timer;1"].createInstance(Ci.nsITimer);
  timer.initWithCallback(continueTest, 10000, Ci.nsITimer.TYPE_ONE_SHOT);
  simulateActivityCallback(false);
  yield;

  simulateActivityCallback(true);
  busyWait(1000); // Give the watchdog time to wake up on the condvar.
  var stateChange = Cu.getWatchdogTimestamp("RuntimeStateChange");
  startHibernation = Cu.getWatchdogTimestamp("WatchdogHibernateStart");
  stopHibernation = Cu.getWatchdogTimestamp("WatchdogHibernateStop");
  do_log_info("Post-hibernation statistics:");
  do_log_info("stateChange: " + stateChange / 1000000);
  do_log_info("startHibernation: " + startHibernation / 1000000);
  do_log_info("stopHibernation: " + stopHibernation / 1000000);
  // XPCOM timers, JS times, and PR_Now() are apparently not directly
  // comparable, as evidenced by certain seemingly-impossible timing values
  // that occasionally get logged in windows automation. We're really just
  // making sure this behavior is roughly as expected on the macro scale,
  // so we add a 1 second fuzz factor here.
  const FUZZ_FACTOR = 1 * 1000 * 1000;
  do_check_true(stateChange > now + 10*1000*1000 - FUZZ_FACTOR);
  do_check_true(startHibernation > now + 2*1000*1000 - FUZZ_FACTOR);
  do_check_true(startHibernation < now + 5*1000*1000 + FUZZ_FACTOR);
  do_check_true(stopHibernation > now + 10*1000*1000 - FUZZ_FACTOR);

  do_test_finished();
  yield;
}
