#ifndef STATE_H
#define STATE_H

#include "keyword.h"
// #include "schedule.h"
class State{
// ただbitを保存するだけ
public:


  

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
