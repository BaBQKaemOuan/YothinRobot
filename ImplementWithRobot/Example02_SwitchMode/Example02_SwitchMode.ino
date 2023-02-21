#define sw_green 12            // กำหนดพอร์ตสวิตซ์
#define sw_red   13

bool stateButtonRed = false;   // กำหนดตัวแปร
bool stateButtonGreen = false;
int  state = 0;

void setup() {
  pinMode(sw_green, INPUT);    // กำหนดพอร์ตสวิตซ์ให้เป็น Input
  pinMode(sw_red, INPUT);

  selectMode();
}

void loop() {
  if(state == 1) {
    Serial.println("Auto!");
  }
  else if(state == 2) {
    Serial.println("Manual!");
  }
}

void selectMode() {
  while(true) {
    stateButtonRed = digitalRead(sw_red);                         // อ่านสถานะของสวิตซ์
    stateButtonGreen = digitalRead(sw_green);
    
    if (stateButtonRed == HIGH) {                                 // ถ้าสถานะสวิตซ์เป็น HIGH
      state = 1;                                                  // กำหนดตัวแปร State มีค่าเท่ากับ 1
    }
    else if(stateButtonGreen == HIGH) {                           // ถ้าสถานะสวิตซ์เป็น HIGH
      state = 2;                                                  // กำหนดตัวแปร State มีค่าเท่ากับ 2
    }
    else if(stateButtonGreen == HIGH && stateButtonRed == HIGH) { // ถ้าสวิตซ์ถูกกดพร้อมกัน
      break;                                                      // ออกจาก Loop while
    }
    Serial.println(state);
  }
}
