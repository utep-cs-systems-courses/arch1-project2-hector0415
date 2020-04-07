#include "util.h"

#define c1 76
#define d1 68
#define e1 61  
#define f1 57
#define g 51
#define a 45
#define b 40
#define c2 38
#define d2 34
#define e2 30
#define f2 29
#define r 0

char state = 0;
int state_counter_two = 0;

void state_advance()
{
  switch(state)
    {
    case 1:
      buzzer_set_period(0);
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
  buzzer_set_period(a*200);
  red_on = 0;
  green_on = 0;
  state_counter_two = 1;
}

void state_two_one()
{
  buzzer_set_period(d2*200);
  red_on = 1;
  green_on = 0;
  state_counter_two = 2;
}

void state_two_two()
{
  buzzer_set_period(a*200);
  red_on = 0;
  green_on = 0;
  state_counter_two = 3;
}

void state_two_three()
{
  buzzer_set_period(g*200);
  red_on = 0;
  green_on = 1;
  state_counter_two = 0;
}
static int stc = 0;
void state_three()
{
  //dimming is done in wdInterruptHandler
  char notes [48] = {f1,f1,a,c2,a,f1,e1,r,d2,c2,r,r,e1,e1,g,b,g,e1,f1,r,d2,e2,r,r,f1,f1,a,c2,a,f1,e1,r,d2,c2,r,r,e1,e1,g,b,g,e1,f1,r,e2,f1,r,r};
  buzzer_set_period(notes[stc]*200);
  stc = (stc+1)%48;
  
}
static int sfc = 0;
void state_four()
{
  red_on = 1;
  green_on = 1;
  
  char notes [64] ={g,b,c2,d2,d2,d2,d2,d2,g,b,c2,d2,d2,d2,d2,d2,g,b,c2,d2,d2,b,b,g,g,b,b,a,a,a,a,a,b,b,a,g,g,g,g,b,b,d2,d2,d2,c2,c2,c2,c2,c2,b,c2,d2,d2,b,b,g,g,a,a,g,g,g,g,g};
  buzzer_set_period(notes[sfc]*200);
  sfc = (sfc+1)%64;
}

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
