#define PWMA  6
#define INA_1 5
#define INA_2 4

#define PWMB  9
#define INB_1 8
#define INB_2 7

#define RELAY_PIN A5

#define ENCODER_A 2
#define ENCODER_B 3

#define SW_GREEN 12
#define SW_RED   13

#define INFRA_PIN A7

uint8_t sensors[5] = {A4, A3, A2, A1, A0};

uint32_t count_a = 0;
uint32_t count_b = 0;

#define MAX_SPEED 255

#define ON  1
#define OFF 0

void setup() {
  Serial.begin(9600);

  pinMode(PWMA, OUTPUT);
  pinMode(INA_1, OUTPUT);
  pinMode(INA_2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(INB_1, OUTPUT);
  pinMode(INB_2, OUTPUT);

  pinMode(RELAY_PIN, OUTPUT);

  pinMode(ENCODER_A, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_A), Arising, RISING);

  pinMode(ENCODER_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), Brising, RISING);

  pinMode(SW_GREEN, INPUT);
  pinMode(SW_RED, INPUT);

  pinMode(INFRA_PIN, INPUT);

  pinMode(sensors[0], INPUT);
  pinMode(sensors[1], INPUT);
  pinMode(sensors[2], INPUT);
  pinMode(sensors[3], INPUT);
  pinMode(sensors[4], INPUT);
}

void loop() {
  Relay(OFF);
  //  printOverAll();
  //  delay(10);
  //  Motor(-200, -200);
}

void Relay(bool state) {
  digitalWrite(RELAY_PIN, state);
}

void printOverAll() {
  Serial.print(digitalRead(SW_GREEN));   Serial.print("\t");
  Serial.print(digitalRead(SW_RED));     Serial.print("\t");
  Serial.print(count_a);                 Serial.print("\t");
  Serial.print(count_b);                 Serial.print("\t");
  Serial.print(digitalRead(sensors[0])); Serial.print("\t");
  Serial.print(digitalRead(sensors[1])); Serial.print("\t");
  Serial.print(digitalRead(sensors[2])); Serial.print("\t");
  Serial.print(digitalRead(sensors[3])); Serial.print("\t");
  Serial.print(digitalRead(sensors[4])); Serial.print("\t");
  Serial.print(analogRead(INFRA_PIN));   Serial.print("\t\n");
}

void motorA(int16_t _sp) {
  _sp = constrain(_sp, -MAX_SPEED, MAX_SPEED);

  if (_sp > 0) {
    digitalWrite(INA_1, HIGH);
    digitalWrite(INA_2, LOW);
  }
  else if (_sp < 0) {
    digitalWrite(INA_1, LOW);
    digitalWrite(INA_2, HIGH);
  }
  else {
    digitalWrite(INA_1, HIGH);
    digitalWrite(INA_2, HIGH);
    analogWrite(PWMA, 0);
  }
  analogWrite(PWMA, abs(_sp));
}

void motorB(int16_t _sp) {
  _sp = constrain(_sp, -MAX_SPEED, MAX_SPEED);

  if (_sp > 0) {
    digitalWrite(INB_1, HIGH);
    digitalWrite(INB_2, LOW);
  }
  else if (_sp < 0) {
    digitalWrite(INB_1, LOW);
    digitalWrite(INB_2, HIGH);
  }
  else {
    digitalWrite(INB_1, HIGH);
    digitalWrite(INB_2, HIGH);
    analogWrite(PWMB, 0);
  }
  analogWrite(PWMB, abs(_sp));
}

void Motor(int16_t _spA, int16_t _spB) {
  motorA(_spA); motorB(_spB);
}

void Arising() {
  count_a ++;
}

void Brising() {
  count_b ++;
}
