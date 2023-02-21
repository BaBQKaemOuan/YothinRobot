int x;  // ประกาศตัวแปร x
const int Fan = 19;

void setup() {
  Serial.begin(9600);    // เปิดการสื่อสาร
  pinMode(Fan, OUTPUT);  // ตั้ง Fan pin เป็น OUTPUT
}

void loop() {
  x = Serial.read();     // อ่านค่าและเก็บค่าที่อ่านมาไว้ใน x

  switch (x) {
    case 'a' : digitalWrite(Fan, HIGH); break;        // เมื่อกด A มอเตอร์จะหมุน
    case 'b' : digitalWrite(Fan, LOW);  break;        // มอเตอร์ดับ
    case 'c' : digitalWrite(Fan, HIGH); delay(1000);  // มอเตอร์จะวิ่ง 1 วินาทีแล้วดับ
               digitalWrite(Fan, LOW);  delay(1000);
               digitalWrite(Fan, HIGH); delay(1000);
               digitalWrite(Fan, LOW);  delay(1000);
  }
}
