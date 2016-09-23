// Example 4-1. Blinking LDE

// Blinking LDE

const int LED = 13; // LDE connected to 
                    // digital pin 13
                    
void setup() {
  pinMode(LED, OUTPUT);     // sets the digital
                            // pin as output
}

void loop() {
  digitalWrite(LED, HIGH);  // turns the LED on
  delay(1000);              // waits for a second
  digitalWrite(LED, LOW);   // turns the LED off
  delay(1000);              // waits for a second
}
