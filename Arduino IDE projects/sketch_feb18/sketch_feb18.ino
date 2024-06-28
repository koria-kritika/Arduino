#include <DHT.h>

#define DHTPIN 2     // Pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define FAN_PIN 3     // Pin connected to the Fan

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  delay(1000);  // Wait for 2 seconds to take readings
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  if (temperature > 24) {  // Turn on the fan if temperature is greater than 25 degrees Celsius
    digitalWrite(FAN_PIN, HIGH);
    Serial.println("Fan ON");
  } else {  // Turn off the fan otherwise
    digitalWrite(FAN_PIN, LOW);
    Serial.println("Fan OFF");
  }
}


















