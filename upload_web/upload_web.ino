//----------------------------------------Include the NodeMCU ESP8266 Library

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//----------------------------------------
float u, i,p;


//----------------------------------------SSID dan Password wifi mu gan.
const char* ssid = "Turtle"; //--> Nama Wifi / SSID.
const char* password = "khongcho"; //-->  Password wifi .
//----------------------------------------

//----------------------------------------Host & httpsPort
const char* host = "script.google.com";
const int httpsPort = 443;
//----------------------------------------


WiFiClientSecure client; //--> Create a WiFiClientSecure object.

// Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

String GAS_ID = "AKfycbwV_on9JX2IpGwFuGTMi5lPPQHDh4ha6wI7cC4KMsRiBbDVw0-EL7nzVvmqkGqBgFD4gQ"; //--> spreadsheet script ID

//============================================ void setup
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);


  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");
    


  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
  }
  //----------------------------------------If successfully connected to the wifi router, the IP Address that will be visited is displayed in the serial monitor
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //----------------------------------------

  client.setInsecure();
}
//==============================================================================
//============================================================================== void loop
void loop() {

  now = millis();
  // Publishes new temperature and humidity every 3 seconds
  if (now - lastMeasure > 3000) {
    lastMeasure = now;
    u=random(220.00,224.00);
    i=random(1.00,3);
    p=u*i;
   
    
    Serial.print("Điện áp");
    Serial.print(u);
    Serial.print(" V\t Dòng điện");
    Serial.print(i);
    Serial.print(" *A ");
    
   
     sendData(u,i,p);
    
  }

  
}
//*****
//==============================================================================

void sendData(float value,float value2,float value3) {
  Serial.println("==========");
  Serial.print("connecting to ");
  Serial.println(host);
  
  //----------------------------------------Connect to Google host
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  //----------------------------------------

  //----------------------------------------Proses dan kirim data  

  float dien_ap = value; 
  float dong_dien = value2;
  float cong_suat = value3;
  String url = "/macros/s/" + GAS_ID + "/exec?ap=" + dien_ap + "&dong=" + dong_dien + "&cs=" + cong_suat ;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");

  Serial.println("request sent");
  //----------------------------------------

  //---------------------------------------
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.print("reply was : ");
  Serial.println(line);
  Serial.println("closing connection");
  Serial.println("==========");
  Serial.println();
  //----------------------------------------
} 
//===============================================

