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
   * 1 xung = 1 bước 1.8'
   * 5 xung = 5 bước 1.8'x5 = 9'
   * 1 vòng 360' = 360/1.8 = 200 bước
   */
  digitalWrite(dir,HIGH); //Chân dir dùng để xác định chiều quay (hoặc thay đổi dây của motor)
  
  for(int x = 0; x < 400; x++)
  {
    digitalWrite(tep,HIGH); // Cạnh lên
    delayMicroseconds(1000); //Thời gian xuất xung = tốc độ quay | 400
    digitalWrite(tep,LOW); // Cạnh xuống
    delayMicroseconds(1000);
  }
  delay(1000);
  
}
