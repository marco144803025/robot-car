#include <avr/io.h>
#include <avr/interrupt.h>
#define _BV(bit) (1 << (bit))
int state;
void T100ms()
{
	TCCR1A = 0;
	TCCR1B = 0x05;
	TCNT1H = 0xF9;
	TCNT1L = 0xE5;
	while ((TIFR1 & (1<<TOV1)) == 0);
	TCCR1B = 0;
	TIFR1 = (1<<TOV1);
}
ISR(TIMER0_COMPA_vect)
{
		T100ms();
		T100ms();
	char key='0';
	char oldkey='0';
	while(1){
		state=0;
		DDRB|= _BV(0);
		if(!(PIND&_BV(2)))	{
			key='1';//left up
			state=1;
			break;
		}
		if(!(PIND&_BV(3))){
			key='3';//right upxxxxxxxxxxxxxxxxxxx
			state=1;
			break;
		}
		DDRB &= ~_BV(0);
		DDRB|= _BV(1);
		if(!(PIND&_BV(2))){
			key='0';//left right
			state=1;
			break;
		}
		if(!(PIND&_BV(3))){
			key='4';//right rightxxxxxxxxxxxxxxxxxxxx
			state=1;
			break;
		}
		DDRB &= ~_BV(1);
		DDRB|= _BV(2);
		if(!(PIND&_BV(2))){
			key='2';//left bottom
			state=1;
			break;
		}
		if(!(PIND&_BV(3))){
			key='5';//right bottomxxxxxxxxxxxxxxxxxxxxxxxx
			state=1;
			break;
		}
		DDRB &= ~_BV(2);
		if(state==0){
			if(!(PIND&_BV(2))){
				key='6';//left left
				break;
			}
			if(!(PIND&_BV(3))){
				key='7';//right leftxxxxxxxxxxxxxxxxxxxxxxxxxx
				break;
			}
		}
	}
	UDR0=key;
}

int main(void)
{
	DDRB=0x07;
	DDRD=0x02;
	PORTD=0x0C;
	TCCR2A=0x00;
	TCCR0A=2;
	OCR0A=249;
	UBRR0=103;
	TIMSK0=2;
	TCCR0B=3;
	UCSR0B=_BV(TXEN0);
	sei();
	while(1);
}
