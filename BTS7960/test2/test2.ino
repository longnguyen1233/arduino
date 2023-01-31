int LPWM = 9; //Dùng chân digital có xuất xung PWM
int RPWM = 10;

int bientro = A0; //Biến trở nối chân A0
int gtbientro;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(LPWM, OUTPUT);
  pinMode(RPWM, OUTPUT);

  pinMode(bientro, INPUT);
}

void loop() 
{
  gtbientro = analogRead(bientro); //đọc tín hiệu Analog từ biến trở 0-1023
  int giatripwm = map(gtbientro,0,1023,0,255); //Chuyển giá trị đọc được từ biến trở sang xung PWM

  Serial.print("GT biến trở: "); Serial.print(gtbientro);
  Serial.print("    GT PWM: "); Serial.println(giatripwm); Serial.println("   ");
  
  analogWrite(LPWM, giatripwm);
  analogWrite(RPWM, 0);
}
