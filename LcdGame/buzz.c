// importing
#include <msp430.h>
#include "libTimer.h"
#include "buzz.h"

// constants to see if game over and who scored
int whoScored = 0;
int GameIsOver = 0;

// buzzInitialization of the buzzer
void buzzInitialization()
{
   
    timerAUpmode();	
    // it runs the speaker
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    // enables the speaker to have an output
    P2DIR = BIT6;		
}

void buzzSP(short cycles)
{
  CCR0 = cycles; 
  //it means a half of a cycle
  CCR1 = cycles >> 1;		
}

// its used to play a sound
void playSound(){

  static int Count = 0; //counter

  if(Count == 20){
    buzzSP(0);
    whoScored = 0;
    GameIsOver = 0;
    Count = 0;
  }
  else{
    if(GameIsOver){
      buzzSP(1000);
    }
    else if(whoScored){
      buzzSP(7000);
    }
  }

  Count++;
}
