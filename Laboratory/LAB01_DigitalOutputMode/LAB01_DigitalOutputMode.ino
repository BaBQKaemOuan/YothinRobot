void setup() {
  pinMode(19, OUTPUT);    // Set Digital Pin 19 as an Output
}

void loop() {
  digitalWrite(19, HIGH); // Turn on the fan
  delay(1000);            // Delay (do nothing) for 1000ms(1 of a second)
  digitalWrite(19, LOW);  // Turn off the fan
  delay(1000);            // Delay (do nothing) for 1000ms(1 of a second)
}
