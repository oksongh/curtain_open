#ifndef ETC_H
#define ETC_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "pinassign.h"
#include "keyword.h"

State parse(const String command);

State read_button(State state);

std::vector<String> split(const String s);

#endif
