#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define MQ_PIN A0
#define BUZZER_PIN 3  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(1000);
  }
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);  
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Sıcaklık: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(" --- ");

  Serial.print("Nem: ");
  Serial.print("%");
  Serial.print(humidity);
  Serial.print(" --- ");

  int gasValue = analogRead(MQ_PIN);
  Serial.print(" Gaz Değeri: ");
  Serial.print(gasValue);


  int havaKalitesiYuzde = map(gasValue, 65, 200, 95, 100);
  Serial.print(" --- Hava Kalitesi: ");
  Serial.print(havaKalitesiYuzde);
  Serial.println("%");


  if (gasValue > 140) {
    digitalWrite(BUZZER_PIN, HIGH);  
  } else {
    digitalWrite(BUZZER_PIN, LOW);   
  }

  delay(1000);
}
