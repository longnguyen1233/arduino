int LPWM = 9; //Dùng chân digital có xuất xung PWM
int RPWM = 10;

int bientro = A0; //Điện trở chân A0
int gtbientro;

int congtac = 7; //Công tắc chân số 7
int gtcongtac;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(LPWM, OUTPUT);
  pinMode(RPWM, OUTPUT);

  pinMode(bientro, INPUT);

  pinMode(congtac, INPUT_PULLUP); //dùng điện trở trong arduino thay điện trở ngoài
}

void loop() 
{
  gtcongtac = digitalRead(congtac); //Đọc giá trị công tắc 0/1
  
  gtbientro = analogRead(bientro); //đọc tín hiệu Analog từ biến trở 0-1023
  int giatripwm = map(gtbientro,0,1023,0,255);

  Serial.print("GT biến trở: "); Serial.print(gtbientro);
  Serial.print("    GT PWM: "); Serial.println(giatripwm);
  Serial.print("GT công tắc: "); Serial.print(gtcongtac); 
  
  if(gtcongtac == 0) // 0 - Quay nghịch chiều kim đồng hồ
  {
     Serial.println("   Quay nghịch"); Serial.println("   ");
     analogWrite(LPWM, 0);
     analogWrite(RPWM, giatripwm);
  }
  else  // 1 - Quay thuận chiều kim đồng hồ
  {
     Serial.println("   Quay thuận"); Serial.println("   ");
     analogWrite(LPWM, giatripwm);
     analogWrite(RPWM, 0);
  }
  
  //delay(500);

}
