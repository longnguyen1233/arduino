/*

CÁC HÀM THÔNG DỤNG KHI DÙNG I2C

lcd.init()  : Khởi tạo màn hình lcd
lcd.clear() : Xóa màn hình, đưa con trỏ về vị trí 0,0
lcd.home()  : Đưa con trỏ về vị trí 0
lcd.setCursor(x,y)  : Đưa con trỏ về vị trí cột thứ x, hàng thứ y
lcd.noDisplay() : Không hiển thị gì trên màn hình cả
lcd.display() : Hiển thị lên màn hình
lcd.noBlink() : Không nhấp nháy con trỏ
lcd.blink() : Nhấp nháy con trỏ
lcd.scrollDisplayLeft() : Cuộn màn hình bên trái
lcd.scrollDisplayRight()  : Cuộn màn hình bên phải
lcd.leftToRight() : Kí tự sẽ hiển thị từ phía bên trái sang phải
lcd.rightToLeft() : Kí tự sẽ hiển thị từ phía phải sang trái
lcd.noBacklight() : Tắt đèn nền
lcd.backlight() : Có đèn nền
lcd.write(x)  : Lcd sẽ in ra kí tự thứ x trong ô nhớ từ 0-7 của CGRAM
lcd.createChar(location,charmap[])  : Hiển thị một kí tự charmap[] bất kì
 

*/

#include <Wire.h> //Gọi thư viện I2C để sử dụng các thư viện I2C

#include <LiquidCrystal_I2C.h> //Thư viện LCD I2C
LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02
int a;
String message1 = String("               WELCOME TO DIEN TU TUYET NGA");
String message2 = String("               LH/Zalo: 0936832336-0708787899 OR WEBSITE: DIENTUTUYETNGA.COM");
int length;

byte muiten[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00000
};

byte loa[] = {
  B00001,
  B00011,
  B00111,
  B11111,
  B11111,
  B00111,
  B00011,
  B00001
};

byte tim[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte tick[] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B10110,
  B11100,
  B01000,
  B00000
};

byte nhietdo[] = {
  B11000,
  B11000,
  B00111,
  B01000,
  B01000,
  B01000,
  B00111,
  B00000
};

byte phantram[] = {
  B11000,
  B11001,
  B00010,
  B00100,
  B01000,
  B10011,
  B00011,
  B00000
};

byte notnhac[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01011,
  B11011,
  B11000,
  B00000
};

byte caichuong[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100
};
void setup() 
{
  lcd.init(); //Khởi tạo màn hình LCD
  lcd.backlight(); //Bật đèn màn hình lCD
  lcd.createChar(0, muiten);
  lcd.createChar(1, loa);
  lcd.createChar(2, tim);
  lcd.createChar(3, tick);
  lcd.createChar(4, nhietdo);
  lcd.createChar(5, phantram);
  lcd.createChar(6, notnhac);
  lcd.createChar(7, caichuong);
  length = message2.length();
}

void loop() 
{

  for(int i= 0; i<length; i++)
  {
    ClearRow(0);
    lcd.print(message1.substring(i,i+15));
    ClearRow(1);
    lcd.print(message2.substring(i,i+15));
    delay(600);
  }
  
  //chạy trái sang phải
//  for(int i= length; i>=0; i--)
//  {
//    ClearRow(0);
//    lcd.print(message1.substring(i,i+15));
//    delay(500);
//  }
//  for(int i=16; i>=3; i--)
//  {
//    lcd.clear(); 
//    lcd.setCursor(i, 0);
//    lcd.print("WELCOME TO"); 
//    delay(500); 
//  }
//

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
  lcd.write(byte(0));

  lcd.setCursor(2,0);
  lcd.write(byte(1));

  lcd.setCursor(4,0);
  lcd.write(byte(2)); 

  lcd.setCursor(6,0);
  lcd.write(byte(3)); 

  lcd.setCursor(8,0);
  lcd.write(byte(4)); 

  lcd.setCursor(10,0);
  lcd.write(byte(5)); 

  lcd.setCursor(12,0);
  lcd.write(byte(6)); 

  lcd.setCursor(14,0);
  lcd.write(byte(7));
  lcd.setCursor(1, 1);
  for(a=33; a<47; a++) 
    lcd.write(a);
  delay(5000);
}

void ClearRow(int rowNum)
{
  lcd.setCursor(0,rowNum);
  lcd.print("                    ");
  lcd.setCursor(0,rowNum);
}
