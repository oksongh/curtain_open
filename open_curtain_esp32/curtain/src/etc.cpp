#include "etc.h"

State parse(const String command){
// command :str_none,and so on
  State newState;
  std::vector<String> vecstr;

  split(command, vecstr);

  if (vecstr[0] == str_open){
    newState.state |= State::open;

  }else if(vecstr[0] == str_close){
    newState.state |= State::close;

  }else if(vecstr[0] == str_reserve){
    if(vecstr[1]){

    }
      if(vecstr[2] == str_open){

      }else if(vecstr[2] == str_close){

      }else{

      }

  }else{
    // newState.state == State::none;

  }
  return newState;
}

State read_button(State state){

  if(digitalRead(closepin)){
    state.state = State::close;
  }else if(digitalRead(openpin)){
    state.state = State::open;
  }else{
  }
  return state;
}

void split(String s,std::vector<String> &vecstr){
  if(s.length() == 0){
    return;
  }
  s += char_split;
  for(int i = 0,prei = 0;i < s.length();i++){
    if(s[i] == char_split){
      vecstr.push_back(s.substring(prei, i));
      prei = i;
    }
  }

}
