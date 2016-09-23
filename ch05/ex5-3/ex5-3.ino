// Example 5-3. Blink LED at a rate specified by the value of the analogue input

const int LED = 13;   // the pin for the LDE

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

  digitalWrite(LED, HIGH);  // turn the LED on

  delay(val); // stop the program for
              // some time

  digitalWrite(LED, LOW); // turn the LED off

  delay(val); // stop the program for
              // some time
}
