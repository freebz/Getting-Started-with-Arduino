// Example 8-3. Turn on the water only if it's not raining

if ( ( nowMinutesSinceMidnight >= onOffTimes[valve][ONTIME]) &&
     ( nowMinutesSinceMidnight < onOffTimes[valve][OFFTIME]) ) {
     // Before we turn a valve on make sure it's not raining
     if ( humidityNow > 50) { // Arbitrary; adjust as necessary
       // It's raining; turn the valve OFF
       Serial.print(" OFF ");
       digitalWrite(valvePinNumbers[valve], LOW);
     }
     else {
       // No rain and it's time to turn the valve ON
       Serial.print(" ON ");
       digitalWrite(valvePinNumbers[valve], HIGH);
     } // end of checking for rain
} // end of checking for time to turn valve ON
   else {
     Serial.print(" OFF ");
     digitalWrite(valvePinNumbers[valve], LOW);
   }


void loop() {

  // Remind user briefly of possible commands
  Serial.print("TYpe 'P' to print settings or 'S2N13:45'");
  Serial.println(" to set valve 2 ON time to 13:34");

  // Get (and pirnt) the current date, time,
  // temperature, and humidity
  getTimeTempHumidity();

  // Check for new time settings:
  expectValveSettings();

  // Check to see whether it's time to turn any
  // valve ON or OFF
  checkTimeControlVavles();

  // No need to do this too frequently
  delay(5000);
}

/*
 * Check for user interaction, which will
 * be in the form of something typed on
 * the serial monitor.
 * 
 * If there is anything, make suer it's
 * properly-formed, and perform the
 * requested action.
 */
void checkUserInteraction() {

  // Check for user interaction
  while (Serial.available() > 0) {

    // The first character tells us what to expect for the
    // rest of the line
    char temp = Serial.read();

    // If the first character is 'P'
    // then print the current settings
    // and break out of the while() loop
    if ( temp == 'P') {

      printSettings();
      Serial.flush();
      break;
      
    } // end of printing current settings

    // If first character is 'S'
    // then the rest will be a setting
    else if ( temp == 'S') {
      expectValveSetting();
    }

    // Otherwise, it's an error. Remind the user
    // what the choices are and break out of the
    // while() loop
    else
    {
      printMenu();
      Serial.flush();
      break;
    }
    
  } // end of processing user interaction
  
}

void printMenu() {
  Serial.println(
    "Please enter P to print the current settings");
  Serial.println(
    "Please enter S2N13:45 to set valve 2 ON time to 13:34");
}
