#include <FastLED.h>
#include <Arduino.h>

#define NUM_LEDS 50
int r = 193;
int g = 217;

CRGBArray<NUM_LEDS> leds;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
bool isWaterfall = false;

const TProgmemPalette16 Palette PROGMEM =
    {
        CRGB::Gray,
        CRGB::Aqua,
        CRGB::Cyan,
        CRGB::Blue,
        CRGB::Blue,
        CRGB::DarkBlue,
        CRGB::DarkBlue,
        CRGB::Black,
};


void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 50;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void waterfall()
{
  while(isWaterfall == true)
  {
static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors(startIndex);
    FastLED.show();
    FastLED.delay(10);
}
  }
  