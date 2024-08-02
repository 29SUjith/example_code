//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Web Server App Control Home Automation
#include <WiFi.h>
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "M S Innovations";   //WIFI SSID
const char* password = "Subramanya";    //WIFI PASSWORD

/* data received from application */
String  data =""; 

/* define L298N or L293D motor control pins */
int Relay1 = 12;    //D6
int Relay2 = 16;    //D0
int Relay3 = 4;     //D2
int Relay4 = 5;     //D1


void setup()
{
  /* initialize motor control pins as output */
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT); 
  pinMode(Relay3, OUTPUT);  
  pinMode(Relay4, OUTPUT);

  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  digitalWrite(Relay3,LOW);
  digitalWrite(Relay4,LOW);
  
  /* start server communication */
  Serial.begin(115200);
  connectWiFi();
  server.begin();
}

void loop()
{
    /* If the server available, run the "checkClient" function */  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
Serial.print(data);
/************************ Run function according to incoming data from application *************************/

    
    if (data == "Relay1ON")
    { 
      digitalWrite(Relay1,HIGH);
      }
    
    else if (data == "Relay1OFF")
    {
      digitalWrite(Relay1,LOW);
      }

    else if (data == "Relay2ON")
    {
      digitalWrite(Relay2,HIGH);
      }
      
    else if (data == "Relay2OFF")
    {
      digitalWrite(Relay2,LOW);
      }
      
    else if (data == "Relay3ON")
    {
      digitalWrite(Relay3,HIGH);
      }
      
    else if (data == "Relay3OFF")
    {
      digitalWrite(Relay3,LOW);
      }
      
    else if (data == "Relay4ON")
    {
      digitalWrite(Relay4,HIGH);
      }
      
    else if (data == "Relay4OFF")
    {
      digitalWrite(Relay4,LOW);
      }
      
} 

void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
/********************************** RECEIVE DATA FROM the APP ******************************************/
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

