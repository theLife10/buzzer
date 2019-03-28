#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
char switch_state_down, switch_state_changed,speed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down SWITCHES*/
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up ~SWITCHES*/
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/*SWITCHES enables resistors for switches */
  P2IE = SWITCHES;		/* SWITCHES enable interrupts from switches */
  P2OUT |= SWITCHES;		/* SWITCHES pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* ~SWITCHES set switches' bits for input */
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();


   if(!(p2val & SW1)){
	speed =18;
	 switch_one();
	switch_state_changed = 1;
  }
  else if(!(p2val & SW2)){
	speed =30;
	switchtwo();
	led_switch();
	switch_state_changed = 1;
  }
  else if ( ! (p2val & SW3) ) {
	speed = 100;
	switchthree();
	switch_state_changed = 1;

  }
  else if ( ! ( p2val & SW4 ) ) {
	speed = 200 ;
	switchfour();
	switch_state_changed = 1 ;

  }
}
