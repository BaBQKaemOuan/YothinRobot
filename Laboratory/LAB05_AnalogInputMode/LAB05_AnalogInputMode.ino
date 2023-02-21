int POT_Pin = A5;     // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int Poten_Value = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Poten_Value = analogRead(POT_Pin);
  Serial.print(" Poten value = ");
  Serial.println(Poten_Value);
  digitalWrite(ledPin, HIGH);
  delay(Poten_Value);
  digitalWrite(ledPin, LOW);
  delay(Poten_Value);
}
