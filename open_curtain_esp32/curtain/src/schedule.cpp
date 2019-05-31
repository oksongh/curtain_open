#include "schedule.h"

long Schedule::_now_min = 0;
long Schedule::_now_hour = 0;

long Schedule::to_time(char c1, char c2){
  return (c1 - '0') * 10 + c2 - '0';

}

void Schedule::split(String s){
  if(s.length() == 0){
    return;
  }
  s += char_split;
  for(int i = 0,prei = 0;i < s.length();i++){
    if(s[i] == char_split){
      _vecstr.push_back(s.substring(prei, i));
      prei = i;
    }
  }
}

void Schedule::set_time(const char *str, const int len){
  if(len != 4){
    Serial.printf("%d\n",len);
    return;
  }
  _exetime_hour = to_time(str[0], str[1]);
  _exetime_min = to_time(str[2], str[3]);

}

void Schedule::set_now(const char* str,const int len){
  if(len != 4){
    Serial.printf("%d\n",len);
    return;
  }
  _now_hour = to_time(str[0], str[1]);
  _now_min = to_time(str[2], str[3]);

}

void Schedule::read_button(){

  if(digitalRead(closepin)){
    _state |= close;
    // sche.or_state(Schedule::close);
  }else if(digitalRead(openpin)){
    _state |= open;
    // sche.or_state(Schedule::open);
  }else{

  }
}

void Schedule::add_task(){
  if(_exetime_min == init_time || _exetime_hour == init_time){
    _exetime_hour = _now_hour;
    _exetime_min = _now_min;
  }
  tasks.push_back(*this);
}

void Schedule::serialprint(){
  Serial.printf("now %ld:%ld,exe at %ld:%ld,state:%d,state:", _now_hour,_now_min,_exetime_hour,_exetime_min,_state);
  Serial.println(_state,BIN);

}
void Schedule::parse(String msg){
  split(msg);
  for(String s:_vecstr){
    Serial.printf("_vecstr %s\n", s.c_str());
  }

  for (size_t i = 0; i < _vecstr.size();) {
  /* code */

    if(_vecstr[0] == str_open){
      _state |= open;
      i++;
    }else if(_vecstr[0] == str_close){
      _state |= close;
      i++;
    }else if(_vecstr[0] == str_set){

    }else if(_vecstr[0] == str_reserve){
      // etc 1220,0930,2310
      set_time(_vecstr[1].c_str(), _vecstr[1].length());
      i += 2;

    }else if(_vecstr[0] == str_now){
      set_now(_vecstr[1].c_str(),_vecstr[1].length());
      i += 2;

    }else{
    }
  }
}
