/*
 * lab3pt1.c
 *
 * Created: 8/2/2018 12:33:05 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>
#define  button = A & 0x01;
#define  led1   = B & 0x01;
#define  led2   = B & 0x02;

enum States{start, s1, s2} state;

void tick(){
	switch(state){//transistion
		case start:
			state=s1;
			break;
		case s1:
			if((PINA & 0x01)==1){state=s2}
				else {state=s1;}
			break;
		case s2:
			if ((PINA & 0x01)){state=s1;}
				else{state=s2;}
			break;
		default:
			state=s1;		
	}//transistion
	switch (state){//action
		case s1:
			PORTB=0x01;
			break;
		case s2:
			PORTB=0x02;
			break;
		default:
			break;
	}
}


int main(void)
{
	DDRA=0x00; PORTA=0xFF;
	DDRB=0xFF; PORTB=0x00;
    while (1) 
    {
		tick();
		
    }
}

