# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I./h
LDFLAGS =./lib/libTimer.a -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as  

all: project.elf
	 (cd /home/student/beepy-blinky-toy-theLife10/project/timerLib; make install)
#additional rules for files
project.elf: ${COMMON_OBJECTS} bbmain.o switches.o led.o buzzer.o wdInterruptHandler.o  stateMachine.s
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@ 

load: project.elf
	mspdebug rf2500 "prog project.elf"

clean:
	(cd /home/student/beepy-blinky-toy-theLife10/project/timerLib; make clean)
	rm -f *.o *.elf
	rm -rf lib h


bbmain.o: buzzer.h led.h switches.h
led.o: led.h
buzzer.c: buzzer.h switches.h
wdInterruptHandler.o: buzzer.h led.h switches.h
switches.o: buzzer.h led.h switches.h
