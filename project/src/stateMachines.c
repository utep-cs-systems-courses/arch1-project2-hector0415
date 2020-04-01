#include "util.h"

char state = 0;
int state_counter_two = 0;

void state_advance()
{
  switch(state)
    {
    case 1:
      buzzer_set_period(2000);
      state_one();
      led_update();
      break;
      
    case 2:
      state_two();
      led_update();
      break;

    case 3:
      state_three();
      led_update();
      break;

    case 4:
      buzzer_set_period(1000);
      state_four();
      led_update();
      break;
    }
}
/*
void state_one()
{
  buzzer_set_period(1000);
  green_on = 0;
  red_on = 0;
}
*/

 /*
void state_two()
{
  switch(state_counter_two)
    {
    case 0:
      buzzer_set_period(2500);
      red_on = 0;
      green_on = 0;
      state_counter_two = 1;
      break;

    case 1:
      buzzer_set_period(3000);
      red_on = 1;
      green_on = 0;
      state_counter_two = 2;
      break;
      

    case 2:
      buzzer_set_period(2000);
      red_on = 0;
      green_on = 0;
      state_counter_two = 3;
      break;

    case 3:
      buzzer_set_period(3000);
      red_on = 0;
      green_on = 1;
      state_counter_two = 0;
      break;
      
    default:
    }
}
*/

void state_two_zero()
{
  buzzer_set_period(2500);
  red_on = 0;
  green_on = 0;
  state_counter_two = 1;
}

void state_two_one()
{
  buzzer_set_period(3000);
  red_on = 1;
  green_on = 0;
  state_counter_two = 2;
}

void state_two_two()
{
  buzzer_set_period(2000);
  red_on = 0;
  green_on = 0;
  state_counter_two = 3;
}

void state_two_three()
{
  buzzer_set_period(3000);
  red_on = 0;
  green_on = 1;
  state_counter_two = 0;
}

void state_three()
{
  //state three is performed in the wdInterrupter.
}
/*
void state_four()
{
  buzzer_set_period(4000);
  green_on = 1;
  red_on = 1;
}
*/
static enum {off=0,dim=1,bright=2} ledMode;
static char pwmCount = 0;

void sm_slow_clock()
{
  ledMode = 1;
}

void sm_fast_clock()
{
  pwmCount = (pwmCount + 1) & 3;
}

void sm_update_led()
{
  char new_red_on;
  char new_green_on;
  switch(ledMode)
    {
    case off:
      new_red_on = 0;
      break;

    case bright:
      new_red_on = 1;
      break;

    case dim:
      new_red_on = (pwmCount < 1);
      new_green_on = (pwmCount < 1);
      break;
    }
  if(red_on != new_red_on)
    {
      red_on = new_red_on;
      green_on = new_green_on;
      led_changed = 1;
    }
}
