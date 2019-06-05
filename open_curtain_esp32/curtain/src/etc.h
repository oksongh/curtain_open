#ifndef ETC_H
#define ETC_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "pinassign.h"
#include "keyword.h"
#include "task.h"
#include "constants/output_parameters.h"

void parse(const String command,State &state,Task &task);

void read_button(State &state);

// std::vector<String> split(const String s);
void split(const String,std::vector<String> &vecstr);

void output(State state);

void open_curtain();

void close_curtain();

#endif
