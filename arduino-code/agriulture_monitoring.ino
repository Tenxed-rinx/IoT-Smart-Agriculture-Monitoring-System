#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define SOIL_PIN A0
#define LDR_PIN A1
#define WATER_LEVEL_PIN A2

#define PUMP_PIN 7

DHT dht(DHTPIN, DHTTYPE);

// Threshold values
int soilThreshold = 500;
int tempThreshold = 35;
int waterThreshold = 200;

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(PUMP_PIN, OUTPUT);

  Serial.println("🌱 Smart Agriculture Monitoring Started");
}

void loop() {

  // Sensor Readings
  int soilMoisture = analogRead(SOIL_PIN);
  int lightValue = analogRead(LDR_PIN);
  int waterLevel = analogRead(WATER_LEVEL_PIN);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("--------------------------------");

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Light Intensity: ");
  Serial.println(lightValue);

  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  // Pump Logic
  if (soilMoisture > soilThreshold) {

    digitalWrite(PUMP_PIN, HIGH);

    Serial.println("🚰 Pump Status: ON");
    Serial.println("⚠ ALERT: Soil is Dry");

  } else {

    digitalWrite(PUMP_PIN, LOW);

    Serial.println("🚰 Pump Status: OFF");
  }

  // High Temperature Alert
  if (temperature > tempThreshold) {
    Serial.println("🔥 ALERT: High Temperature");
  }

  // Low Water Alert
  if (waterLevel < waterThreshold) {
    Serial.println("💧 ALERT: Low Water Level");
  }

  delay(2000);
}