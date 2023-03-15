String text;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // lúc đầu ta để LED tắt
}
void loop()
{
  if(Serial.available()) { // nếu có dữ liệu gửi đến
    text = Serial.readStringUntil('\n'); // đọc giá trị gửi đến cho đến khi gặp kí tự xuống dòng \n
    
    if(text == "on") {
        digitalWrite(LED_BUILTIN,HIGH); // bật LED
        Serial.println("LED is turned ON");  // gửi lại thông báo lên Serial Monitor
    }
    
    if(text == "off") {
        digitalWrite(LED_BUILTIN,LOW); // tắt LED
        Serial.println("LED is turned OFF");
    }
   }
 }
