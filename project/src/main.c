#include "util.h"
#include "libTimer.h"

int main()
{
  configureClocks();

  switch_init();
  led_init();
  buzzer_init();
  
  enableWDTInterrupts();
  
  or_sr(0x18); //CPU off, GIE on
}
