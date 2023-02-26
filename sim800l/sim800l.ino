#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // CHÂN TX NỐI VỚI CHÂN 3, CHÂN RX NỐI VỚI CHÂN 2

#define  GOI  4//CHÂN TÁC ĐÔNG ĐỂ GỌI ĐIÊN
int trang_thai;
void setup()
{
  pinMode(GOI,INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
    }
 
void loop()
{ 
  trang_thai= digitalRead(GOI);
  Serial.print("trang thai:");
  Serial.println(trang_thai);
  delay(1000);
  if (digitalRead(GOI) == LOW)
  {
    delay(20);
     if (digitalRead(GOI) == LOW){
      goidien();
     }
  }
}
void goidien()
{
  mySerial.println("ATD+84377107817;"); // GỌI ĐẾN SỐ
  Serial.println("dang goi");
  Serial.println(trang_thai);
  delay(15000);            // CHỜ 15S
  mySerial.println();
}