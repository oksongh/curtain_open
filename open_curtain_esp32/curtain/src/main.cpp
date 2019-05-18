#include <Arduino.h>
#include "wifi_handler.h"
#include "etc.h"
#include "state.h"
#include "pinassign.h"

wifi_handler wh;
String command;
int closepin = 5;
int openpin = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  wh.setup_wifiAP();
  wh.setup_wifi();

  int a = 0b001;
  int b = 0b000;
  a |= b;
}

void loop() {
  // put your main code here, to run repeatedly:
  command = wh.read_udp();


}
