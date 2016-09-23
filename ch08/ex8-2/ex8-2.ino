// Example 8-2. The expectValveSetting() function

/*
 * Example 8-2. expectValveSetting() and printSettings() functions
 * Read a string of the form "2N13:45" and separate it into the
 * valve number, the letter indicating ON or OFF, and the time
 */

void expectValveSetting() {

  // The first integer should be the valve number
  int valveNumber = Serial.parseInt();

  // the next character should be either N or F
  char onOff = Serial.read();

  int desiredHour = Serial.parseInt();  // get the hour

  // the next character should be ':'
  if (Serial.read() != ':') {
    Serial.println("no : found"); // Sanity check
    Serial.flush();
    return;
  }

  int desiredMinutes = Serial.parseInt(); // get the minutes

  // finally expect a newline which is the end of the sentence:
  if (Serial.read() != '\n') {  // Sanity check
    Serial.println("You must end your request with a Newline");
    Serial.flush();
    return;
  }

  // Convert desired time to # of minutes since midnight
  int desiredMinutesSinceMidnight
    = (desiredHour*60 + desiredMinutes);

  // Put time into the array in the correct row/column
  if ( onOff == 'N') { // it's an ON time
    onOffTimes[valveNumber][ONTIME]
    = desiredMinutesSinceMidnight;
  }
  else if ( onOff == 'F') {  // it's an OFF time
    onOffTimes[valveNumber][OFFTIME]
    = desiredMinutesSinceMidnight;
  }
  else { // user didn't use N or F
    Serial.print("You must use upper case N or F ");
    Serial.println("to indicate ON time or OFF time");
    Serial.flush();
    return;
  }

  printSettings();  // print the array so user can confirm settings
} // end of expectValveSetting()

void printSettings() {
  // Print current on/off settings, converting # of minutes since
  // midnight back to the time in hours and minutes
  Serial.println();
  for (int valve = 0; valve < NUMBEROFVALVES; valve++) {
    Serial.print("Value ");
    Serial.print(valve);
    Serial.print(" will turn ON at ");

    // integer division drops remainder: divide by 60 to get hours
    Serial.print((onOffTimes[valve][ONTIME])/60);
    Serial.print(":");

    // minutes % 60 are the remainder (% is the modulo operator)
    Serial.print((onOffTimes[valve][ONTIME])%(60));

    Serial.print(" and will turn OFF at ");
    Serial.print((onOffTimes[valve][OFFTIME])/60);  // hours
    Serial.print(":");
    Serial.print((onOffTimes[valve][OFFTIME])%(60)); // minutes
    Serial.println();
  }
}
