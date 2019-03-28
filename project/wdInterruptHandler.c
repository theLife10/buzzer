#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "dim_light.h"

void decisecond() 
{
  static char cnt = 0;		/* # deciseconds/frequecy change */
  if (++cnt > 2) {
    cnt = 1;
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char second_count = 0, decisecond_count = 0;
  if (++second_count == 250) {
    second_count = 0;
  }
  if (++decisecond_count == speed) {
	  switch_interrupt_handler();
	  led_update();
	decisecond_count=0;
	}
}
