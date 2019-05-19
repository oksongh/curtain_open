#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "keyword.h"

const char ssid[] = "curtain";
const char pass[] = "curtainopen";
const int localPort = 8000;
const IPAddress ip(192, 168, 4, 1);
const IPAddress subnet(255, 255, 255, 0);

class wifi_handler {
private:

  WiFiUDP udp;
  String msg;

public:
  void setup_wifi(){
    udp.begin(ip, localPort);
  }
  void setup_wifiAP(){
    WiFi.softAP(ssid, pass);
    // WiFi.softAP(ssid);
    delay(100);
    WiFi.softAPConfig(ip, ip, subnet);
  }

  String read_udp(){
    if(udp.parsePacket() > 0){

      msg = udp.readString();
      Serial.printf("\nmsg:%s\n",msg.c_str());
      return msg;
    }

    return str_none;
  }

};
#endif
