#ifndef SCHDULE_H
#define SCHDULE_H

#include <Arduino.h>
// #include <time.h>
class Schedule{
private:
  //bool is_reserve;
  long _exetime_hour;//8
  long _exetime_min;//20
  // struct tm time;
  static long _now;
  uint8_t _state;
  std::vector<String> _vecstr;

  long to_time(char c1,char c2){
    return (c1 - '0') * 10 + c2 - '0';
  }
  void split(String s){
    s += char_split;
    for(int i = 0,prei = 0;i < s.length();i++){
      if(s[i] == char_split){
        _vecstr.push_back(s.substring(prei, i));
        prei = i;
      }
    }
  }

  void set_time(const char* str,const int len){
    if(len != 4){
      Serial.printf("%d\n",len);
      return;
    }
    _exetime_hour = to_time(str[0], str[1]);
    _exetime_min = to_time(str[2], str[3]);
  }
public:
  static const uint8_t none = 0b00000;
  static const uint8_t close = 0b00001;
  static const uint8_t open =  0b00010;

  uint8_t get_state(){
    return _state;
  }

  void parse(String msg){
    split(msg);
    for(int i = 0;i < _vecstr.size();){
      if(_vecstr[i] == str_open){
        _state |= open;
        i++;
      }else if(_vecstr[i] == str_close){
        _state |= close;
        i++;
      }else if(_vecstr[i] == str_reserve){
        set_time(_vecstr[i+1].c_str(), _vecstr[i+1].length());
        i += 2;
      }else{
        i++;
      }
    }
  }
  void read_button(){

    if(digitalRead(closepin)){
      _state |= close;
      // sche.or_state(Schedule::close);
    }else if(digitalRead(openpin)){
      _state |= open;
      // sche.or_state(Schedule::open);
    }else{

    }
  }

};

#endif
