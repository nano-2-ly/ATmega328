#include <avr/io.h>
#include <avr/interrupt.h>

int count = 0;
int state = 0;

ISR(TIMER0_OVF_vect){
	count ++ ;
	if (count == 32){
		count = 0;
		state = !state;
		if(state) PORTB = 0xFF;
		else PORTB = 0x00;
	}
}

int main(void){
	DDRB = 0x20;
	PORTB = 0x00;
	
	TCCR0B |= (1<<CS02) | (1<<CS00);
	
	TIMSK0 |= (1<<TOIE0);
	sei();
	
	while(1) {}
}