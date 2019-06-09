#include <Arduino.h>
#include <FastLED.h>

#define ICE_LED_PIN     3
#define ICE_NUM_LEDS    10
#define ICE_BRIGHTNESS  64
#define ICE_LED_TYPE    WS2812B
#define ICE_COLOR_ORDER GRB
CRGB leds[ICE_NUM_LEDS];

void setup() {
    FastLED.addLeds<ICE_LED_TYPE, ICE_LED_PIN, ICE_COLOR_ORDER>(leds, ICE_NUM_LEDS).setCorrection( TypicalLEDStrip );
    for( int i = 0; i < ICE_NUM_LEDS; i++) {
        leds[i] = CRGB( 255, 255, 150);
    }

}

void loop() {
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