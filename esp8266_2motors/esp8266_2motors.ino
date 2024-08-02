#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "M S Innovations";
const char* password = "Subramanya";

ESP8266WebServer server(80);


void front(byte x)
{
  if(x==1)
  {
    Serial.println("F1");
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
  }
  else if(x==2)
  {
    Serial.println("F2");
    digitalWrite(D4,LOW);
    digitalWrite(D5,HIGH);
  }
}
void back(byte x)
{
  if(x==1)
  {
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
  }
  else if(x==2)
  {
     digitalWrite(D4,HIGH);
     digitalWrite(D5,LOW);
  }
}
void right()
{
  front(1);
  back(2);
}
void left()
{
  front(2);
  back(1);
}
void off()
{
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D4,LOW);
  digitalWrite(D5,LOW);
}

void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  analogWrite(D0,127);
  analogWrite(D3,127);
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Adress");
  Serial.println(WiFi.localIP());

  // Define the route and the handler function
  server.on("/", HTTP_GET, handleRequest);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleRequest() {
  String message = "Hello, NodeMCU!"; // Your response message
  
  server.send(200, "text/plain", message); // Send a response to the client
  
  String dataReceived = server.arg("data"); // Get the data sent by the client
  if (dataReceived != "") {
    Serial.println("Received data: " + dataReceived);
    char x=dataReceived.charAt(0);
    if(x=='A')
    {
        front(1);
        front(2);
    }
    else if(x=='B')
    {
      left();
    }
    else if(x=='C')
    {
      right();
    }
    else if(x=='D')
    {
      back(1);
      back(2);
    }
    else if(x=='Z')
    {
      off();
    }
    else if(x=='0')
    {
      analogWrite(D0,0);
      analogWrite(D3,0);
    }
    else if(x=='1')
    {
            analogWrite(D0,64);
            analogWrite(D3,64);
    }
    else if(x=='2')
    {
            analogWrite(D0,127);
            analogWrite(D3,127);
    }
    else if(x=='3')
    {
            analogWrite(D0,191);
            analogWrite(D3,191);
    }
    else if(x=='4')
    {
            analogWrite(D0,255);
            analogWrite(D3,255);
    }
    // You can process the received data here
  }
}
