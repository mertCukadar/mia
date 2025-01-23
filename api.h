#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#ifndef STASSID
#define STASSID "SUPERONLINE-WiFi_4987"
#define STAPSK "RMCHEV7NVKAF"
#endif

void run_server();