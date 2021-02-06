#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define WATER_SENSOR 8

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(WATER_SENSOR, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("*** Water Sensor ***");
}

void loop() {
  int water = digitalRead(WATER_SENSOR);

  lcd.setCursor(0, 2);
  // lcd.print( water ? "* Water Detected *" : "* No Water Present *");

  if (water) {
    lcd.print("* Water Detected *");
  } else {
    lcd.print("* No Water Present *");
  }
}
