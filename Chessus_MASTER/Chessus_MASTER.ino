#include <FastLED.h>
#define LED     7
#define NUM_LEDS    50
CRGB leds[NUM_LEDS];

int obstaclePin = 5;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

int  decideCase;
long rRandom;
long gRandom;
long bRandom;

long rHelp;
long gHelp;

//set delay time here:
int rate = 71;


void setup() {
  FastLED.addLeds<WS2812, LED, GRB>(leds, NUM_LEDS);

  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);
  
  //Do not use pin A5 on the Arduino,it is occupied by this:
  randomSeed(analogRead(A5));
  
  
}
void loop() {
  

  
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
  { 
    Serial.println();
    Serial.println("≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠");
    Serial.println("Light up my CHEESO !!! ");

      //a random value to pick the colour
      decideCase = random(0, 5);

      //this determines which colour is picked by the random value of decideCase.
      // (switch is more or less the same as an if-statement)
      switch (decideCase) 
      {
      case 0:
        bRandom = random(170, 255);
        rRandom = random(0, 15);
        gRandom = random(0, 15);
        Serial.println("a shade of blue");
      break;
      
      case 1:
        bRandom = random(0, 15);
        rRandom = random(170, 255);
        gRandom = random(0, 15);
        Serial.println("a shade of red");
      break;

      case 2:
        bRandom = random(0, 15);
        rRandom = random(0, 15);
        gRandom = random(170, 255);
        Serial.println("a shade of green");
      break;

      case 3 :
        bRandom = random(0, 5);
        rRandom = random(170, 220);
        gRandom = (rRandom + random(-10, 10) ) * 0.5;
        Serial.println("a shade of yellow");
      break;

      case 4:
        bRandom = random(0, 256);
        rHelp   = 256 - bRandom; 
        rRandom = random(0, rHelp);
        gHelp   = bRandom + rRandom;
        gRandom = 256 - gHelp;
        Serial.println("a random mix");
      break;
      }
  

  Serial.print("B: ");
  Serial.println(bRandom);
  Serial.print("R: ");
  Serial.println(rRandom);
  Serial.print("G: ");
  Serial.println(gRandom);
  Serial.println();
  Serial.print("rate: ");
  Serial.println(rate);
  Serial.println("≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠≠");
  Serial.println();
  
//    
    
  for (int i = 0; i <= 49; i++) {

    //first step: light up the first 3 LEDs and turn them off again
    if (i == 0)
    {
      leds[i] = CRGB ( bRandom, rRandom, gRandom); FastLED.show(); delay(rate);
      leds[i] = CRGB::Black; FastLED.show();
    }
    
    //second step: light up the first 6 LEDs and turn them off again
    else if (i == 1) 
    {
      leds[i-1] = CRGB ( bRandom, rRandom, gRandom); FastLED.show();
      leds[i] = CRGB ( bRandom, rRandom, gRandom); FastLED.show(); delay(rate);
      leds[i-1] = CRGB::Black; FastLED.show();
      leds[i] = CRGB::Black; FastLED.show();
    }
    
    //all remaining steps: light up 6 LEDs at a time, turn them off again, 
    //advance one segment, repeat until 49 is reached
    else
    {
      leds[i] = CRGB ( bRandom, rRandom, gRandom); FastLED.show();
      leds[i+1] = CRGB ( bRandom, rRandom, gRandom); FastLED.show(); delay(rate);
      leds[i] = CRGB::Black; FastLED.show();
    }

    //increase rate of delay when 49 is reached
    //the rate increases by decreasing rate :))))))))
    if (i == 49 && rate > 1)
      {
      rate = rate - 10;
      }
  }
  
//  This didnt seem to do anything, so I commented it out:  
//  for (int i = 0; i <= 49; i++) {
//    leds[i] = CRGB ( 0, 0, 0); FastLED.show(); delay(20);
//  }
  }
  else
  {
    //reset delay rate to 71 when sensor doesn't sense anything
    rate = 71;
 
/*  for (int i = 0; i <= 49; i++) {
    leds[i] = CRGB ( 0, 0, 0);
    FastLED.show();
    delay(30);
  }
  for (int i = 49; i >= 0; i--) {
    leds[i] = CRGB ( 0, 0, 0);
    FastLED.show();
    delay(30);
  }
    */
}
}
