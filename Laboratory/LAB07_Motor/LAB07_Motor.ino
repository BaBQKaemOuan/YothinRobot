#define Motor1_A 8     //กำหนดพอร์ต
#define Motor1_B 7
#define Motor1_PWM 9

void setup() {
  pinMode(Motor1_A, OUTPUT);    //กำหนดให้เป็น Output
  pinMode(Motor1_B, OUTPUT);
  pinMode(Motor1_PWM, OUTPUT);
}

void loop() {
  motorLeft(200); // เรียกใช้ฟังก์ชั่น
}

void motorLeft(int Speed) {         //speed ตั้งแต่ 0-255
  digitalWrite(Motor1_A, HIGH);     //สั่งพอร์ต digital ให้เป็น HIGH
  digitalWrite(Motor1_B, LOW);      //สั่งพอร์ต digital ให้เป็น LOW
  analogWrite(Motor1_PWM, Speed);   //สั่งพอร์ต PWM
}
