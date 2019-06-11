#ifndef OUTPUTS_MANAGE_H
#define OUTPUTS_MANAGE_H

#include <Arduino.h>
#include "state.h"
#include "constants/pinassign.h"
#include "constants/keyword.h"
#include "constants/output_parameters.h"

void output(State state);

void motor_setup();

void open_curtain();

void close_curtain();


#endif
