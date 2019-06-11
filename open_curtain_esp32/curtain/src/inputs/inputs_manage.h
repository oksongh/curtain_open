#ifndef INPUTS_MANEGE_H
#define INPUTS_MANEGE_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "task.h"
#include "constants/keyword.h"

void parse(const String command,State &state,Task &task);

void read_button(State &state);

void split(const String,std::vector<String> &vecstr);


#endif
