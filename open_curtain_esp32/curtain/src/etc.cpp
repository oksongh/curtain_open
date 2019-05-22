#include "etc.h"

State parse(const String command){
// command :str_none,and so on
  // State newState;
  Schedule sche;
  std::vector<String> vecstr;

  split(command, vecstr);

  if (vecstr[0] == str_open){
    sche.or_state(Schedule::open);
    sche.set_time()
  }else if(vecstr[0] == str_close){
    sche.or_state(Schedule::close);

  }else if(vecstr[0] == str_reserve){
    // 受け取ってから[1]s後に実行
    sche.set_time(vecstr[1].c_str());
    // sche.or_state(vecstr[2])

    if(vecstr[2] == str_open){
      sche.or_state(Schedule::open);

    }else if(vecstr[2] == str_close){

    }else{

    }
  }else if{


  }else{
    // newState.state == State::none;

  }
  return newState;
}

void read_button(Schedule &sche){

  if(digitalRead(closepin)){
    sche.or_state(Schedule::close);
  }else if(digitalRead(openpin)){
    sche.or_state(Schedule::open);
  }else{

  }
}

void split(const String s,std::vector<String> &vecstr){

  for(int i = 0,prei = 0;i < s.length();i++){
    if(s[i] == char_split){
      vecstr.push_back(s.substring(prei, i));
      prei = i;
    }
  }
  // no space
  if(vecstr.empty()){
    vecstr.push_back(s);
  }

}
