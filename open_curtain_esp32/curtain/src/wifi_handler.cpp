#include wifi_handler.h

void wifi_handler::setup_wifiAP(){
  WiFi.softAP(ssid, pass);
  delay(100);
  WiFi.softAPConfig(ip, ip, subnet);
}

String wifi_handler::read_udp(){
  if(int len = udp.parsePacket()){
    char buf[len];
    udp.read(buf,len);

  }

}
