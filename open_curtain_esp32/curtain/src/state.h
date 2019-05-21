#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include "keyword.h"
// #include "schedule.h"
class State{
// ただbitを保存するだけ
public:
  static const uint8_t none = 0b00000;
  static const uint8_t close = 0b00001;
  static const uint8_t open =  0b00010;

  uint8_t state;

  State(){
    state = none;

  }
  void convert(String s){
    if(s == str_open){
      state |= open;
    }else if(s == str_close){
      state |= close;
    }else{
      state |= none;
    }
  }
  /*
  static uint8_t operator|(){

  }
  */


};
#endif
