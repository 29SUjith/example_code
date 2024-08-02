#include <math.h>

const int sineWavePin = 9; // Pin to output the sine wave
const int frequency = 1; // Frequency in Hz
const int samples = 100; // Number of samples per period
const int amplitude = 127; // Amplitude of the sine wave (127 for 0-255 range)
const int offset = 128; // Offset to center the sine wave in the 0-255 range
const int period = 1000000 / (frequency * samples); // Period in microseconds per sample

void setup() {
  pinMode(sineWavePin, OUTPUT);
  Serial.begin(115200); // Initialize Serial communication at 115200 baud
}

void loop() {
  for (int i = 0; i < samples; i++) {
    float angle = 2 * PI * i / samples; // Calculate the angle for this sample
    int value = offset + amplitude * sin(angle); // Calculate the sine value
    analogWrite(sineWavePin, value); // Set the PWM duty cycle
    Serial.println(value); // Print the value for the Serial Plotter
    delayMicroseconds(period); // Wait for the period per sample
  }
}
