int LPWM = 9; //Dùng chân digital có xuất xung PWM
int RPWM = 10;

void setup() 
{
  pinMode(LPWM, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(ena, OUTPUT);
}

void loop() 
{
  analogWrite(LPWM, 255); //Xuất xung PWM lên chân LPWM 0-255
  analogWrite(RPWM, 0); //Xuất xung PWM lên chân RPWM
}
