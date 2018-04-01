
#include<avr/io.h>

#include <avr/interrupt.h>

void timer0_init (void);
void timer0_start(int prescale, int reg);
void timer0_rest(void);
void timer0_stop(void);
unsigned char timer0_get(void);
void timer1_inti(void);
void timer1_start(int prescale, int reg);

void timer1_stop(void);
int timer1_get(void);

