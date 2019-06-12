#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "constants/keyword.h"

// WiFiUDP udp;
class wifi_handler {
private:
  static const String ssid; //"curtain";

  static const String pass;//"curtainopen";
  static const int localPort;//8000;
  static const IPAddress ip;//(192, 168, 4, 1);
  static const IPAddress subnet;//(255, 255, 255, 0);
  static WiFiUDP udp;

public:
  static void setup_wifi(){
    udp.begin(ip, localPort);
  }

  static void setup_wifiAP(){
    WiFi.softAP(ssid.c_str(), pass.c_str());
    // WiFi.softAP(ssid);
    delay(100);
    WiFi.softAPConfig(ip, ip, subnet);
  }

  static String read_udp(){
    if(udp.parsePacket() > 0){

      String msg = udp.readString();
      Serial.printf("\nmsg:%s\n",msg.c_str());
      return msg;
    }

    return str_none;
  }

};
#endif
