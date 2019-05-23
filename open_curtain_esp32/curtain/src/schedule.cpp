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
void Schedule::serialprint(){
  Serial.printf("now %ld:%ld,exe at %ld:%ld,state:%d,state:", _now_hour,_now_min,_exetime_hour,_exetime_min,_state);
  Serial.println(_state,BIN);


}
