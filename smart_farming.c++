#include "thingProperties.h"
#include <SimpleDHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D5
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;
int Sensor= A0;                      
int value= 0;
int pinDHT11 = D3;
SimpleDHT11 dht11(pinDHT11);
#define r D0
void setup() {
  pinMode(r,OUTPUT);
   sensors.begin();
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  sensor();
  // Your code here
 
 
}
void sensor(){
  Serial.print("MOISTURE LEVEL : ");
   value= analogRead(Sensor);
   value= value/10;
   Serial.println(value);
   sOIL_MOISTURE=value;
    sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.print(" C  ");
  tEMP_C=Celsius;
  Serial.print(Fahrenheit);
  Serial.println(" F");

  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
 
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print( "  IS TEMPARATURE  ");
  Serial.print((int)humidity); Serial.println("   IS HUMIDITY ");
  hUMIDITY=humidity;
  tEMPARATURE=temperature;
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}

