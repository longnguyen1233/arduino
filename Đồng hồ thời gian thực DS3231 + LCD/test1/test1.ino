
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //I2C của LCD là 0x27, LCD 16x02
#include <DS3231.h>

DS3231  rtc(SDA, SCL);

void setup()
{
  Serial.begin(115200);   
  Wire.begin();//Khởi tạo I2C
  
  lcd.backlight();  //Mở đèn LCD
  lcd.begin();  //Khởi động LCD
  lcd.setCursor(0,0);
  lcd.print("Time:");
  lcd.setCursor(0,1);
  lcd.print("Date:");
  
  // Tạo rtc
  rtc.begin();
  
  rtc.setDOW(SATURDAY);     // Cài đặt thứ trong tuần
  rtc.setTime(18, 30, 00);     // Cài đặt giờ, phút, giây (24)
  rtc.setDate(16, 2, 2023);   // Ngày, tháng, năm
}

void loop()
{
  // Thứ
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Ngày, tháng, năm
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  lcd.setCursor(6,1);
  lcd.print(rtc.getDateStr()); 

  // giờ, phút, giây
  Serial.println(rtc.getTimeStr());
  lcd.setCursor(6,0);
  lcd.print(rtc.getTimeStr()); 
  delay (1000);
}
