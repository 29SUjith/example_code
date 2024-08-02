// Define the analog pin to which the soil moisture sensor is connected
const int soilMoisturePin = A0;

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the soil moisture sensor
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Map the analog value to a percentage (assuming a range from 0 to 1023)
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Print the values to the serial monitor
  Serial.print("Soil Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print("\t Moisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Add a delay to avoid rapid serial monitor updates
  delay(1000);
}
