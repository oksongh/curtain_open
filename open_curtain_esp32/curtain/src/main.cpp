#include <Arduino.h>
#include "wifi_handler.h"
#include "etc.h"
#include "pinassign.h"
#include "schedule.h"

wifi_handler wh;
String command;
Schedule sche;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  wh.setup_wifiAP();
  wh.setup_wifi();

}

void loop() {
  // put your main code here, to run repeatedly:
  command = wh.read_udp();
  sche.parse(command);
  sche.read_button();
  sche.serialprint();
  // Serial.printf("state %d\n",sche.get_state() );
  // state = parse(command);
  // read_button(state);
  // millis();

  // Serial.printf("state:");
  // state.
  delay(1500);

}
