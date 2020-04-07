#include "util.h"

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  static char blink_count = 0;

  if(state != 3)
    { 
      if (++blink_count == 125)
	{
	  state_advance();
	  blink_count = 0;
	}
    }
  else
    {
      if(++blink_count == 125)
	{
	  sm_slow_clock();
	  state_advance();
	  blink_count = 0;
	}
      sm_fast_clock();
      sm_update_led();
      led_update();
    }
}
