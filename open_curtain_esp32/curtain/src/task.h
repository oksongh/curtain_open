#ifndef TASK_H
#define TASK_H

#include <Arduino.h>
#include "state.h"
#include "time_hhmm.h"
class Task{
public:
  Task() {
    output_state.state = State::none;

  }
  void check_time(State &state){
    unsigned long now_ms = millis();
    // Serial.printf("millis %ld \n", millis());
    // Serial.printf("millis-std %ld \n", millis() - stdmill);

    unsigned long errhour = std::floor((double)( (now_ms - stdmill)/(unsigned long)(1000*60*60) ));
    unsigned long errmin = std::floor((double)( (now_ms - stdmill)/(unsigned long)(1000*60) ));
    // Serial.printf("errhour %ld,errmin:%ld\n", errhour,errmin);
    // Serial.printf("reservehour %d,reservemin:%d\n", reserve_hm.hour,reserve_hm.min);
    // Serial.printf("standard_hm hour %d,standard_hm min:%d\n", standard_hm.hour,standard_hm.min);

    if(errhour + standard_hm.hour >= reserve_hm.hour){
      if(errmin + standard_hm.min >= reserve_hm.min){
        state.state |= output_state.state;
        Serial.printf("changed by reserve\n");
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
    standard_hm.hour = (int)(time.substring(0,2).toInt());
    standard_hm.min = (int)(time.substring(2,4).toInt());
    stdmill = millis();
    Serial.printf("std hour %d min %d\n",standard_hm.hour ,standard_hm.min);

  }
  void set_reserve_time(String time){
    // Serial.printf("time.c %s \n",time.c_str());
    // Serial.printf("time.sub02 %s \n",time.substring(0,2).c_str());
    // Serial.printf("time.sub02.int %ld \n",time.substring(0,2).toInt());
    // Serial.printf("time.sub2 %d \n",time.substring(2).toInt());

    reserve_hm.hour = (int)(time.substring(0,2).toInt());
    reserve_hm.min = (int)(time.substring(2,4).toInt());
    Serial.printf("res hour %d min %d\n",reserve_hm.hour ,reserve_hm.min);


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
