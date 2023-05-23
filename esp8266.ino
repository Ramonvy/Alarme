#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <NTPClient.h>
#include <WiFiUdp.h>


const char* ssid     = "";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "";

//Shutdown
int m10 = 4;            //hora
int m11 = 0;            //minuto
int m12 = 0;            //segundo


//Power
int m20 = 6;            //hora
int m21 = 30;            //minuto
int m22 = 0;            //segundo

WiFiUDP ntpUDP;

//Adjusting to use the Brasilia time zone(GMT-3) > -3 * 60 * 60 = -10800
NTPClient timeClient(ntpUDP, -10800);


int stt = 0;

void setup() {
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  //delay(3000);
  Serial.println('\n');

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  timeClient.begin();
}

void loop() {
  timeClient.update();
  if(stt == 1){
    Serial.print("Registro aberto ");
  }
  else{
    Serial.print("Registro fechado ");
  }
  
  Serial.println(timeClient.getFormattedTime());

  if(timeClient.getHours() == m10 && timeClient.getMinutes() == m11 && timeClient.getSeconds() >= m12){
    //digitalWrite(0, HIGH);
    digitalWrite(0, LOW);
    stt = 1;
  }

  if(timeClient.getHours() >= m20 && timeClient.getMinutes() >= m21 && timeClient.getSeconds() >= m22 && stt == 1){
     //digitalWrite(0, LOW);
     digitalWrite(0, HIGH);
      stt = 0;
  }

  
  delay(500);

}
