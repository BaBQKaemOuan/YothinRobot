#define port_IRsen 1
#define port_Relay 2

bool state = 0;

void setup() {
  pinMode(port_IRsen, INPUT);
  pinMode(port_Relay, OUTPUT);
}

void loop() {
  state = digitalRead(port_IRsen);
  Serial.println(state);

  if (state = true)
  {
    digitalWrite(port_Relay, HIGH);
  }
  else
  {
    digitalWrite(port_Relay, LOW);
  }
}
