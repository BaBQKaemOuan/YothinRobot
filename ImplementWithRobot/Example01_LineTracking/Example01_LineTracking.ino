#define Motor1_A 4
#define Motor1_B 5
#define Motor1_PWM 6

#define Motor2_A 7
#define Motor2_B 8
#define Motor2_PWM 9

#define port_sen1 1
#define port_sen2 2
#define port_sen3 3
#define port_sen4 4
#define port_sen5 5
bool sen1 = 0 , sen2 = 0, sen3 = 0, sen4 = 0, sen5 = 0;

void setup() {
  pinMode(port_sen1, INPUT);
  pinMode(port_sen2, INPUT);
  pinMode(port_sen3, INPUT);
  pinMode(port_sen4, INPUT);
  pinMode(port_sen5, INPUT);

  pinMode(Motor1_A, OUTPUT);
  pinMode(Motor1_B, OUTPUT);
  pinMode(Motor1_PWM, OUTPUT);

  pinMode(Motor2_A, OUTPUT);
  pinMode(Motor2_B, OUTPUT);
  pinMode(Motor2_PWM, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void track_line(int sp)
{
  while (true)
  {
    readSensorIR();
    if (sen1 == HIGH && sen2 == HIGH && sen3 == HIGH && sen4 == HIGH && sen5 == HIGH)
    {
      motor_L(0);
      motor_R(0);
      break;
    }
    else if (sen1 == HIGH && sen2 == HIGH && sen3 == LOW && sen4 == HIGH && sen5 == HIGH)
    {
      motor_L(255);
      motor_R(255);
    }
    else if (sen1 == HIGH && sen2 == LOW && sen3 == LOW && sen4 == HIGH && sen5 == HIGH)
    {
      motor_L(100);
      motor_R(-100);
    }
    else if (sen1 == LOW && sen2 == LOW && sen3 == HIGH && sen4 == HIGH && sen5 == HIGH)
    {
      motor_L(100);
      motor_R(-150);
    }
    else if (sen1 == LOW && sen2 == HIGH && sen3 == HIGH && sen4 == HIGH && sen5 == HIGH)
    {
      motor_L(100);
      motor_R(-200);
    }
    else if (sen1 == HIGH && sen2 == HIGH && sen3 == LOW && sen4 == LOW && sen5 == HIGH)
    {
      motor_L(-100);
      motor_R(100);
    }
    else if (sen1 == HIGH && sen2 == HIGH && sen3 == HIGH && sen4 == LOW && sen5 == LOW)
    {
      motor_L(-150);
      motor_R(100);
    }
    else if (sen1 == HIGH && sen2 == HIGH && sen3 == HIGH && sen4 == HIGH && sen5 == LOW)
    {
      motor_L(-200);
      motor_R(100);
    }
  }
}

void motor_L(int sp) {
  if (sp > 0)
  {
    digitalWrite(Motor1_A, HIGH);
    digitalWrite(Motor1_B, LOW);
  }
  else if (sp < 0)
  {
    digitalWrite(Motor1_A, LOW);
    digitalWrite(Motor1_B, HIGH);
  }
  else
  {
    digitalWrite(Motor1_A, LOW);
    digitalWrite(Motor1_B, LOW);
  }
  analogWrite(Motor1_PWM, abs(sp));
}

void motor_R(int sp)
{
  if (sp > 0)
  {
    digitalWrite(Motor2_A, HIGH);
    digitalWrite(Motor2_B, LOW);
  }
  else if (sp < 0)
  {
    digitalWrite(Motor2_A, LOW);
    digitalWrite(Motor2_B, HIGH);
  }
  else
  {
    digitalWrite(Motor2_A, LOW);
    digitalWrite(Motor2_B, LOW);
  }
  analogWrite(Motor2_PWM, abs(sp));
}

void readSensorIR()
{
  sen1 = digitalRead(port_sen1);
  sen2 = digitalRead(port_sen2);
  sen3 = digitalRead(port_sen3);
  sen4 = digitalRead(port_sen4);
  sen5 = digitalRead(port_sen5);
}
