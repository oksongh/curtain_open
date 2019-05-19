#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "curtain";
const char pass[] = "carteneropen";
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
    delay(100);
    WiFi.softAPConfig(ip, ip, subnet);
  }

  String read_udp(){
    if(udp.parsePacket() > 0){

      msg = udp.readString();
      Serial.printf("msg:%s",msg.c_str());
      return msg;
    }
    return " ";
  }

};
#endif
