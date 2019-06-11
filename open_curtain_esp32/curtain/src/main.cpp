#include <Arduino.h>
#include "wifi_handler.h"
#include "state.h"
#include "task.h"
#include "outputs/output_manege.h"
#include "inputs/inputs_manage.h"

// String command;
Task task;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  wh.setup_wifiAP();
  wh.setup_wifi();

  motor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  command = wh.read_udp();
  parse(command,state,task);

  task.check_time(state);

  read_button(state);


  Serial.printf("state:");
  Serial.println(state.state,BIN);

  output(state);

  Serial.printf("state:");
  Serial.println(state.state,BIN);
  delay(2000);

}
