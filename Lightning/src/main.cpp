#include <FastLED.h>
#include <Arduino.h>

#define NUM_LEDS 10
CRGBArray<NUM_LEDS> leds;
int Brightness = 0;
int fadeAmount = 5;

void setup()
{
  FastLED.addLeds<NEOPIXEL, 3>(leds, NUM_LEDS);
  leds[0] = CRGB:: White;
  leds[1] = CRGB:: White;
  leds[2] = CRGB:: White;
  leds[3] = CRGB:: White;
  leds[4] = CRGB:: White;

}

void pulsate()
{
  FastLED.setBrightness(Brightness);
  if(Brightness<0 || Brightness>255)
  {
    fadeAmount = -fadeAmount;
  }
  else 
  {
    Brightness += fadeAmount;
  }
  delay(80);
}

void flash()
{

}

void loop()
{
  pulsate();
  pulsate();
  delay(100);
 
}