/* #16
================================================================================================================= 
Channel M&E Automation:https://bit.ly/3uz3Bt8
Vui lòng đăng ký kênh https://bit.ly/34a2of1 cảm ơn các bạn rất nhiều!
Danh sách phát Arduino : https://bit.ly/34BUDlU
=================================================================================================================
*/
#include <Stepper.h>

const int stepsPerRevolution = 2048; // Số bước / 1 vòng quay đối với động cơ bước 28BYJ-48

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11); // Cài đặt động cơ bước và cấu hình chân cắm.
//Stepper myStepper1 = Stepper(stepsPerRevolution, 10, 8, 9, 11);

void setup() {
 
    myStepper.setSpeed(15); // Tốc độ quay khai báo 1-19 Ngoài phạm vi này motor không chạy
    //myStepper1.setSpeed(5);
}

void loop() 
{
  
  myStepper.step(stepsPerRevolution); 
  delay(1000);

  myStepper.step(-2*stepsPerRevolution); 
  //myStepper1.step(-0.5*stepsPerRevolution);
  delay(1000);

}
