#ifndef SCHDULE_H
#define SCHDULE_H

#include <Arduino.h>
#include "state.h"

class Schedule{
private:
  long _exetime_hour;//8
  long _exetime_min;//20
  static long _now;
  uint8_t state;

  long to_time(char c1,char c2){
    return (c1 - '0') * 10 + c2 - '0';
  }
public:
  static const uint8_t none = 0b00000;
  static const uint8_t close = 0b00001;
  static const uint8_t open =  0b00010;

  State get_state(){
    return _state;
  }
  void set_state(State s){
    _state = s;
  }
  void or_state(State s){
    _state.state |= s.state;
  }
  void set_time(const char* str,int len){
    if(len != 4){
      return;
    }
    _exetime_hour = to_time(str[0], str[1]);
    _exetime_min = to_time(str[2], str[3]);
  }

};

#endif
