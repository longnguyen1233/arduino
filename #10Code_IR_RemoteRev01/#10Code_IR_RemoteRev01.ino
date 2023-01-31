/*
================================================================================================================= 
Channel M&E Automation:https://bit.ly/3uz3Bt8
Vui lòng đăng ký kênh https://bit.ly/34a2of1 cảm ơn các bạn rất nhiều!
Danh sách phát Arduino : https://bit.ly/34BUDlU
//https://github.com/Arduino-IRremote/Arduino-IRremote
=================================================================================================================
*/
#include <IRremote.hpp>

const int Recv_Pin = 2;
int Ledpin[]={3,4,5,6};
 //           0,1,2,3
int i;
unsigned long lastTime = millis(); // Lưu thời gian cuối cùng khi nhận tín hiệu từ Remote

//===========================================================================================================

void setup() {
  
  Serial.begin(9600);
  
  for(i=0; i<4; i++)
     pinMode(Ledpin[i], OUTPUT);

  for(i=0; i<4; i++)
    digitalWrite(Ledpin[i], LOW);
  
  //Khởi động bộ thu, Khi nhận tín hiệu Led chân 8 nhấp nháy
  IrReceiver.begin(Recv_Pin, true, 8); // True cho phép led nối với chân 8 nhấp nháy
}
//===========================================================================================================
//uint32_t Là kiểu dữ liệu số 32 bit, giá trị không dấu từ 0 đến FFFFFFFF

void loop() {
  if (IrReceiver.decode()) // Kiểm tra liên tục tín hiệu nhận từ Remote
  {
    
    uint32_t dataRemote = IrReceiver.decodedIRData.decodedRawData; // Lưu dữ liệu nhận được vào biến dataRemote 
    
    if(dataRemote>0) // Kiểm tra dữ liệu hợp lệ phải >0
    {
      Serial.println(dataRemote);
      
     if (millis() - lastTime > 250) // Do tắt mở cùng 1 nút bấm nên phải có thời gian nghĩ giữa 2 lần bấn
      {
        switch(dataRemote)
        {
            
          case 4077715200: // Bấm phiếm số 1, điều khiển Led 1 sáng tắt
            digitalWrite(Ledpin[0], !digitalRead(Ledpin[0]));
          break;
          
          case 11208015: // Bấm phiếm số 2, điều khiển Led 2 sáng tắt
            digitalWrite(Ledpin[1], !digitalRead(Ledpin[1]));
            break;

          case 2707357440: // Bấm phiếm số 3, điều khiển Led 3 sáng tắt
            digitalWrite(Ledpin[2], !digitalRead(Ledpin[2]));
          break;
          
          case 4144561920: // Bấm phiếm số 4, điều khiển Led 4 sáng tắt
            digitalWrite(Ledpin[3], !digitalRead(Ledpin[3]));    
          break;
          
          case 3125149440: // Bấm phiếm CH-, tất cả các đèn đều tắt
            for(i=0; i<4; i++)
              digitalWrite(Ledpin[i], LOW); 
          break;
          
          case 3091726080: // Bấm Phiếm số CH+, tất cả các đèn đều sáng
            for(i=0; i<4; i++)
               digitalWrite(Ledpin[i], HIGH);
          break;
        }
      }
    }
    lastTime = millis();//Reset biến lastTime
    IrReceiver.resume(); // Cho phép nhận giá trị tiếp theo
  }
}
