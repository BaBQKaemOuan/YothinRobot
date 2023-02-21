#define port_sen1 1   //กำหนดพอร์ต
#define port_sen2 2
#define port_sen3 3
#define port_sen4 4
#define port_sen5 5
bool sen1 = 0 , sen2 = 0, sen3 = 0, sen4 = 0, sen5 = 0;   //ประกาศตัวแปร

void setup() {
  pinMode(port_sen1, INPUT);
  pinMode(port_sen2, INPUT);
  pinMode(port_sen3, INPUT);
  pinMode(port_sen4, INPUT);
  pinMode(port_sen5, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  sen1 = digitalRead(port_sen1);
  sen2 = digitalRead(port_sen2);
  sen3 = digitalRead(port_sen3);
  sen4 = digitalRead(port_sen4);
  sen5 = digitalRead(port_sen5);
  
  Serial.print(sen1); Serial.print(",");
  Serial.print(sen2); Serial.print(",");
  Serial.print(sen3); Serial.print(",");
  Serial.print(sen4); Serial.print(",");
  Serial.print(sen5);
  Serial.println(",");
  delay(10);
}
