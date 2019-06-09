#include <Arduino.h>
#include <FastLED.h>

#define ICE_LED_PIN     3
#define ICE_NUM_LEDS    10
#define ICE_BRIGHTNESS  64
#define ICE_LED_TYPE    WS2812B
#define ICE_COLOR_ORDER GRB
CRGB ICE_leds[ICE_NUM_LEDS];
bool isIceberg = false;



void iceberg() {
    while (isIceberg == true)
    {
uint8_t brightness = 255;
    while (brightness > 0) {
        for( int i = 0; i < ICE_NUM_LEDS; i++) {
            leds[i].setHSV(0, 0, brightness);
         }
         FastLED.show();    
         FastLED.delay(10);
         brightness--;
    }
    brightness = 255;
    }
     
    
}