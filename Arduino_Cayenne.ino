/*  The Workhop - Arduino Cayenne Control V1.0 - February 2021
 *   
 *  This sketch will allow you to control the brightness of a LED 
 *  and read the temperature and humidity on your smartphone
 *  by using the Cayenne Web app.
 *  Cayenne is a web platform that allows you to control
 *  Arduino, Raspberry Pi and other IoT devices uisng MQTT protocol.
 *  You can easily build graphic interfaces for all your
 *  projects by simply adding new widgets.
 *  
 *  The CayenneMQTT Library is required to run this sketch. 
 *  If you have not already done so you can install it from the Arduino IDE Library Manager.
 *  
 *  The needed libraries for the DHT11 can be downloaded here: 
 *  - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
 *  - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
 *  See guide for details on sensor wiring and usage: 
 *  https://learn.adafruit.com/dht/overview
 *  
 *  Steps Recommended by Cayenne:
 *  1. Attach an analog input device (e.g. a potentiometer) to an analog pin on your Arduino. 
 *     Make sure to use an analog pin, not a digital pin.
 *  2. Set the SENSOR_PIN value below to the pin number you used when connecting the sensor.
 *  3. Set the VIRTUAL_CHANNEL value below to a free virtual channel 
 *     (or the virtual channel of an Generic Analog Input Sensor widget you have added) in the Dashboard.
 *  4. Set the Cayenne authentication info to match the authentication info from the Dashboard.
 *  5. Compile and upload this sketch.
 *  6. Once the Arduino connects to the Dashboard it should automatically create a temporary display widget 
 *     (or update the Generic Analog Input Sensor widget you have added) with data.   
 *  To make a temporary widget permanent click the plus sign on the widget.
 */

#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneMQTTEthernet.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "Get-Your-Username-From-The-Cayenne-Website";
char password[] = "Get-Your-Password-From-The-Cayenne-Website";
char clientID[] = "Get-Your-ClientID-From-The-Cayenne-Website";

#define VIRTUAL_CHANNEL_0 0
#define VIRTUAL_CHANNEL_1 1
#define VIRTUAL_CHANNEL_2 2
#define LEDPIN 8     // Digital pin connected to the LED
#define DHTPIN 9     // Digital pin connected to the DHT sensor 

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  //Initialize LED to be OFF
  digitalWrite(LEDPIN,LOW);
  dht.begin();
  Cayenne.begin(username, password, clientID);
}

void loop()
{
  Cayenne.loop();
}

CAYENNE_OUT(VIRTUAL_CHANNEL_0)      // This function is called at intervals to send sensor data to Cayenne.
{
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  Cayenne.virtualWrite(VIRTUAL_CHANNEL_0, t, "analog_sensor", "null");
}

CAYENNE_OUT(VIRTUAL_CHANNEL_1)      // This function is called at intervals to send sensor data to Cayenne.
{
  float h = dht.readHumidity();
  Cayenne.virtualWrite(VIRTUAL_CHANNEL_1, h, "analog_sensor", "null");
}

CAYENNE_IN(VIRTUAL_CHANNEL_2)      // This function is called when data is sent from Cayenne.
{
  int value = getValue.asInt(); // 0 to 255
  CAYENNE_LOG("Channel %d, pin %d, value %d", VIRTUAL_CHANNEL_2, LEDPIN, value);
  // Write the value received to the PWM pin. analogWrite accepts a value from 0 to 255.
  analogWrite(LEDPIN, value);
}
