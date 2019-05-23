#ifndef SCHDULE_H
#define SCHDULE_H

#include <Arduino.h>
// #include <time.h>
#include "keyword.h"
#include "pinassign.h"

class Schedule{
private:
  //bool is_reserve;
  const long init_time = 1000;

  static long _now_hour;
  static long _now_min;

  long _exetime_hour = init_time;//8
  long _exetime_min = init_time;//20

  uint8_t _state = 0;
  std::vector<String> _vecstr;

  long to_time(char c1,char c2);

  void split(String s);

  void set_time(const char* str,const int len);

  void set_now(const char* str,const int len);

public:
  static const uint8_t none =  0b00000;
  static const uint8_t close = 0b00001;
  static const uint8_t open =  0b00010;

  static std::vector<Schedule> tasks;

  uint8_t get_state(){
    return _state;
  }

  void parse(String msg){
    split(msg);
    for(String s:_vecstr){
      Serial.printf("_vecstr %s\n", s.c_str());
    }

    switch (_vecstr.size()) {
      case 1:

        if(_vecstr[0] == str_open){
          _state |= open;

        }else if(_vecstr[0] == str_close){
          _state |= close;

        }else{

        }

      case 2:

        if(_vecstr[0] == str_reserve){
          // etc 1220,0930,2310
          set_time(_vecstr[1].c_str(), _vecstr[1].length());

        }else if(_vecstr[0] == str_now){
          set_now(_vecstr[1].c_str(),_vecstr[1].length());

        }else{

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


  void add_task(){
    if(_exetime_min == init_time || _exetime_hour == init_time){
      _exetime_hour = _now_hour;
      _exetime_min = _now_min;
    }
    tasks.push_back(*this);
  }

  void serialprint();

};


#endif
