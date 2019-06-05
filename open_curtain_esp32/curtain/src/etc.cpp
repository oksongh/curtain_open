#include "etc.h"

void parse(const String command,State &state,Task &task){
// command :str_none,and so on
  State newState;
  std::vector<String> vecstr;

  split(command, vecstr);
  if(vecstr.size() == 0){
    return;
  }
  Serial.printf("size%d \n", vecstr.size());
  int i = 0;
  try{
    if (vecstr[i] == str_open){
      newState.state |= State::open;
      i++;

    }else if(vecstr[i] == str_close){
      newState.state |= State::close;
      i++;

    }else if(vecstr[i] == str_reserve){
      i++;

      if(vecstr[i] == str_open){
        task.open();
        i++;
      }else if(vecstr[i] == str_close){
        task.close();
        i++;
      }else if(vecstr[i] == str_buzzer){
        task.buzzer();
        i++;

      }else{
        i++;
      }

      if(vecstr[i] == str_set_std_time){
        i++;
        task.set_stdtime(vecstr[i]);
        i++;
      }
      if(vecstr[i] == str_set_reserve_time){
        i++;
        task.str_set_reserve_time(vecstr[i]);
        i++;
      }

    }else{
      // newState.state == State::none;

    }
  }catch(...){
    Serial.printf("int i:%d,vecsize:%d",i,vecstr.size());
  }
}

void read_button(State &state){
  bool isopen = digitalRead(open_button);
  bool isclose = digitalRead(close_button);
  if(isopen && isclose){
    state.state = State::none;
    return;
  }
  if(isclose){
    state.state = State::close;
  }else if(isopen){
    state.state = State::open;
    Serial.println("open");
  }else{
  }
}

void split(String s,std::vector<String> &vecstr){
  if(s.length() == 0){
    return;
  }
  s += char_split;
  for(int i = 0,prei = 0;i < s.length();i++){
    if(s[i] == char_split){
      vecstr.push_back(s.substring(prei, i));
      prei = i;
    }
  }

}

void motor_setup(){
  ledcSetup(channelA,motor_freq,motor_resol);
  ledcAttachPin(motorA, channelA);

  ledcAttachPin(motorB, channelB);
  ledcSetup(channelB,motor_freq,motor_resol);

}
void output(State state) {
  float delaytime = 0;

  if((state.state & State::open) != 0){
    open_curtain();
  }
  if((state.state & State::close) != 0){
    close_curtain();
  }
}
void open_curtain(){
  ledcWrite(channelA,200);
  ledcWrite(channelB,200);

  delay(opentime_ms);

  ledcWrite(channelA,neutral_output);
  ledcWrite(channelB,neutral_output);
}

void close_curtain(){
  ledcWrite(channelA,0);
  ledcWrite(channelB,0);

  delay(closetime_ms);

  ledcWrite(channelA,neutral_output);
  ledcWrite(channelB,neutral_output);

}
