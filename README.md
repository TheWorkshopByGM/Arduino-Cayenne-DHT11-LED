# Arduino-Cayenne-DHT11-LED
This sketch will allow you to control the brightness of a LED and read the temperature and humidity on your smartphone by using the Cayenne Web app.

You will need to modify your USERNAME, PASSWORD, and CLIENTID in order to make the code worl. (You can get all these info from the Cayenne website)

Cayenne is a web platform that allows you to control Arduino, Raspberry Pi and other IoT devices uisng MQTT protocol.

You can easily build graphic interfaces for all your projects by simply adding new widgets.

The CayenneMQTT Library is required to run this sketch. 
If you have not already done so you can install it from the Arduino IDE Library Manager.

The needed libraries for the DHT11 can be downloaded here: 
- DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
- Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
See guide for details on sensor wiring and usage: https://learn.adafruit.com/dht/overview

Steps Recommended by Cayenne:
1. Attach an analog input device (e.g. a potentiometer) to an analog pin on your Arduino. Make sure to use an analog pin, not a digital pin.
2. Set the SENSOR_PIN value below to the pin number you used when connecting the sensor.
3. Set the VIRTUAL_CHANNEL value below to a free virtual channel (or the virtual channel of an Generic Analog Input Sensor widget you have added) in the Dashboard.
4. Set the Cayenne authentication info to match the authentication info from the Dashboard.
5. Compile and upload this sketch.
6. Once the Arduino connects to the Dashboard it should automatically create a temporary display widget (or update the Generic Analog Input Sensor widget you have added) with data.   
To make a temporary widget permanent click the plus sign on the widget.
