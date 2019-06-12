#include <Arduino.h>
#include "wifi_handler.h"
#include "state.h"
#include "task.h"
#include "outputs/outputs_manage.h"
#include "inputs/inputs_manage.h"

// String command;
// Task task;
inputs_manage input;
State state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(112500);

  input.setup_input();
  // wh.setup_wifiAP();
  // wh.setup_wifi();

  motor_setup();
}

void loop() {
  state = input.reload();
  Serial.printf("state:");
  Serial.println(state.state,BIN);

  output(state);

  Serial.printf("state:");
  Serial.println(state.state,BIN);
  delay(2000);

}
