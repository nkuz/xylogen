#include <FastLED.h>
#include <Arduino.h>

#define NUM_LEDS 10
CRGBArray<NUM_LEDS> leds;
int Brightness = 5;
int fadeAmount = 5;


void setup()
{
  FastLED.setBrightness(50);
  FastLED.addLeds<NEOPIXEL, 3>(leds, 10);
 
}


void motion()
{
  for (int i = 0; i< NUM_LEDS; i++)
  {
    leds[i]= CRGB::White;
    FastLED.show();
    delay(15);
    leds[i] = CRGB::Black;
    FastLED.show();
  }

}

void fade()
{
  fill_solid( &(leds[0]), NUM_LEDS, CHSV( 0, 0, 255) );
FastLED.show();

for (int i =0; i<45; i++)
{
 Brightness = Brightness - fadeAmount;
    fill_solid( &(leds[0]), NUM_LEDS, CHSV( 0, 0, Brightness) );
    FastLED.show();
    delay(30);
}

    
}

void loop()
{
  motion();
  delay(400);
  fade();
  
 
}