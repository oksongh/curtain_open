#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
class State{

public:
  static const uint8_t none = 0b00000;
  static const uint8_t close = 0b00001;
  static const uint8_t open =  0b00010;
  uint8_t state;

  State();
  /*
  static uint8_t operator|(){

  }
  */


};
#endif
