/*********************
   _74HC165.h
   andy.od.ua @ 2014
**********************/ 

#ifndef SHIFT_74HC165_H_

#define SHIFT_74HC165_H_

#define SHIFT_165_DDR DDRD
#define SHIFT_165_PORT PORTD
#define SHIFT_165_PIN PIND
#define SHIFT_165_LATCH  2	// latch
#define SHIFT_165_CLK 4	    // clock
#define SHIFT_165_DATA_IN 5	  // serial data in
// one 74HC165 "Serial Input" pin 10 connect to GND
// pin 15 "Clock Inhibit"	connect to	GND
// more chips	74HC165 pin 9 "Serial Output"	connect to "Serial Input" pin 10 and etc
#define SHIFT_165_NUM_CHIPS 1 // number chips

extern char SHIFT_165_DATA[SHIFT_165_NUM_CHIPS * 8];
extern int8_t SHIFT_165_NUM_BITS;

// initalizing
extern void SHIFT_165_INIT();

// read all bits from register
extern void SHIFT_165_All();

// read one bit
extern char SHIFT_165_BIT(int8_t bitNumber );

#endif
