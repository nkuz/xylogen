
#include <FastLED.h>
#include <Arduino.h>

#define Light_NUM_LEDS 54
CRGBArray<Light_NUM_LEDS> leds;
int Light_Brightness = 5;
int fadeAmount = 5;


void setup()
{
  FastLED.setBrightness(255);
  FastLED.addLeds<NEOPIXEL, 3>(leds, Light_NUM_LEDS);
 
}


void motion()
{
  fill_solid( &(leds[0]), Light_NUM_LEDS, CHSV( 0, 0, 0) );

  for (int i = 0; i< Light_NUM_LEDS-3; i++)
  {
    leds[i]= CRGB::White;
    leds[i+1] = CRGB::White;
    leds[i+2] = CRGB:: White;
    leds[i+3] = CRGB::White;
    FastLED.show();
    delay(5);
    leds[i].setHSV(0,0,10);
    leds[i+1].setHSV(0,0,10);
    leds[i+2].setHSV(0,0,10);
    leds[i+3].setHSV(0,0,10);
    FastLED.show();
  }

}

void fade()
{
  fill_solid( &(leds[0]), Light_NUM_LEDS, CHSV( 0, 0, 255) );
FastLED.show();
for (int i =0; i<45; i++)
{
 Light_Brightness = Light_Brightness - fadeAmount;
    fill_solid( &(leds[0]), Light_NUM_LEDS, CHSV( 0, 0, Light_Brightness) );
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

