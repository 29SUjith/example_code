const int squareWavePin = 9; // Pin to output the square wave
const int frequency = 1000;  // Frequency of the square wave in Hertz
const int period = 1000000 / frequency; // Period in microseconds

void setup() {
  pinMode(squareWavePin, OUTPUT);
}

void loop() {
  digitalWrite(squareWavePin, HIGH);
  delayMicroseconds(period / 2); // Half period for HIGH state
  digitalWrite(squareWavePin, LOW);
  delayMicroseconds(period / 2); // Half period for LOW state
}
