String RxBuff = "";                                    // Khai bao bo dem nhan du lieu
int Index_Rxdata = -1;                           // vi tri cua chuoi nhan duoc
const String myphone = "0919691943";
//const int PWR_KEY = 4;
const int status_led = 13;
void Gsm_Init();                      // Cau hinh Module Sim800C
void Gsm_MakeCall(String phone);      // Ham goi dien
void Gsm_MakeSMS(String phone,String content);     // Ham nhan tin
void tinhieu_cambien();

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  
  pinMode(status_led, OUTPUT);  //Khai bao ngo ra chan dieu khien relay
  digitalWrite(status_led, LOW);   //Khoi tao trang thai ngo ra ban dau
  pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  //pinMode(6, OUTPUT);
  digitalWrite(4, HIGH);
  //digitalWrite(5, HIGH);
  //digitalWrite(6, HIGH);

  //pinMode(2, INPUT_PULLUP);      //D4 is output, connect LED on board
  //attachInterrupt(0, tinhieu_cambien, FALLING); 
  
  GSM_Init();
  //GSM_MakeCall(myphone);
  //GSM_MakeSMS(myphone,"I'm a test");
  
}
void loop() { 
  delay(1000);
  if(Serial.available()){            //Khi co tin nhan gui den module sim thi tien hanh doc va dieu khien
    serialEvent_GSM();           
  }
}
void tinhieu_cambien(){
  GSM_MakeCall(myphone);
  bool statusLed = !digitalRead(status_led);
  digitalWrite(status_led,statusLed);
}
//----Ham phuc vu ngat khi nhan tin nhan SMS ve SIM800L------
void serialEvent_GSM(){
  while(Serial.available()){                          //Doi den khi co du lieu nhan ve
    char inChar =(char)Serial.read();                  //Doc 1 byte du lieu vua nhan
    RxBuff += inChar;                                   //Ghi byte do vao bo dem RxBuff
    if(RxBuff.length()>=128){
      RxBuff="";
    }
  }
  
  int i;

  Index_Rxdata = RxBuff.indexOf("BATDEN");              // Tim vi tri cua chuoi "sw1on" trong bo dem nhan RxBuff
  if(Index_Rxdata >= 0)                                                   // Neu tim thay "LAMP_ON" trong RxBuff
  {
    Index_Rxdata = -1;                                                     // 
    //RxBuff = "";                                                                   // Xoa bo dem
    digitalWrite(4, LOW);                                             // Dong Relay de bat den // Bat bong den
    if(!digitalRead(4)){
        String content_sms;
        content_sms = "Den da duoc Bat";
        GSM_MakeSMS(myphone, content_sms);
    }
  }
 
  Index_Rxdata = RxBuff.indexOf("TATDEN");              // Tim vi tri cua chuoi "sw1on" trong bo dem nhan RxBuff
  if(Index_Rxdata >= 0)                                                   // Neu tim thay "LAMP_ON" trong RxBuff
  {
    Index_Rxdata = -1;                                                     // 
    //RxBuff = "";                                                                   // Xoa bo dem
    digitalWrite(4, HIGH);                                             // Dong Relay de bat den // Bat bong den
    if(digitalRead(4)){
        String content_sms;
        content_sms = "Den da duoc Tat";
        GSM_MakeSMS(myphone, content_sms);
    }
  }
 
   Index_Rxdata = RxBuff.indexOf("KIEMTRA");      // Gui tin nhan bao trang thai cua cac relay dieu khien
   if(Index_Rxdata >=0){
      String content_sms;
      if(!digitalRead(4)){
        content_sms = "Den dang Bat";
        GSM_MakeSMS(myphone, content_sms);
      }else{
        content_sms = "Den dang Tat";
        GSM_MakeSMS(myphone, content_sms);
      }

   }
   RxBuff = "";
}
//-----Cau hinh module GSM------------
void GSM_Power_On(){
  digitalWrite(4, HIGH);                // Du chan PWR_KEY len cao it nhat 1s 
  delay(1500);                                            // o day ta de 1,5s
  digitalWrite(4, LOW);                  // Du chan PWR_KEY xuong thap
  delay(100);                                              // cac ban xem trong Hardware designed sim800C de hieu ro hon
}
void GSM_Init(){
  Serial.println("ATE0");                            // Tat che do phan hoi (Echo mode)
  delay(2000);
  Serial.println("AT+IPR=9600");              // Dat toc do truyen nhan du lieu 9600 bps
  delay(2000);
  Serial.println("AT+CMGF=1");                // Chon che do TEXT Mode
  delay(2000);
  Serial.println("AT+CLIP=1");                  // Hien thi thong tin nguoi goi den
  delay(2000);
  Serial.println("AT+CNMI=2,2");              // Hien thi truc tiep noi dung tin nhan
  delay(2000);  
}
void GSM_MakeCall(String phone){
  Serial.println("ATD" + phone + ";");         // Goi dien 
  delay(10000);                                        // Sau 10s
  Serial.println("ATH");                              // Ngat cuoc goi
  delay(2000);
}
void GSM_MakeSMS(String phone, String content){
  Serial.println("AT+CMGS=\"" + phone + "\"");     // Lenh gui tin nhan
  delay(3000);                                                     // Cho ky tu '>' phan hoi ve 
  Serial.print(content);                                          // Gui noi dung
  Serial.print((char)26);                                         // Gui Ctrl+Z hay 26 de ket thuc noi dung tin nhan va gui tin di
  delay(5000);                                                      // delay 5s
}
