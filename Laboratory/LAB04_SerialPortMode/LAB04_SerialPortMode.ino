int i = 0; // Declare a variable "i" and initialize it to 0
void setup() {
  Serial.begin(9600); // Start serial communications at 9600 baud
  Serial.println("Hello World!");
}
void loop() {
  Serial.print("i = "); // Print "i = " to the serial port
  Serial.println(i);    // Print the value of "i"
  i = i + 1;            // Add one to "i" (so it's higher for the next time)
  delay(1000);          // delay 1 second
}
