// Example 5-4. Set the LED to a brightness specified by the value of the analogue input

const int LED = 9;    // the pin for the LDE

int val = 0;  // variable used to store the value
              // comming from the sensor

void setup() {

  pinMode(LED, OUTPUT);     // LED is an output

  // Note: Analogue pins are
  // automatically set as inputs
}

void loop() {

  val = analogRead(0);  // read the value from
                        // the sensor
  analogWrite(LED, val/4);  // turn the LED on at
                            // the brightness set
                            // by the sensor

  delay(val); // stop the program for
              // some time
}
