#include "FastLED.h"
 
#define NUM_LEDS 120
#define DATA_PIN 2
#define TWO_HUNDRED_PI 628
 
CRGB leds[NUM_LEDS];
 
int element = 0;
int last_element = 0;
 
void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

}
 
void loop() {
    for(int i=0; i<TWO_HUNDRED_PI; i++){
        element = round((NUM_LEDS-1)/2*(sin(i/100.0)+1));
        leds[element].g = 255;
        leds[element].r = 0;
        FastLED.show();
         
        delay(1);
         
        if(element < last_element){
            leds[element].g = 0;
            FastLED.show();
        }
         
        last_element = element;
    }
    for(int i=0; i<TWO_HUNDRED_PI; i++){
        element = round((NUM_LEDS-1)/2*(sin(i/100.0)+1));
        leds[element].g = 0;
        leds[element].r = 255;
        FastLED.show();
         
        delay(1);
         
        if(element < last_element){
            leds[element].g = 0;
            FastLED.show();
        }
         
        last_element = element;
    }
}
    
