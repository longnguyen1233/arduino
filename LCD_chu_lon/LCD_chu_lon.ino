#include <Wire.h> //Gọi thư viện I2C để sử dụng các thư viện I2C

#include <LiquidCrystal_I2C.h> //Thư viện LCD I2C
LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02
String message1 = String("DIEN TU TUYET NGA");
String message2 = String("DIENTUTUYETNGA.COM");
int phantram=0, a=16, dai1;
byte tim[] = {  B00000,  B01010,  B11111,  B11111,  B01110,  B00100,  B00000,  B00000};
byte kt1[] = {  B00111,  B01111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111};
byte kt2[] = {  B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000};
byte kt3[] = {  B11100,  B11110,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111};
byte kt4[] = {  B00000,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111,  B11111};
byte kt5[] = {  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01111,  B00111};
byte kt6[] = {  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11110,  B11100};
byte kt7[] = {  B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B11111,  B11111};
byte kt8[] = {  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111};
byte muiten[] = {  B00000,  B00100,  B01110,  B11111,  B00100,  B00100,  B00100,  B00000};
byte loa[] = {  B00001,  B00011,  B00111,  B11111,  B11111,  B00111,  B00011,  B00001};
byte tick[] = {  B00000,  B00000,  B00001,  B00011,  B10110,  B11100,  B01000,  B00000};
byte nhietdo[] = {  B11000,  B11000,  B00111,  B01000,  B01000,  B01000,  B00111,  B00000};
byte phamtram[] = {  B11000,  B11001,  B00010,  B00100,  B01000,  B10011,  B00011,  B00000};
byte notnhac[] = {  B00001,  B00011,  B00101,  B01001,  B01011,  B11011,  B11000,  B00000};
byte caichuong[] = {  B00100,  B01110,  B01110,  B01110,  B01110,  B11111,  B00000,  B00100};
byte tim_trai[] = {  B00110,  B01111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00001};
byte tim_phai[] = {  B01100,  B11110,  B11111,  B11111,  B11110,  B11100,  B11000,  B10000};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(); //Khởi tạo màn hình LCD
  lcd.backlight(); //Bật đèn màn hình lCD 
  dai1=message2.length();
}


void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  kt(1);
  so3(7);
  delay(1000);
  so2(7);
  delay(1000);
  lcd.clear();
  so1(7);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LOADING");
  lcd.setCursor(8,1);
  lcd.print(phantram);
  lcd.setCursor(9,1);
  lcd.print("%");
  delay(500);
  for(int i=0; i <= 9; i++)
  {
    
    if(phantram<90)
          phantram+=10;    
    else
          phantram=99;
    lcd.setCursor(7,1); 
    lcd.print(phantram);    
    lcd.print("%");
    lcd.setCursor(i+7,0);
    lcd.print(".");
    
    delay(1000);
  }
  phantram=0;
  for(int i=17; i>=0; i--)
  {
    if(i>3)
    {
      lcd.clear();
      lcd.setCursor(a,0); //hàng 1
      lcd.print("WELCOME TO");
      a--;
    }
    
    ClearRow(1);
    lcd.print(message1.substring(i,i+16));
    delay(500);
  }
  a=16;
  delay(1000);
  lcd.clear();
  kt(2);
  lcd.setCursor(3,0);
  lcd.write(6);
  lcd.setCursor(11,0);
  lcd.write(6);
  lcd.setCursor(2,1);
  lcd.write(6);
  lcd.setCursor(12,1);
  lcd.write(6);
  lcd.setCursor(4,0); //hàng 1
  lcd.print("DIEN TU");
  lcd.setCursor(3,1); //hàng 1
  lcd.print("TUYET NGA");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0); //hàng 1
  lcd.print("SDT/ZALO:");
  lcd.setCursor(3,1); //hàng 1
  lcd.print("0936832336");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0); //hàng 1
  lcd.print("WEBSITE:");
  ClearRow(1);
  lcd.print(message2.substring(0,16));
  delay(2000);
  for(int i=0; i<=dai1; i++)
  {
    ClearRow(1);
    lcd.print(message2.substring(i,i+16));
    delay(500);
  }
  for(int i=0; i<5; i++)
  {
    lcd.clear();
    delay(200);
    lcd.setCursor(4, 0);
    lcd.print("SPECIAL"); 
    lcd.setCursor(3, 1);
    lcd.print("CHARACTERS");
    delay(200);    
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(0);
  lcd.setCursor(2,0);
  lcd.write(1);
  lcd.setCursor(4,0);
  lcd.write(2); 
  lcd.setCursor(6,0);
  lcd.write(3); 
  lcd.setCursor(8,0);
  lcd.write(4); 
  lcd.setCursor(10,0);
  lcd.write(5); 
  lcd.setCursor(12,0);
  lcd.write(6); 
  lcd.setCursor(14,0);
  lcd.write(7);
  lcd.setCursor(1, 1);
  for(a=33; a<47; a++) 
    lcd.write(a);
  delay(2000);
  lcd.clear();
  kt(3);
  lcd.setCursor(5,0);
  lcd.print("I"); 
  tim_lon(7); 
  lcd.setCursor(10,0);
  lcd.print("U"); 
  lcd.setCursor(1,1);
  lcd.print("SEE YOU AGAIN!");
  delay(2000);
  lcd.clear();

  lcd.setCursor(3,0);
  lcd.print("THANK YOU");
  lcd.setCursor(2,1);
  lcd.print("FOR WATCHING");
  delay(1000);
}
void kt(int goi)
{
  if(goi==1)
  {
    lcd.createChar(0, kt1);
    lcd.createChar(1, kt2);
    lcd.createChar(2, kt3);
    lcd.createChar(3, kt4);
    lcd.createChar(4, kt5);
    lcd.createChar(5, kt6);
    lcd.createChar(6, kt7);
    lcd.createChar(7, kt8);
  }
  else if(goi==2)
  {
    lcd.createChar(0, muiten);
    lcd.createChar(1, loa);
    lcd.createChar(2, tick);
    lcd.createChar(3, nhietdo);
    lcd.createChar(4, phamtram);
    lcd.createChar(5, notnhac);
    lcd.createChar(6, tim);
    lcd.createChar(7, caichuong);
  }
  else if(goi==3)
  {
    lcd.createChar(0, tim_trai);
    lcd.createChar(1, tim_phai);
    
  }
}
void ClearRow(int rowNum)
{
  lcd.setCursor(0,rowNum);
  lcd.print("                    ");
  lcd.setCursor(0,rowNum);
}
void so3(int so)
{
  lcd.setCursor(so,0); //hàng 1
  lcd.write(6); 
  
  lcd.setCursor(so+1,0);
  lcd.write(6); 

  lcd.setCursor(so+2,0);
  lcd.write(2); 

  lcd.setCursor(so,1);//hàng 2
  lcd.write(3);
  
  lcd.setCursor(so+1,1);
  lcd.write(3); 

  lcd.setCursor(so+2,1);
  lcd.write(5);
}

void so2(int so)
{
  lcd.setCursor(so,0); //hàng 1
  lcd.write(6); 
  
  lcd.setCursor(so+1,0);
  lcd.write(6); 

  lcd.setCursor(so+2,0);
  lcd.write(2); 

  lcd.setCursor(so,1);//hàng 2
  lcd.write(4);
  
  lcd.setCursor(so+1,1);
  lcd.write(3); 

  lcd.setCursor(so+2,1);
  lcd.write(3);
}

void so1(int so)
{  
  lcd.setCursor(so,0); //hàng 1
  lcd.write(1); 
  
  lcd.setCursor(so+1,0);
  lcd.write(2); 

  
  lcd.setCursor(so,1);//hàng 2
  lcd.write(3);
  
  lcd.setCursor(so+1,1);
  lcd.write(7); 

  lcd.setCursor(so+2,1);
  lcd.write(3);
}
void tim_lon(int so)
{  
  lcd.setCursor(so,0); //hàng 1
  lcd.write(0); 
  
  lcd.setCursor(so+1,0);
  lcd.write(1);   
}
