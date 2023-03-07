#define Motor1_A 4    //กำหนดพอร์ต
#define Motor1_B 5
#define Motor1_PWM 6

void setup() {
  pinMode(Motor1_A, OUTPUT);    //กำหนดให้เป็น Output
  pinMode(Motor1_B, OUTPUT);
  pinMode(Motor1_PWM, OUTPUT);
}

void loop() {
  digitalWrite(Motor1_A, LOW); //สั่งพอร์ต digital ให้เป็น HIGH
  digitalWrite(Motor1_B, HIGH);  //สั่งพอร์ต digital ให้เป็น LOW
  analogWrite(Motor1_PWM, 100); //สั่งพอร์ต PWM
}
