/*

  MQTT Current Sensor Example for Arduino RP2040 Connect

  This example connects an Arduino RP2040 Connect to WiFi and MQTT to read an
  analog current sensor (INA169 from Adafruit) and publish its readings to an
  MQTT broker. It demonstrates how to establish WiFi and MQTT connections, read
  analog sensor data, and send it to an MQTT broker.

  Hardware Requirements:
  - Arduino RP2040 Connect board
  - Analog current sensor INA169 from Adafruit connected to pin A3 
    (use a simple voltage divider with two 10kOhm resistors)
  - A WiFi network with SSID and password provided in "secrets.h"
  - MQTT broker address and topic defined in the code

  Purpose:
  This setup is used to monitor the power consumption of the Arduino RP2040 Connect.
  The data is collected and stored in an InfluxDB database for analysis and monitoring.

  Created 5 October 2023
  by Spiridon Fotiadis

*/

#include <WiFiNINA.h>
#include <ArduinoMqttClient.h>

#include "secrets.h"

// Constants
const int SENSOR_PIN = 3;  // Input pin for measuring Vout
const int RS = 10;          // Shunt resistor value (in ohms)
const int VOLTAGE_REF = 3.3;  // Reference voltage for analog read
const float CURRENT_LSB = 0.04;

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "test.mosquitto.org";
int        port     = 1883;
const char topic[]  = "arduino_currents";

void setup() {
  Serial.begin(9600);
  wifiConnect();
  mqttConnect();
}

void loop() {
  mqttClient.poll();
  float current = readCurrent();
  sendCurrent(current);
  delay(1000);
}

void wifiConnect() {
  Serial.print("Connect to WIFI...");
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.println(".");
    delay(5000); // wait 5 seconds for retry
  }
  Serial.println("Connected to the network");
}

void mqttConnect() {
  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

float readCurrent() {
   // Read a value from the INA169 board
  float sensorValue = analogRead(SENSOR_PIN);

  // Remap the ADC value into a voltage number (5V reference)
  sensorValue = (sensorValue * VOLTAGE_REF) / 1023;

  // Follow the equation given by the INA169 datasheet to
  // determine the current flowing through RS. Assume RL = 10k
  // Is = (Vout x 1k) / (RS x RL)
  float current = sensorValue / CURRENT_LSB;

  // Output value (in amps) to the serial monitor to 3 decimal
  // places
  Serial.print(current, 3);
  Serial.println(" A");
  
  return current;
}

void sendCurrent(float current) {
    mqttClient.beginMessage(topic);
    mqttClient.print(current);
    mqttClient.endMessage();
}