#ifndef ETC_H
#define ETC_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "constants/pinassign.h"
#include "constants/keyword.h"
#include "task.h"
#include "constants/output_parameters.h"

void parse(const String command,State &state,Task &task);

void read_button(State &state);

// std::vector<String> split(const String s);
void split(const String,std::vector<String> &vecstr);


#endif
