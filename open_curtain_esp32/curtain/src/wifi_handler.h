#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "curtain"; // SSID
const char pass[] = "carteneropen";  // password
const int localPort = 8000;      // ポート番号
const IPAddress ip(192, 168, 4, 1);       // IPアドレス(ゲートウェイも兼ねる)
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

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
  void read_udp(){
    if(udp.parsePacket() > 0){

      msg = udp.readString();
      Serial.printf("msg:%s",msg.c_str());
    }

  }

};
#endif
