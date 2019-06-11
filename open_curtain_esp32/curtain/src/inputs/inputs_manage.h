#ifndef INPUTS_MANEGE_H
#define INPUTS_MANEGE_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "task.h"
#include "wifi_handler.h"
#include "constants/pinassign.h"
#include "constants/keyword.h"

void split(const String,std::vector<String> &vecstr);

void parse(const String command,State &state,Task &task);

class inputs_manage{
public:
  State state;
  wifi_handler wh;
  Task task;

  State reload();

  void setup_input();

  void read_button(State &state);

};

#endif
