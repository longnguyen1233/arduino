int LPWM = 9; //Dùng chân digital có xuất xung PWM
int RPWM = 10;
int ena=8;
void setup() 
{
  pinMode(LPWM, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(ena, OUTPUT);
  digitalWrite(ena,HIGH);
}

void loop() 
{
  analogWrite(LPWM, 255); //Xuất xung PWM lên chân LPWM 0-255
  analogWrite(RPWM, 0); //Xuất xung PWM lên chân RPWM
}
