#ifndef TASK_H
#define TASK_H value

#include "state.h"
class task{
public:
  task() {
    output_state.state = State::none;
  }
  void loop(State &state){
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
  // virtual void set_output() = 0;

private:
  State output_state;


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
