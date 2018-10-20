#ifndef HaLakeM5StackLibrary_h 
#define HaLakeM5StackLibrary_h 

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <vector>

#include "./ChainArray.h"
#include "Utils.h"

#define TRY_CONNECT_AP 50
#define WEBSERVER_SERVICE_LIMIT 128

class HaLakeM5StackLibrary{
  private:
    struct ServiceObject{
      String uri;
      void (*callback)();
    };

    void sendGetResponse(WiFiClient *client, String html, String status);

    uint8_t service_amount = 0;
    ServiceObject services[WEBSERVER_SERVICE_LIMIT];
    Utils *utils = new  Utils();

  public:
    void begin(unsigned long serial_rate = 115200);
    bool connectWifi(char *ssid, char *pass);
    void webServer_addService(String uri, void (*callback)());
    void webServer_open();
    void webServer_requestHandle();
};

#endif