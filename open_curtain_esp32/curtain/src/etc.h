#ifndef ETC_H
#define ETC_H

#include <Arduino.h>
#include <vector>
#include "pinassign.h"
#include "keyword.h"
#include "schedule.h"

State parse(const String command);

void read_button(Schedule &sche);

// std::vector<String> split(const String s);
void split(const String,std::vector<String> &vecstr);

#endif
