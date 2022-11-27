#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(12, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void setup() 
{                 
  pinMode(2,INPUT);
  pinMode(3,INPUT);  
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {  while(true){delay(0); }   }
  myDFPlayer.volume(30); 
  nhac_mo_dau();
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




}

void nhac_mo_dau()
{
myDFPlayer.play(1);delay(4000); 
}

void bai_hat_1()
{myDFPlayer.play(2);delay(100); 
  }

void bai_hat_2()
{myDFPlayer.play(3);delay(100); 
  }
























