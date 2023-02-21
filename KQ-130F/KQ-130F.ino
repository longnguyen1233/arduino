#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
char data_in[100]; //bộ đệm nhận dữ liệu
int index = 0; // chỉ số cho bộ đệm
int den=4;
void setup()
{
  Serial.begin(9600);
  while (!Serial) {;}
 Serial.println("WELLCOME TO......!");
  // Cài đặt cổng nối tiếp chạy bằng phần mềm
  mySerial.begin(9600);
  pinMode(den,OUTPUT);
}
void loop() // run over and over
{
  if (mySerial.available())
  {
     char c = mySerial.read();
     if(c == 'O'){
        Serial.println("LED ON");
        digitalWrite(den, HIGH);
      }
      else if(c == 'F')
      {
        Serial.println("LED OFF");
        digitalWrite(den, LOW);
      }
        
    }
  if (Serial.available())
    mySerial.write(Serial.read());
}