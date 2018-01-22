/*********************
   _74HC165.c
   andy.od.ua @ 2014
**********************/

#include <avr/io.h>
#include "SHIFT_74HC165.h"

char SHIFT_165_DATA[SHIFT_165_NUM_CHIPS * 8];
int8_t SHIFT_165_NUM_BITS = (SHIFT_165_NUM_CHIPS * 8) - 1;

// initalizing
void SHIFT_165_INIT() {
  SHIFT_165_DDR |= ( (1 << SHIFT_165_CLK) | (1 << SHIFT_165_LATCH) );
  SHIFT_165_PORT |= ( 1 << SHIFT_165_CLK);
}

void clock_function() {
  // Clock input
  SHIFT_165_PORT &= ~ ( 1 << SHIFT_165_CLK);
  SHIFT_165_PORT |= (1 << SHIFT_165_CLK);
}

void latch_function() {
  // When Low data is loaded from parallel inputs
  SHIFT_165_PORT &= ~ ( 1 << SHIFT_165_LATCH);
  SHIFT_165_PORT |= ( 1 << SHIFT_165_LATCH);
}

// read all bits from register
void SHIFT_165_All() {
  latch_function();
  // read bits
  for (int bit = SHIFT_165_NUM_BITS; bit > -1; bit--) {
    if ( ( SHIFT_165_PIN & ( 1 << SHIFT_165_DATA_IN) ) ) {
      SHIFT_165_DATA[bit] = 1;
    } else {
      SHIFT_165_DATA[bit] = 0;
    }
    clock_function();
  }
}

// read one bit
char SHIFT_165_BIT(int8_t bitNumber ) {
  char temp_bit = 0;
  latch_function();
  // read bit
  for (int bit = SHIFT_165_NUM_BITS; bit > (bitNumber - 1) ; bit--)  {
    if ( ( SHIFT_165_PIN & ( 1 << SHIFT_165_DATA_IN) ) ) {
      temp_bit = 1;
    } else {
      temp_bit = 0;
    }
    clock_function();
  }
  return temp_bit;
}
