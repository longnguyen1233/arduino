
// *** A4988 ***
//  MS1   MS2   MS3   Microstep resolution
//  Low   Low   Low       Full step
//  High  Low   Low       1/2 step
//  Low   High  Low       1/4 step
//  High  High  Low       1/8 step
//  High  High  High      1/16 step
//.....................................
//  *** 8825 ***
//  Low   Low   Low       Full step
//  High  Low   Low       Half step
//  Low   High  Low       1/4 step
//  High  High  Low       1/8 step
//  Low   Low   High      1/16 step
//  High  Low   High      1/32 step
//  Low   High  High      1/32 step
//  High  High  High      1/32 step

int tep = 5;
int dir = 4;
int ena = 6;

void setup() 
{
  Serial.begin(9600);
  pinMode(ena,OUTPUT); // Enable pin dùng để khởi động motor
  pinMode(tep,OUTPUT); // Step chân xung
  pinMode(dir,OUTPUT); // Dir xác định chiều quay
  
  digitalWrite(ena,LOW); // Set Enable LOW - khởi động motor
}

void loop() 
{
  /*
   * 1 xung = 1/16 của 1.8' = 0.1125'  ~~ 1 xung = 1/32 của 1.8' = 0.05625'
   * 
   * 5 xung = 5 bước 5 x 0.1125' = 0.5625'
   * 500 xung = 500 x 0.1125' = 56.25'
   * 1 vòng 360' = 360/0.1125' = 3200 bước(xung) ở 1/16 | 1/32 = 6400 bước
   * ở Full step: 1 vòng 360' = 200 bước(xung)
   */
  digitalWrite(dir,LOW); //Chân dir dùng để xác định chiều quay (hoặc thay đổi dây của motor)
  for(int x = 0; x < 6400; x++) //Quay 1 vòng
  {
    digitalWrite(tep,HIGH); // Cạnh lên
    delayMicroseconds(8); //Thời gian xuất xung = tốc độ quay
    digitalWrite(tep,LOW); // Cạnh xuống
    delayMicroseconds(8);
  }
  delay(1000);

  digitalWrite(dir,HIGH);
  for(int x = 0; x < 6400; x++) //Quay 2 vòng
  {
    digitalWrite(tep,HIGH); // Cạnh lên
    delayMicroseconds(1000); //Thời gian xuất xung = tốc độ quay
    digitalWrite(tep,LOW); // Cạnh xuống
    delayMicroseconds(1000);
  }
  delay(1000);  
}
