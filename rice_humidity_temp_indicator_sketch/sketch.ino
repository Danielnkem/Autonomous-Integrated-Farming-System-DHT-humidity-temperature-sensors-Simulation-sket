// Autonomous Integrated Farming System: DHT humidity/temperature sensors Simulation sketch
// With indicators and Sensor Report
// Written by Daniel Nkemakolam
// Reference: "Example testing sketch for various DHT humidity/temperature sensors" - ladyada, public domain
long hrandNumber;
long trandNumber;
#include "DHT.h"


#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT22   // DHT 22 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);
const int highhthreshold = 70;
const int lowhthreshold = 49;
const int hightthreshold = 27;
const int lowtthreshold = 20;

void setup() {
  Serial.begin(38400); 
  Serial.println("rice_DHTxx simulation!");
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  int t = dht.readTemperature();

   // print a random number from 0 to 299
  hrandNumber = random(30, 74);


  // print a random number from 10 to 19
  trandNumber = random(10, 40);
  

  delay(500);

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
     Serial.println("*");
   Serial.println("*");
    Serial.print("Humidity: "); 
    Serial.print(hrandNumber);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(trandNumber);
    Serial.println(" *C");
    Serial.println(" --- REPORT ---");
  }

   if (hrandNumber > highhthreshold ) {
    Serial.println("--- Humidity WARNING! your attention required (Rice) ---");
   }

else if (hrandNumber <= lowhthreshold) { // 60 <= temperature < 70
  // Warning! User attention required.
 
  } 
  else {
    Serial.println("--- Humidity is Good (Rice) ---");
  } 

 if (trandNumber > hightthreshold ) {
    Serial.println("--- Temperature WARNING! your attention required (Rice) ---");
   }

else if (trandNumber <= lowtthreshold) 
{ // 60 <= temperature < 70
  // Warning! User attention required.

  } 
  else {
    Serial.println("--- Temperature is Good (Rice) ---");

  } 
 
}

