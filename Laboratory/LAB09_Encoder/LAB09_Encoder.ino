int x = 0;  // กำหนดตัวแปร x ให้มีค่าเท่ากับ 0

void setup() {
  pinMode(2, INPUT);  // กำหนดให้พอร์ต 2 เป็น Input
}

void loop() {
  while(x < 20) { //เช็คตัวแปร x 
    while(digitalRead(2) == HIGH);  // รอจนกว่าพร์ต 2 จะมีสถานะเป็น HIGH
    while(digitalRead(2) == LOW);   // รอจนกว่าพร์ต 2 จะมีสถานะเป็น LOW
    x++;                            // บวกค่าตัวแปร x ทีละ 1

    Serial.println(x);              // แสดงค่าตัวแปร x
  }
}
