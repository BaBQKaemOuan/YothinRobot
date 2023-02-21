#define relay_pin 19  // กำหนดพอร์ตรีเลย์

void setup() {
  pinMode(relay_pin, OUTPUT); // กำหนดพอร์ตรีเลย์เป็น OUTPUT
}

void loop() {
  digitalWrite(relay_pin, HIGH);  // สั่งให้พอร์ตรีเลย์ มีสถานะเป็น HIGH
  delay(1000);                    // หน่วงเวลา 1 วินาที
  digitalWrite(relay_pin, LOW);   // สั่งให้พอร์ตรีเลย์ มีสถานะเป็น LOW
  delay(1000);                    // หน่วงเวลา 1 วินาที
}
