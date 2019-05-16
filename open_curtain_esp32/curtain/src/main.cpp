#include <Arduino.h>
#include "wifi_handler.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);
  wifi_handler wh;
  wh.setup_wifi();
}

void loop() {
  // put your main code here, to run repeatedly:

}
