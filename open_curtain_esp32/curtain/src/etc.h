#ifndef ETC_H
#define ETC_H

#include <Arduino.h>
#include <vector>
#include "state.h"
#include "pinassign.h"

State parse(const String command){

  State newState;
  std::vector<String> vecstr = split(command);

  if (vecstr[0] == "open"){
    newState.state |= State::open;

  }else if(vecstr[0] == "close"){
    newState.state |= State::close;

  }else if(vecstr[0] == "reserve"){
    if(vecstr[1]){

    }
      if(vecstr[2] == "open"){

      }else if(vecstr[2] == "close"){

      }else{

      }

  }else{
    // newState.state == State::none;

  }
  return newState;
}

State read_button(State state){

  if(digitalRead(closepin)){
    state.state |= State::close;
  }else if(digitalRead(openpin)){
    state.state |= State::open;
  }else{
    state.state |= State::none;
  }
  return state;
}

std::vector<String> split(const String s){
  std::vector<String> vecstr;

  for(int i,prei = 0;i < s.length();i++){
    if(s[i] == ' '){
      vecstr.push_back(s.substring(prei, i));
      prei = i;
    }
  }
  return vecstr;
}

#endif
