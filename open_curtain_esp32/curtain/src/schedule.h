#ifndef SCHDULE_H
#define SCHDULE_H

#include "state.h"

class Schedule{
private:
  long _exetime_hour;//8
  long _exetime_min;//20
  State _state;
  static long _now;
  long to_time(char c1,char c2){
    return (c1 - '0') * 10 + c2 - '0';
  }
public:
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
