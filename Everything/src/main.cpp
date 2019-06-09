#include <Arduino.h>
#include <FastLED.h>
#include <waterfall.h>
#include <turtle.h>
#include <iceberg.h>
#include <lightning.h>

void setup()
{

}

void loop()
{
 if(isTurtle == true)
 {
   //turtle setup
   delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    Turtle_currentPalette = RainbowColors_p;
    Turtle_currentBlending = LINEARBLEND;
   turtle();
 } 
 else if (isLightning == true)
 {
   //lightning setup
   FastLED.setBrightness(255);
  FastLED.addLeds<NEOPIXEL, 3>(leds, Light_NUM_LEDS);
  lightning();
 }
else if(isIceberg == true)
{
  //Iceberg setup
  FastLED.addLeds<ICE_LED_TYPE, ICE_LED_PIN, ICE_COLOR_ORDER>(leds, ICE_NUM_LEDS).setCorrection( TypicalLEDStrip );
    for( int i = 0; i < ICE_NUM_LEDS; i++) {
        ICE_leds[i] = CRGB( 255, 255, 150);
    }
    iceberg();
}
else if (isWaterfall==true)
{
  //waterfall setup
  FastLED.addLeds<NEOPIXEL, 3>(leds, NUM_LEDS);
  currentPalette = Palette;
  currentBlending = LINEARBLEND;
  waterfall();
}

}