#include <PulseSensorPlayground.h>//pulse sens
#include <WiFi.h>
#include "ThingSpeak.h"
#include <DFRobot_MLX90614.h>
#include <Wire.h> 



const char* ssid = "VodafoneMobileWiFi-B53841";   //the internet
const char* password = "8387714391"; 

const int PulseWire = 34;  //intialising stuff for the pulse 
int Threshold = 550;
int myBPM = 0;

WiFiClient  client;
PulseSensorPlayground pulseSensor;  // Create PulseSensor object
DFRobot_MLX90614_I2C sensor;   // instantiate an object to drive our tempsensor

unsigned long myChannelNumber = 1;// API stuff for the thingSpeak
const char * myWriteAPIKey = "E84C1QVAEVVBPPPV";
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

// float PulseSensor= analogRead(34);// to read the results for the pulse sensor


void setup(){
Serial.begin(115200);  //Initialize serial
  pinMode(34,INPUT);

WiFi.mode(WIFI_STA);

ThingSpeak.begin(client);  // Initialize ThingSpeak 

// Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  Wire.begin();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  pulseSensor.analogInput(PulseWire);   
  pulseSensor.setThreshold(Threshold);   
  //pulseSensor.setSerialOutput(False);    // We'll print manually in loop

  if (pulseSensor.begin()) {
    Serial.println(" PulseSensor initialized successfully!");
  } else {
    Serial.println(" PulseSensor failed to initialize. Check wiring.");
  }

  // initialize the sensor for the temp
  while( NO_ERR != sensor.begin() ){
    Serial.println("Communication with device failed, please check connection");
    delay(3000);
  }
  Serial.println("Begin ok!");

  
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(500);     
      } 
      Serial.println("\nConnected.");
    }

    // set the fields with the values
    

// Check if a beat was detected
  if (pulseSensor.sawStartOfBeat()) {  
    myBPM = pulseSensor.getBeatsPerMinute();


      if (myBPM > 40 && myBPM < 180) {
        Serial.println("♥ Normal heartbeat detected!");
        Serial.print("BPM: ");
        Serial.println(myBPM);
      } else {
        Serial.println("⚠ Abnormal or noisy reading.");
        Serial.print("BPM: ");
        Serial.println(myBPM);
      }
    }
  delay(20);

  // Temperature readings
    float ambientTemp = sensor.getAmbientTempCelsius();
    float objectTemp  = sensor.getObjectTempCelsius();
    Serial.print("Ambient Celsius : ");
    Serial.print(ambientTemp);
    Serial.println(" °C");
    Serial.print("Object Celsius : ");
    Serial.print(objectTemp);
    Serial.println(" °C");

    
    ThingSpeak.setField(1,myBPM);
    ThingSpeak.setField(2, objectTemp);

    int x = ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
  
    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }

  



  Serial.println();
  delay(500);
}