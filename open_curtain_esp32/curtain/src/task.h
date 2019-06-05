#ifndef TASK_H
#define TASK_H value

#include <Arduino.h>
#include "state.h"
#include "time_hhmm.h"
class Task{
public:
  Task() {
    output_state.state = State::none;

  }
  void check(State &state){
    unsigned long errhour = (millis() - stdmill)%(1000*60*60);
    unsigned long errmin = (millis() - stdmill)%(1000*60);
    if(){

    }
    state.state |= output_state.state;
  }
  void open(){
    output_state.state |= State::open;
  }
  void close(){
    output_state.state |= State::close;
  }
  void buzzer(){
    output_state.state |= State::buzzer;
  }
  void set_stdtime(String time){
    standard.hour = time.substring(2).toInt();
    standard.min = time.substring(2,4).toInt();
    stdmill = millis();

  }
  void set_reservetime(String time)
  // virtual void set_output() = 0;

private:
  State output_state;
  Time_hm standard;
  Time_hm reserve_hm;
  unsigned long stdmill;
};

// class open_buzzer : task_general{
// private:
//   void set_output() override{
//     task_general::open();
//     task_general::buzzer();
//
//   }
// };
//
// class open : task_general{
// private:
//   void set_output() override{
//     task_general::open();
//
//   }
// };
//
// class close_buzzer : task_general{
// private:
//   void set_output() override{
//     task_general::close();
//     task_general::buzzer();
//   }
// };
//
// class close : task_general{
// private:
//   void set_output() override{
//     task_general::close();
//
//   }
// };
#endif
