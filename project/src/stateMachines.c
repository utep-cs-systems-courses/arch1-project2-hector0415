#include "util.h"

char state = 0;

void state_advance()
{
  switch(state)
    {
    case 1:
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
      state_four();
      led_update();
      break;
    }
}

void state_one()
{
  
}

void state_two()
{

}

void state_three()
{

}

void state_four()
{

}
