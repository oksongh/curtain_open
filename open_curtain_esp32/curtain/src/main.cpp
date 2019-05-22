#include <Arduino.h>
#include "wifi_handler.h"
#include "etc.h"
#include "pinassign.h"

wifi_handler wh;
String command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  wh.setup_wifiAP();
  wh.setup_wifi();

}

void loop() {
  // put your main code here, to run repeatedly:
  command = wh.read_udp();
  state = parse(command);
  read_button(state);
  millis()

  Serial.printf("state:");
  Serial.println(state.state,BIN);
  state.
  delay(800);

}
