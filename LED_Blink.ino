// Built-in LED is connected to digital pin 13
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin 13 as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(10000);                // Wait 1 second
  digitalWrite(ledPin, LOW);  // Turn LED OFF
  delay(10000);                // Wait 1 second
}