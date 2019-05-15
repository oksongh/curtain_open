#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "curtain"; // SSID
const char pass[] = "carteneropen";  // password
const int localPort = 8000;      // ポート番号

const IPAddress ip(192, 168, 4, 1);       // IPアドレス(ゲートウェイも兼ねる)
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

WiFiUdp udp;

void setup_wifi(){
  udp.begin(ip, localPort);
}

#endif
