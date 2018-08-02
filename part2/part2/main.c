/*
 * part2.c
 *
 * Created: 8/2/2018 1:05:40 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

enum States(Start, init,wait, decrement, increment, reset)state;
unsigned char number=0x00;
void tick(){
	)
		switch(state){//transistion
			case Start:
				state=init;
				break;
			case init:
				state=wait;
				break;
			case wait:
				if(PINA==1){state=increment;}
				else if (PINA==2){state=decrement;}
				else if (PINA==3){state=reset;}
				else {state=wait;}
				break;
			case decrement:
				state=wait;
				break;
			case increment:
				state=wait;
				break;
			case reset:
				state=wait;
				break;
			default:
				state=init;
				break;
			}//transition
	switch{//action
		case Start:
			break;
		case int:
			pc=7;
		case increment:
					if(PORTC<9){PORTC++;}
			break;
		case wait:
			break;
		case decrement:
			if(PORTC>1){PORTC--;}
			break;

		case reset:
			PORTC=0;
			break;
			
		default:
			break;
		}//action
	



int main(void)
{
	DDRA=0x00;	PORTA=0xFF;
	DDRB=0xFF;	PORTB=0x00;
	state=Start;
    while (1) 
    {
		tick();
    }
}

