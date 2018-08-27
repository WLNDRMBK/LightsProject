#include "FastLED.h"

// How many leds in your strip?
int NUM_LEDS 50;

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

bool Sensor1 = false;
bool Sensor2 = false;
bool Hit = false;
int i = 0, x1 = 0, x2 = NUM_LEDS;

void setup() { 
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  
  TestLed();
  delay(200);
}

void RunLed{
  bool s1 = false;
  bool s2 = false;
  if(s1 == true && Sensor1 == false) Sensor1 = true;
  if(s2 == true && Sensor2 == false) Sensor2 = true;

  if(!Hit){
    if(Sensor1){
      SetLed(x1,91, 159, 255);  
      if(x1<NUM_LEDS)x1++;
    }
    if(Sensor2){
      SetLed(x2,91, 159, 255);  
      if(x1<NUM_LEDS)x1++;
      if()
      else hit;
    }
    if(Sensor1 && Sensor 2){
     if() 
    }
  }
  else{
    
  }
  
  if(i<=NUM_LEDS/2)i++;
  else i = 0;
}

void TestLed(){
  SetLed(i,91, 159, 255);
  if(i != 0)RemoveLed(i-1);
  else RemoveLed(NUM_LEDS);
  
  if(i<=NUM_LEDS)i++;
  else i = 0;
}

//Blue is dead in 25
void SetLed(int nr, int r, int g, int b){
  g = (float)g/2;
  b = (float)b/2;
  leds[nr].r = b;
  leds[nr].g = r;
  leds[nr].b = g;
  FastLED.show();
}

void RemoveLed(int nr){
  leds[nr] = CRGB::Black;
}

