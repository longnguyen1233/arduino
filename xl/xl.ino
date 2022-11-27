#ifdef ESP32
#include <WiFi.h>
#include <time.h>
#include <WebServer.h>
WebServer server(80);

#define RELAY1 22
#define RELAY2 21

#elif ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80);
#define LED1 2
#define RELAY1 D0
#define RELAY2 D1
#define NUT1 D2
#define NUT2 D3
#define NUT3 D5

#endif

#include "web.h"

const char *ssid = "DienTuTuyetNga-2.4G";
const char *pass= "baovy0111";

//config địa chỉ ip esp cố định

IPAddress local_IP(192, 168, 1, 121);

IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

String ChuoiSendWebJson = ""; //chuỗi tổng để send dữ liệu
float nhietdo;
float doam;
int TTTB1, BienDF, BienGH, BienJK, BienKL, BienLZ, BienZX, BienXC, BienCV, BienVB, BienBN, BienNM, BienMQ, BienQW, BienWE, BienER, BienRT;
int TTTB2, dung_ngay, dung_gio;
int timezone= 7*3600;
int dst=0;
int ngay, phut, gio, cai_giay;
unsigned long last = 0, time_bd,t,time_bom;


void ConnectWiFi();
void Led_Blynk1();
void Led_Blynk();
void SendWebPage();
void Send_Update();
void DataJson (String sensor1, String sensor2, String sensor3, String sensor4, String sensor5, String sensor6, String sensor7, String sensor8, String sensor9, String sensor10, String sensor11, String sensor12, String sensor13, String sensor14, String sensor15, String sensor16, String sensor17, String sensor18, String sensor19, String sensor20 );
void chuongtrinhcambien();
void Onclick_Button();
void XylyONOFF(String button);
void Send_Input();
void XulyData(String InPut);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);
 

  Led_Blynk1();

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  // Led chế độ


  //MẶC ĐỊNH OFF RELAY
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  Serial.println();
  delay(5000);

  ConnectWiFi();

  

  server.on("/",[] {
    SendWebPage();
  });

  server.on("/Update",[] {
    Send_Update();
  });
  
  server.on("/Button",[] {
    Onclick_Button();
  });

  server.on("/Input",[] {
    Send_Input();
  });
  
  server.begin();
  Serial.println("Server start");
  Led_Blynk();
  last = millis();
  time_bom=millis();
  cai_giay=0;
  
  
  configTime(timezone,dst,"pool.ntp.org","time.nist.gov");
  Serial.println("Waiting for server");
  while(!time(nullptr)){
  Serial.print("#");
  delay(500);
  }
   Serial.println("Time respone is ok!: "); 
  }
  
void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();// duy trì server cho mình
  if(millis() - last >= 1000)
  {
    chuongtrinhcambien();
    last= millis();
  }
  //kt_ngay_bd_kt_1();
  
  if(dung_ngay ==1){
    
   if(BienJK - gio == 0 && phut == 8)
   {
      dung_gio = 1;  
      cai_giay=1;
   }
   else if (phut != 8 &&cai_giay ==0)
   {
    time_bom= millis();
    
   }
  }

    
  if(dung_gio == 1)
  {
      
    if(millis()-time_bom >= (BienKL*60000))
    {
      dung_gio = 0;
      digitalWrite(RELAY1, LOW);
      cai_giay=0;
      
      
    }
    else
    {
      digitalWrite(RELAY1, HIGH);
    }

  }

  if(millis()-t >500) {
  time_t now = time(nullptr);
  struct tm* p_tm=localtime(&now);
  gio = p_tm->tm_hour;
  phut = p_tm->tm_min;
  t=millis();
   }   
   //Serial.print("giây");
   //Serial.println(millis()-time_bom);
}



void kt_ngay_bd_kt_1()
{
  if(time_bd >= ((BienDF-1)*86400000) && time_bd <= ((BienGH)*86400000))
  {
    dung_ngay = 1;
  }
  else{
    dung_ngay = 0;
  }
}
void XulyData(String InPut)
{
  int TimD, TimF, TimG, TimH, TimJ, TimK, TimL,TimZ, TimX, TimC, TimV, TimB, TimN, TimM, TimQ, TimW, TimE, TimR, TimT;
  TimD = InPut.indexOf("D");
  TimF = InPut.indexOf("F");
  TimG = InPut.indexOf("G");
  TimH = InPut.indexOf("H");
  TimJ = InPut.indexOf("J");
  TimK = InPut.indexOf("K");
  TimL = InPut.indexOf("L");
  TimZ = InPut.indexOf("Z");
  TimX = InPut.indexOf("X");
  TimC = InPut.indexOf("C");
  TimV = InPut.indexOf("V");
  TimB = InPut.indexOf("B");
  TimN = InPut.indexOf("N");
  TimM = InPut.indexOf("M");
  TimQ = InPut.indexOf("Q");
  TimW = InPut.indexOf("W");
  TimE = InPut.indexOf("E");
  TimR = InPut.indexOf("R");
  TimT = InPut.indexOf("T");

  if(TimD >= 0 && TimF >= 0)  //biến DF là ngày bắt đầu 1
  {
    String DataDF = "";
    DataDF = InPut.substring(TimD + 1 , TimF);
    BienDF =  DataDF.toInt();
  }

  if(TimG >= 0 && TimH >= 0)  //biến GH là ngày kết thúc 1
  {
    String DataGH = "";
    DataGH = InPut.substring(TimG + 1 , TimH);
    BienGH =  DataGH.toInt();
  }

  if(TimJ >= 0 && TimK >= 0)  //biến JK là giờ bơm 1
  {
    String DataJK = "";
    DataJK = InPut.substring(TimJ + 1 , TimK);
    BienJK =  DataJK.toInt();
  }

  if(TimK >= 0 && TimL >= 0)  //biến KL là thời gian bơm 1
  {
    String DataKL = "";
    DataKL = InPut.substring(TimK + 1 , TimL);
    BienKL =  DataKL.toInt();
  }

  if(TimL >= 0 && TimZ >= 0)  //biến LZ là ngày bắt đầu 2
  {
    String DataLZ = "";
    DataLZ = InPut.substring(TimL + 1 , TimZ);
    BienLZ =  DataLZ.toInt();
  }

  if(TimZ >= 0 && TimX >= 0)  //biến ZX là ngày kết thúc 2
  {
    String DataZX = "";
    DataZX = InPut.substring(TimZ + 1 , TimX);
    BienZX =  DataZX.toInt();
  }

  if(TimX >= 0 && TimC >= 0)  //biến XC là giờ bơm 2
  {
    String DataXC = "";
    DataXC = InPut.substring(TimX + 1 , TimC);
    BienXC =  DataXC.toInt();
  }

  if(TimC >= 0 && TimV >= 0)  //biến CV là thời gian bơm 2
  {
    String DataCV = "";
    DataCV = InPut.substring(TimC + 1 , TimV);
    BienCV =  DataCV.toInt();
  }


  if(TimV >= 0 && TimB >= 0)  //biến VB là ngày bắt đầu 3
  {
    String DataVB = "";
    DataVB = InPut.substring(TimV + 1 , TimB);
    BienVB =  DataVB.toInt();
  }

  if(TimB >= 0 && TimN >= 0)  //biến BN là ngày kết thúc 3
  {
    String DataBN = "";
    DataBN = InPut.substring(TimB + 1 , TimN);
    BienBN =  DataBN.toInt();
  }

  if(TimN >= 0 && TimM >= 0)  //biến NM là giờ bơm 3
  {
    String DataNM = "";
    DataNM = InPut.substring(TimN + 1 , TimM);
    BienNM =  DataNM.toInt();
  }

  if(TimM >= 0 && TimQ >= 0)  //biến MQ là thời gian bơm 3
  {
    String DataMQ = "";
    DataMQ = InPut.substring(TimM + 1 , TimQ);
    BienMQ =  DataMQ.toInt();
  }

  if(TimQ >= 0 && TimW >= 0)  //biến QW là ngày bắt đầu 4
  {
    String DataQW = "";
    DataQW = InPut.substring(TimQ + 1 , TimW);
    BienQW =  DataQW.toInt();
  }

  if(TimW >= 0 && TimE >= 0)  //biến WE là ngày kết thúc 4
  {
    String DataWE = "";
    DataWE = InPut.substring(TimW + 1 , TimE);
    BienWE =  DataWE.toInt();
  }

  if(TimE >= 0 && TimR >= 0)  //biến ER là giờ bơm 4
  {
    String DataER = "";
    DataER = InPut.substring(TimE + 1 , TimR);
    BienER =  DataER.toInt();
  }

  if(TimR >= 0 && TimT >= 0)  //biến RT là thời gian bơm 4
  {
    String DataRT = "";
    DataRT = InPut.substring(TimR + 1 , TimT);
    BienRT =  DataRT.toInt();
  }
}
void Send_Input()
{
  Serial.println(">>>Send InPut");
  Serial.println(server.arg("Input"));
  String InPut = "";
  InPut = server.arg("Input");
  XulyData(String(InPut));
  server.send(200, "text/html", webpage );
  time_bd = millis();
}
void XylyONOFF(String button)
{
  if(button.indexOf("A0B") >= 0)
  {
    Serial.println("OFF DEN");
    digitalWrite(RELAY1, LOW);
    TTTB1 = 0;
  }
  else if(button.indexOf("A1B") >= 0)
  {
    Serial.println("ON DEN");
    digitalWrite(RELAY1, HIGH);
    TTTB1 = 1;
  }

  if(button.indexOf("C0D") >= 0)
  {
    Serial.println("OFF QUAT");
    digitalWrite(RELAY2, LOW);
    TTTB2 = 0;
  }
  else if(button.indexOf("C1D") >= 0)
  {
    Serial.println("ON QUAT");
    digitalWrite(RELAY2, HIGH);
    TTTB2 = 1;
  } 
}
void Onclick_Button()
{
  Serial.println(">>>Onclick Button");
  Serial.println(server.arg("Button"));
  String button = "";
  button = server.arg("Button");
  XylyONOFF(String(button));
  server.send(200, "text/html", webpage );
}

void chuongtrinhcambien()
{
  nhietdo= nhietdo +1.1;
  doam= doam +1.2;
  if (nhietdo >= 151)
  {
    nhietdo = 0;
  }
  if (doam >= 101)
  {
   doam = 0; 
  }
}

void Send_Update()
{
  //send dữ liệu JSON
  DataJson(String(nhietdo), String(doam), String(TTTB1), String(TTTB2), String(BienDF), String(BienGH), String(BienJK), String(BienKL), String(BienLZ), String(BienZX), String(BienXC), String(BienCV), String(BienVB), String(BienBN), String(BienNM), String(BienMQ), String(BienQW), String(BienWE), String(BienER), String(BienRT));
  server.send(200, "text/html", String(ChuoiSendWebJson) );
}
void DataJson (String sensor1, String sensor2, String sensor3, String sensor4, String sensor5, String sensor6, String sensor7, String sensor8, String sensor9, String sensor10, String sensor11, String sensor12, String sensor13, String sensor14, String sensor15, String sensor16, String sensor17, String sensor18, String sensor19, String sensor20 )
{
  ChuoiSendWebJson = "{\"ND\":\"" + String(sensor1) + "\","+
                      "\"DA\":\"" + String(sensor2) + "\","+
                      "\"TB1\":\"" + String(sensor3) + "\","+
                      "\"TB2\":\"" + String(sensor4) + "\","+
                      "\"DF\":\"" + String(sensor5) + "\","+
                      "\"GH\":\"" + String(sensor6) + "\","+
                      "\"JK\":\"" + String(sensor7) + "\","+
                      "\"KL\":\"" + String(sensor8) + "\","+
                      "\"LZ\":\"" + String(sensor9) + "\","+
                      "\"ZX\":\"" + String(sensor10) + "\","+
                      "\"XC\":\"" + String(sensor11) + "\","+
                      "\"CV\":\"" + String(sensor12) + "\","+
                      "\"VB\":\"" + String(sensor13) + "\","+
                      "\"BN\":\"" + String(sensor14) + "\","+
                      "\"NM\":\"" + String(sensor15) + "\","+
                      "\"MQ\":\"" + String(sensor16) + "\","+
                      "\"QW\":\"" + String(sensor17) + "\","+
                      "\"WE\":\"" + String(sensor18) + "\","+
                      "\"ER\":\"" + String(sensor19) + "\","+
                      "\"RT\":\"" + String(sensor20) + "\"}";
}
void SendWebPage()
{
    server.send(200, "text/html", webpage );
}
void ConnectWiFi()
{
    
  WiFi.disconnect(); delay(1000);
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS))
  {
    Serial.println("STA Failed to configure");
  }
  delay(1000); WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Đã kết nối");
  Serial.print("Connected,IP address: ");
  Serial.println(WiFi.localIP());
}
void Led_Blynk1()
{
  #ifdef ESP8266
    digitalWrite(LED1, LOW);
  #endif
}

void Led_Blynk()
{
  #ifdef ESP8266
    digitalWrite(LED1, HIGH);
  #endif
}
