#include "etc.h"

void parse(const String command,State &state,Task &task){
// command :str_none,and so on

  std::vector<String> vecstr;

  split(command, vecstr);
  if(vecstr.size() == 0){
    Serial.printf("size%d \n", vecstr.size());
    return;
  }
  for(String s:vecstr){
    Serial.printf("data:%s\n",s.c_str());
  }
  Serial.printf("size%d \n", vecstr.size());
  int i = 0;
  // Serial.printf("%s\n", (str_reserve+" "+str_open+" "+str_set_std_time+" "+str_set_reserve_time).c_str());
  try{
    if (vecstr[i] == str_open){
      state.state |= State::open;

      i++;

    }else if(vecstr[i] == str_close){
      state.state |= State::close;
      i++;

    }else if(vecstr[i] == str_reserve){
      i++;
      Serial.printf("reserve\n");
      if(vecstr[i] == str_open){
        task.open();
        Serial.printf("open\n");

        i++;
      }else if(vecstr[i] == str_close){
        task.close();
        i++;
      }else if(vecstr[i] == str_buzzer){
        task.buzzer();
        i++;

      }else{
        i++;
        Serial.printf("else\n");

      }

      if(vecstr[i] == str_set_std_time){
        Serial.printf("std\n");
        i++;
        task.set_std_time(vecstr[i]);
        i++;

      }
      if(vecstr[i] == str_set_reserve_time){
        Serial.printf("reservetime\n");
        i++;
        task.set_reserve_time(vecstr[i]);
        i++;
      }

    }else{


    }
    Serial.printf("i:%d \n", i);

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
    Serial.println("close");

  }else if(isopen){
    state.state = State::open;
    Serial.println("open");
  }else{
  }
}

void split(const String s,std::vector<String> &vecstr){
  if(s.length() == 0){
    return;
  }
  int end,start;
  for(end = 0,start = 0;end < s.length();end++){
    if(s[end] == char_split){
      vecstr.push_back(s.substring(start, end));
      start = end + 1;
    }
  }
  // add last element
  vecstr.push_back(s.substring(start,end));

}

void motor_setup(){
  ledcSetup(channelA,motor_freq,motor_resol);
  ledcAttachPin(motorA, channelA);

  ledcAttachPin(motorB, channelB);
  ledcSetup(channelB,motor_freq,motor_resol);

}
void output(State state) {

  if((state.state & State::open) != 0){
    Serial.println("open in the output!");
    open_curtain();
  }
  if((state.state & State::close) != 0){
    close_curtain();
  }
}
void open_curtain(){
  ledcWrite(channelA,30000);
  ledcWrite(channelB,0);

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
