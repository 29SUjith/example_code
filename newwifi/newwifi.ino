#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include<Servo.h>

const char* ssid = "M S Innovations";
const char* password = "Subramanya";
const int trigPin=D8;
const int echoPin=D7;
volatile bool OD=false;
volatile long dis;
ESP8266WebServer server(80);
Servo servo;
unsigned long currentTime,previousTime,delayTime=100;
void dist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  long distance = (duration / 2) / 29.1;

  if (distance >= 2 && distance <= 400) {
    dis=distance;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    }
    else {
    Serial.println("Out of range");
  }
}

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
  servo.attach(D6);
  servo.write(90);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
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
  currentTime=millis();
  if (currentTime-previousTime>=delayTime && !OD)
  {
    dist();
    if (dis<=8)
    {
      OD=true;
    }
    previousTime=currentTime;
  }
  if(OD)
  {
      off();
      server.send(200,"text/plain","Cant go front");
      delay(250);
      servo.write(180);
      if (dis<=8)
      {
        server.send(200,"text/plain","I Cant go right");
      }
      else
      server.send(200,"text/plain","I Can go right");
      delay(250);
      servo.write(0);
      if(dis<=8)
      server.send(200,"text/plain","I Cant go left");
      else
      server.send(200,"text/plain","I Can go left");
      delay(250);
      servo.write(0);
      OD=false;
  }
 // String message = "A"; // Your response message
  
  //server.send(200, "text/plain", message); // Send a response to the client
  
  String dataReceived = server.arg("data"); // Get the data sent by the client
  if (dataReceived != "") {
    server.send(200,"text/plain","A");
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
    // You can process the received data here
    delay(10);
  }
  
}