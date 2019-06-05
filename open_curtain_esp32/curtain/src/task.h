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
  void check_time(State &state){
    unsigned long errhour = (millis() - stdmill)%(1000*60*60);
    unsigned long errmin = (millis() - stdmill)%(1000*60);
    Serial.printf("errhour %ld,errmin:%ld\n", errhour,errmin);

    if(errhour + standard_hm.hour > reserve_hm.hour){
      if(errmin + standard_hm.min > reserve_hm.min){
        state.state |= output_state.state;

      }
    }
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
  void set_std_time(String time){
    standard_hm.hour = time.substring(2).toInt();
    standard_hm.min = time.substring(2,4).toInt();
    stdmill = millis();

  }
  void set_reserve_time(String time){
    reserve_hm.hour = time.substring(2).toInt();
    reserve_hm.min = time.substring(2,4).toInt();

  }
  // virtual void set_output() = 0;

private:
  State output_state;
  Time_hm standard_hm;
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
