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

  void parse(String msg);
  void read_button();
  void add_task();
  void serialprint();

};


#endif
