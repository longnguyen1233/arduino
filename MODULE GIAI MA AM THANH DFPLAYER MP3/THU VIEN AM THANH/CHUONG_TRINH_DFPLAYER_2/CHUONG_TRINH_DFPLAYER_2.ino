#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(12, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
String text;
void setup() 
{                 
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);  
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  if (!myDFPlayer.begin(mySoftwareSerial)) 
  {  
    Serial.println(F("Không thể khởi động:"));
    Serial.println(F("1.Kiểm tra lại kết nối"));
    Serial.println(F("2.Lắp lại thẻ nhớ"));
      while(true)
      {
        delay(0);
      }
  }
  Serial.println(F("DFPlayer Mini đang hoạt động"));

  myDFPlayer.volume(30); 
  
}

void loop() 
{
 if(digitalRead(2) == LOW) 
 {while(digitalRead(2) == LOW);
  bai_hat_1();
 }
 if(digitalRead(3) == LOW) 
 {while(digitalRead(3) == LOW);
  bai_hat_2();
 }
if(Serial.available()) { 
    text = Serial.readStringUntil('\n'); 
      
        if(text == "n") {
            myDFPlayer.next();   
            Serial.println("Next");
        }
        
        else if(text == "p") {
            myDFPlayer.previous();
            Serial.println("Prev");
        }
        else if(text == "1") {
            myDFPlayer.play(1); 
            Serial.println("Start");
        }
        
        

        

    
   }



}

void nhac_mo_dau()
{
  myDFPlayer.play(1); 
}

void bai_hat_1()
{myDFPlayer.play(2);delay(100); 
  }

void bai_hat_2()
{myDFPlayer.play(3);delay(100); 
  }
























