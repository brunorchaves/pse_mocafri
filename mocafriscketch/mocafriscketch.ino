#include "thingProperties.h"

const unsigned long SEND_INTERVAL_MS = 5000UL;

void setup() {
  Serial.begin(115200);
  delay(1500);

  initProperties();                               // credenciais + vars
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  randomSeed(esp_random());                       // valores aleatórios

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();                          // mantém MQTT

  static unsigned long lastSend = 0;
  if (millis() - lastSend >= SEND_INTERVAL_MS) {
    lastSend = millis();

    temperature = random(180, 326) / 10.0f;       // 18,0–32,5 °C
    doorState   = random(0, 2);                   // 0 ou 1

    Serial.printf("📡 Temp: %.1f °C | Porta: %s\n",
                  temperature,
                  doorState ? "FECHADA" : "ABERTA");
  }
}

void onTemperatureChange() {
  Serial.printf("↘️  Dashboard mudou temperature → %.1f °C\n", temperature);
}

void onDoorStateChange() {
  Serial.printf("↘️  Dashboard mudou doorState   → %s\n",
                doorState ? "FECHADA" : "ABERTA");
}
