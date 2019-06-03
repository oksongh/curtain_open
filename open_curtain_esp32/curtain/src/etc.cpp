#include "etc.h"

void parse(const String command,State &state,Task &task){
// command :str_none,and so on
  State newState;
  std::vector<String> vecstr;

  split(command, vecstr);
  int i = 0;
  if (vecstr[i] == str_open){
    newState.state |= State::open;
    i++;

  }else if(vecstr[i] == str_close){
    newState.state |= State::close;
    i++;

  }else if(vecstr[i] == str_reserve){
    i++;

    if(vecstr[i] == str_open){
      task.open();
      i++;
    }else if(vecstr[i] == str_close){
      task.close();
      i++;
    }else if(vecstr[i] == str_buzzer){
      task.buzzer();
      i++;

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
