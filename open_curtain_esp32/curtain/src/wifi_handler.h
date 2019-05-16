#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class wifi_handler {
private:
  const char ssid[] = "curtain"; // SSID
  const char pass[] = "carteneropen";  // password
  const int localPort = 8000;      // ポート番号

  const IPAddress ip(192, 168, 4, 1);       // IPアドレス(ゲートウェイも兼ねる)
  const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

  WiFiUdp udp;
public:
  void setup_wifi(){
    udp.begin(ip, localPort);
  }
  void setup_wifiAP();

  String read_udp();

  }
#endif
