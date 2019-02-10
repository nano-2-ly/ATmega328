#include <avr/io.h>
#define F_CPU 16000000L
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(PCINT2_vect){
	PORTB |= 0x00;
	_delay_ms(100);
	PORTB |= 0x20;
	
}

void INIT_PORT(void){
	DDRB = 0x20;
	PORTB = 0x00;
	
	DDRD = 0x00;
	PORTD = 0xFF;
}

void INIT_PCINT2(void){
	PCICR |= (1<<PCIE2);
	PCMSK2 |= 0xFF;
	//PCMSK2 |= (1<<PCINT18);
	sei();
}

int main(void){
	INIT_PORT();
	INIT_PCINT2();
	
	while(1){}
}