#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    10
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB( 255, 255, 150);
    }

}

void loop() {
     uint8_t brightness = 255;
    while (brightness > 0) {
        for( int i = 0; i < NUM_LEDS; i++) {
            leds[i].setHSV(0, 0, brightness);
         }
         FastLED.show();
         FastLED.delay(10);
         brightness--;
    }
    brightness = 255;
    
}