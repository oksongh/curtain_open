# include "outputs_manage.h"

void output(State state) {

  if((state.state & State::open) != 0){
    Serial.println("open in the output!");
    open_curtain();
  }
  if((state.state & State::close) != 0){
    Serial.println("close in the output!");
    close_curtain();
  }
}

void motor_setup(){
  ledcSetup(channelA,motor_freq,motor_resol);
  ledcAttachPin(motorA, channelA);

  ledcAttachPin(motorB, channelB);
  ledcSetup(channelB,motor_freq,motor_resol);

  // pinMode(motorA,OUTPUT);
  // pinMode(motorB,OUTPUT);

}

void open_curtain(){
  ledcWrite(channelA,30000);
  ledcWrite(channelB,0);

  delay(opentime_ms);

  ledcWrite(channelA,0);
  ledcWrite(channelB,0);
}

void close_curtain(){
  ledcWrite(channelA,0);
  ledcWrite(channelB,30000);

  delay(closetime_ms);

  ledcWrite(channelA,0);
  ledcWrite(channelB,0);

}
