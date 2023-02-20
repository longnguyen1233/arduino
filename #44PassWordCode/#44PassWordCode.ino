/*---------------------------------------------------------------------------------------------------------
                           Mật khẩu mở cửa-PassWord
------------------------------------------------------------------------------------------------------------
*Channel M&E Automation:https://bit.ly/3uz3Bt8
*Vui lòng đăng ký kênh https://bit.ly/34a2of1 cảm ơn các bạn rất nhiều!
*Danh sách phát Arduino : https://bit.ly/34BUDlU
-------------------------------------------------------------------------------------------------------------*/
#include <PC_SIMU.h>
PC_SIMU PLC;

char Code[6] = {" "};
char Key[6]={"12345"};
int Counter = 0;
int Key_Time = 0;
bool PUL_1 = 0;
bool PUL_1_ANT = 0;
bool PUL_2 = 0;
bool PUL_2_ANT = 0;
bool PUL_3 = 0;
bool PUL_3_ANT = 0;
bool PUL_4 = 0;
bool PUL_4_ANT = 0;
bool PUL_5 = 0;
bool PUL_5_ANT = 0;
bool Close_Door = 0;
bool End = 0;
bool Start = 0;

void setup() {
  pinMode(2, INPUT);   // I0.2 : Button 1
  pinMode(3, INPUT);   // I0.3 : Button 2
  pinMode(4, INPUT);   // I0.4 : Button 3
  pinMode(5, INPUT);   // I0.5 : Button 4
  pinMode(6, INPUT);   // I0.6 : Button 5
  pinMode(7, INPUT);   // I0.7 : Lsw gate closed
  pinMode(8, INPUT);   // I1.0 : Lsw gate open
  pinMode(9, OUTPUT);  // Q1.1 : Open gate.
  pinMode(10, OUTPUT); // Q0.2  : Close the gate.
  pinMode(11, OUTPUT); // Q1.3 : Green LED
  pinMode(12, OUTPUT); // Q1.4 : Red LED
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  PLC.INI();
  Counter = 0;
}
void loop() 
{
  PUL_1 = digitalRead(2);
  if(PUL_1 == 1 && PUL_1_ANT == 0)
  {
    Read_Code();
  }
  PUL_1_ANT = PUL_1;
  PUL_2 = digitalRead(3);
  if(PUL_2 == 1 && PUL_2_ANT == 0)
  {
    Read_Code();
  }
  PUL_2_ANT = PUL_2;
  PUL_3 = digitalRead(4);
  if(PUL_3 == 1 && PUL_3_ANT == 0)
  {
    Read_Code();
  }
  PUL_3_ANT = PUL_3;
  PUL_4 = digitalRead(5);
  if(PUL_4 == 1 && PUL_4_ANT == 0)
  {
    Read_Code();
  }
  PUL_4_ANT = PUL_4;
  PUL_5 = digitalRead(6);
  if(PUL_5 == 1 && PUL_5_ANT == 0)
  {
    Read_Code();
  }
  PUL_5_ANT = PUL_5;
  if(Counter >= 5)
  {
    if(Code[0] == Key[0] && Code[1] == Key[1] && Code[2] == Key[2] && Code[3] == Key[3] && Code[4] == Key[4])
    {
      // Valid Key
      if(End == 0) Door();
      else Reset();
    }
    else Not_Valid();
  }
  else
  {
    if(Start == 1)
    {
      Key_Time++;
      if(Key_Time >= 15000) Not_Valid();
    }
  }
}
void Read_Code(){
  if(Counter == 0)
  {
   if(digitalRead(2) == 1)Code[0] = '1';
   if(digitalRead(3) == 1)Code[0] = '2';
   if(digitalRead(4) == 1)Code[0] = '3';
   if(digitalRead(5) == 1)Code[0] = '4';
   if(digitalRead(6) == 1)Code[0] = '5';
  }
  if(Counter == 1)
  {
   if(digitalRead(2) == 1)Code[1] = '1';
   if(digitalRead(3) == 1)Code[1] = '2';
   if(digitalRead(4) == 1)Code[1] = '3';
   if(digitalRead(5) == 1)Code[1] = '4';
   if(digitalRead(6) == 1)Code[1] = '5';
  }
  if(Counter == 2)
  {
   if(digitalRead(2) == 1)Code[2] = '1';
   if(digitalRead(3) == 1)Code[2] = '2';
   if(digitalRead(4) == 1)Code[2] = '3';
   if(digitalRead(5) == 1)Code[2] = '4';
   if(digitalRead(6) == 1)Code[2] = '5';
  }
  if(Counter == 3)
  {
   if(digitalRead(2) == 1)Code[3] = '1';
   if(digitalRead(3) == 1)Code[3] = '2';
   if(digitalRead(4) == 1)Code[3] = '3';
   if(digitalRead(5) == 1)Code[3] = '4';
   if(digitalRead(6) == 1)Code[3] = '5';
  }
  if(Counter == 4)
  {
   if(digitalRead(2) == 1)Code[4] = '1';
   if(digitalRead(3) == 1)Code[4] = '2';
   if(digitalRead(4) == 1)Code[4] = '3';
   if(digitalRead(5) == 1)Code[4] = '4';
   if(digitalRead(6) == 1)Code[4] = '5';
  }
  Start = 1;
  Counter++;
}
void Door()
{
  // Open the Door
  if(digitalRead(8) == 0 && Close_Door == 0)
  {
    digitalWrite(9, 1);
    digitalWrite(11, 1);
  }
  else
  {
    digitalWrite(9, 0);
    delay(2000);
    // close Door
    digitalWrite(11,0);
    digitalWrite(10, 1);
    digitalWrite(12,1);
    Close_Door = 1;
  }
  if(digitalRead(7) == 1 && Close_Door == 1)
  {
    digitalWrite(10, 0);
    digitalWrite(12,0);
    Close_Door = 0;
    End = 1;
  }
}

void Not_Valid(){
      digitalWrite(12, 1);
      delay(800);
      digitalWrite(12, 0);
      delay(800);
      digitalWrite(12, 1);
      delay(800);
      digitalWrite(12, 0);
      Reset();
}
void Reset()
{
  Code[0] = ' ';
  Code[1] = ' ';
  Code[2] = ' ';
  Code[3] = ' ';
  Code[4] = ' ';
  Key_Time = 0;
  Counter = 0;
  Start = 0;
  End = 0;
}
