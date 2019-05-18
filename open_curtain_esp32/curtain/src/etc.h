#ifndef ETC_H
#define ETC_H

#include "state.h"
#include "pinassign.h"
void parse_exe(const String s[]){
  State newState;
  if (s[0]=="open"){
    newState.state |= State::open;
  }
  // switch (s[0]) {
  //   case "open":
  //     state |= open;
  //   case "close":
  //     state |= close;
  //   case "reserve":
  //
  //   default:
  //     state |= none;
  // }
}

State read_button(State state){

  if(digitalRead(closepin)){
    state.state |= State::close;
  }else if(digitalRead(openpin)){
    state.state |= State::open;
  }
  return state;
}

#endif
