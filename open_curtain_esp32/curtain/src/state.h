#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
class State{

public:
  static const uint8_t none =   0b00000;
  static const uint8_t close =  0b00001;
  static const uint8_t open =   0b00010;
  static const uint8_t buzzer = 0b00100;
  uint8_t state;

  State(){
    _state = none;

  }

  // State& operator|=(const State state){
  //   _state |= state._state;
  //   return *this;
  // }
  // State& operator=(const State state){
  //   _state = state._state;
  //   return *this;
  // }


};
#endif
