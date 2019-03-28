#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"
static unsigned int period = 1000;
static signed int rate = 200;	
static int switchonecounter = 0;
static int switchtwocounter = 0;
static int switchthreecounter = 0;
static int switchfourcounter = 0;
#define MIN_PERIOD 1000
#define MAX_PERIOD 4000

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

 //   buzzer_advance_frequency();	/* start buzzing!!! */
}

void buzzer_advance_frequency() 
{
  period += rate;
  if ((rate > 0 && (period > MAX_PERIOD)) || 
      (rate < 0 && (period < MIN_PERIOD))) {
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void switchone(){
	switch(switchonecounter){
		case 0:
		buzzer_set_period(40);
		switchonecounter++;
		break;
		case 1:
		buzzer_set_period(300);
		switchonecounter++;
		break;
		case 2:
		buzzer_set_period(100);
		switchonecounter++;
		break;
		case 3:
		buzzer_set_period(800);
		switchonecounter++;
		break;
		case 4:
		buzzer_set_period(50);
		switchonecounter ++;
		break;
		case 5:
		buzzer_set_period(900);
		switchonecounter=0;
		break;
	}
}

void switchtwo(){
	switch(switchtwocounter){
		case 0:
		buzzer_set_period(1000);
		switchtwocounter++;
		break;
		case 1:
		buzzer_set_period(40);
		switchtwocounter++;
		break;
		case 2:
		buzzer_set_period(500);
		switchtwocounter++;
		break;
		case 3:
		buzzer_set_period(2000);
		switchtwocounter++;
		break;
		case 4:
		buzzer_set_period(200);
		switchtwocounter++;
		break;
		case 5:
		buzzer_set_period(40);
		switchtwocounter = 0;
		break;

	}

}
void switchthree(){
	switch(switchthreecounter){
	case 0:
	buzzer_set_period(1000);
	switchthreecounter++;
	break;
	case 1:
	buzzer_set_period(3000);
	switchthreecounter++;
	break;
	case 2:
	buzzer_set_period(200);
	switchthreecounter++;
	break;
	case 3:
	buzzer_set_period(500);
	switchthreecounter++;
	break;
	case 4:
	buzzer_set_period(3000);
	switchthreecounter++;
	break;
	case 5:
	buzzer_set_period(1000);
	switchthreecounter = 0;
	break;

	}
}


void switchfour(){
		switch(switchfourcounter){
		case 0:
		buzzer_set_period(300);
		switchfourcounter ++;
		break;
		case 1:
		buzzer_set_period(600);
		switchfourcounter++;
		break;
		case 2:
		buzzer_set_period(5000);
		switchfourcounter++;
		break;
		case 3:
		buzzer_set_period(500);
		switchfourcounter++;
		break;
		case 4:
		buzzer_set_period(600);
		switchfourcounter ++;
		break;
		case 5:
		buzzer_set_period(300);
		switchfourcounter = 0;
		break;

		}
}
