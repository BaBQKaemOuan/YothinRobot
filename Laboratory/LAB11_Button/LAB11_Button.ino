#define sw_green 12             // กำหนดพอร์ตสวิตซ์
#define sw_red   13

bool stateButtonRed = false;    // กำหนดตัวแปร
bool stateButtonGreen = false;
int state = 0;

void setup() {
  pinMode(sw_green, INPUT);     // กำหนดพอร์ตให้เป็น INPUT
  pinMode(sw_red, OUTPUT);      // กำหนดพอร์ตให้เป็น INPUT
}

void loop() {
  stateButtonRed = digitalRead(sw_red);      // อ่านค่าสถานะของสวิตซ์
  stateButtonGreen = digitalRead(sw_green);

  if (stateButtonRed == HIGH) {              // ถ้าสถานะสวิตซ์เป็น HIGH
    state = 1;                               // กำหนดตัวแปร state มีค่าเท่ากับ 1
  }
  else if (stateButtonGreen == HIGH) {       // ถ้าสถานะสวิตซ์เป็น HIGH
    state = 2;                               // กำหนดตัวแปร state มีค่าเท่ากับ 2       
  }
  Serial.println(state);
}
