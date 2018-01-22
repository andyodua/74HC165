#include "SHIFT_74HC165.h"

void setup() {
  DDRB = ( 1 << PB1);
  PORTB |= ( 1 << PB1);
  SHIFT_165_INIT(); // init
}

void loop() {
  SHIFT_165_All(); //read all data from register
  // When (74HC165) the contacts 14 and 11 connect to ground  
  // then on the controller pin PB1 in the high
  if ((SHIFT_165_DATA[0] == 0) & (SHIFT_165_DATA[3] == 0) ) { 
    PORTB &= ~( 1 << PB1);
  } else {
    PORTB |= ( 1 << PB1);
  }
}
