#include <Arduino.h>
#include "wifi_handler.h"
#include "etc.h"
#include "state.h"
#include "pinassign.h"
#include "task.h"

wifi_handler wh;
String command;
State state;
Task task;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  wh.setup_wifiAP();
  wh.setup_wifi();

}

void loop() {
  // put your main code here, to run repeatedly:
  command = wh.read_udp();
  parse(command,state,task);
  task.loop(state);
  // output(state,task);
  read_button(state);
  Serial.printf("state:");
  Serial.println(state.state,BIN);
  delay(1800);

}
