#include <Arduino.h>
#include "wifi_handler.h"
#include "etc.h"
#include "state.h"
#include "pinassign.h"

wifi_handler wh;
String command;
State state;

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
  Serial.printf("state:");
  Serial.println(state.state,BIN);
  delay(800);

}
