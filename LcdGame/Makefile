# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:gameStr.elf

#additional rules for files
gameStr.elf: ${COMMON_OBJECTS} gameStr.o buzz.o sizeOfHandler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle -lp2sw

load: gameStr.elf
	mspdebug rf2500 "prog $^"

clean:
	rm -f *.o *.elf
