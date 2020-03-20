#include "util.h"

unsigned char red_on = 0, green_on = 0;
static char redVal[] = {0,LED_RED}, greenVal[] = {0,LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  char ledFlags = redVal[red_on] | greenVal[green_on];
  P1OUT &= (0xff^LEDS) | ledFlags;  //clear bit for leds that are off
  P1OUT |= ledFlags;  //set bits for on leds
    
  switch_state_changed = 0;
}
