#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment display = Adafruit_7segment();

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

void setup() {
  Serial.begin(9600);
  display.begin(0x70);
  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));

    display.print("Error");
    display.writeDisplay();

    while(1);
  }
}
void loop() {
  float temperature = bmp.readTemperature();

  display.print(temperature);
  display.writeDisplay();

  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(3000);


  float pressure = bmp.readPressure() / 100;
  
  display.print((int)pressure);
  display.writeDisplay();

  Serial.print("Absolute pressure: ");
  Serial.println(pressure);
  
  delay(3000);
}
