const int SW_ON = 13;   // Switch SW_ON PIN 13
const int SW_OFF = 12;  // Switch SW_OFF PIN 12
const int Fan = 19;     // Fan PIN 19

int buttonState_Red;
int buttonState_Green;

void setup() {
  pinMode(Fan, OUTPUT);
  pinMode(SW_ON, INPUT);
  pinMode(SW_OFF, INPUT);
}

void loop() {
  buttonState_Red = digitalRead(SW_ON);
  buttonState_Green = digitalRead(SW_OFF);

  if ((buttonState_Green == HIGH) && (buttonState_Red == LOW)) {
    digitalWrite(Fan, HIGH);
  }
  else if ((buttonState_Green == LOW) && (buttonState_Red == HIGH)) {
    digitalWrite(Fan, LOW);
  }
  else {
    digitalWrite(Fan, LOW);
  }
}
