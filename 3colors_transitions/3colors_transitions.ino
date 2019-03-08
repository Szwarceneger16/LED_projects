#include "FastLED.h"
 
#define NUM_LEDS 120
#define DATA_PIN 2
 
CRGB leds[NUM_LEDS];

int w = 0;

void hue_level(void) 
{ 
  float wa = (analogRead(A0)/1023.0)*100.0;
  Serial.println(wa);
  FastLED.setBrightness(wa);
  return; 
}

float color_type(void)
{
  float a = (analogRead(A1)/1023.0)*255.0;
  return a;
}
 
void setup() {
  
  Serial.begin(9600);
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}
 
void loop() {
    for(int i=0; i<3; i++){
        w = i%3;
        switch(w)
        {
        case 0:
            for(int k=0;k<NUM_LEDS;k++)
            {
            leds[k].setRGB(color_type(),255-color_type(),0);
            hue_level();
            FastLED.show();
             delay(8);
            }
          break;
       case 1:
            for(int k=0;k<NUM_LEDS;k++)
            {
            leds[k].setRGB(0,color_type(),255-color_type());
            hue_level();
            FastLED.show();
             delay(8);
            }
          break;
       case 2:
            for(int k=0;k<NUM_LEDS;k++)
            {
            leds[k].setRGB(255-color_type(),0,color_type());
            hue_level();
            FastLED.show();
            delay(8);
            }
          break;
        }
    }
}
