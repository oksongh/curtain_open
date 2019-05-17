#ifndef ETC_H
#define ETC_H

void parse_exe(const String[] s){
  switch (s[0]) {
    case "open":
      state |= open;
    default:
      state |= none;
  }
}

const uint8_t none =  0b00000;
const uint8_t close = 0b00001;
const uint8_t open =  0b00010;

uint8_t button_read(uint8_t state){

  if(digitalRead(closepin)){
    state |= close;
  }else if(digitalRead(openpin)){
    state |= open;
  }
  return state;
}

#endif
