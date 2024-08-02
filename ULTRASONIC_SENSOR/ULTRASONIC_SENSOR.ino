// Define pins for the ultrasonic sensor
#define trigPin 3
#define echoPin 4

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT); // Set trigPin as OUTPUT
  pinMode(echoPin, INPUT); // Set echoPin as INPUT
}

void loop() {
  long duration, distance;
  
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = (duration * 0.0343) / 2; // Speed of sound is 343 meters/second or 0.0343 centimeters/microsecond
  
  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait for a short while before taking the next measurement
  delay(500);
}
