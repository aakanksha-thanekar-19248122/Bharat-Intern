#include <Wire.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "Write your SSID";
const char* password = "Write your password";

// Replace with your Thingspeak channel details
unsigned long channelID = 2132235;
const char* writeAPIKey = "WA192FIQUCHY1JDG";


WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  ThingSpeak.begin(client);}

void loop() {


float h = analogRead(0);


  Serial.print("Air Quality = ");
  Serial.print(h);
  Serial.println(" ppm");




  ThingSpeak.setField(1, h);


  int httpCode = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (httpCode == 200) {
    Serial.println("Data sent to Thingspeak");
  } else {
    Serial.println("Error sending data to Thingspeak");
  }

  delay(500); // Send data every 20 seconds
}