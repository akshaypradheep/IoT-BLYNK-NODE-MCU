#include <dht.h>
#define dht_dpin 14 
dht DHT;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int t;
int h;
char auth[] = "type your auth code here";
char ssid[] = "Name of your wifi";
char pass[] = "password of your wifi";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  DHT.read11(dht_dpin);
  h = DHT.humidity;
  t = DHT.temperature;
  Blynk.run();
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

