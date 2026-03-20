#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("=== High-Level ECU Booting ===");
    Serial.println("ESP32-S3 ready.");
}

void loop() {
    Serial.println("High-Level ECU alive.");
    delay(1000);
}
