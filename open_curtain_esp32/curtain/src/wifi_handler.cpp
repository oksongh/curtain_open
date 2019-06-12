#include "wifi_handler.h"

const String wifi_handler::ssid = "curtain";
const String wifi_handler::pass = "curtainpen";
const int wifi_handler::localPort = 8000;
const IPAddress wifi_handler::ip(192, 168, 4, 1);
const IPAddress wifi_handler::subnet(255, 255, 255, 0);
WiFiUDP wifi_handler::udp;
