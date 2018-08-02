/*
 * part3.c
 *
 * Created: 8/2/2018 2:48:14 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>
enum States {Start, lock, fpress,spress, Unlock}state:
void tick(){
	switch (state){//transistion
		case Start:
			state=lock;
			break;
		
		case lock:
			if(PINA==0x04||PINA==0x02||PINA==0x01){state=fpress;}
			else {state=lock;}
			break;
			
		case fpress:
			if(PINA==0x04){state=spress;}
			else {state=fpress;}
			break;
						
			
		case spress:
			if(PINA==0x02){state=Unlock;}
			else {state=fpress;}
			break;
				
		case unlock:
			if(PINA==0x80){state=lock;}
			else {state=Unlock;}
			break;
		break;	
	
		default:
			state=lock;		
	}//transtion
	switch(state){
		case Start:
			PORTC=0;
		
		case lock:
			PORTB=PORTB& 0xFE;
			PORTC=1;
			break;
		case fpress:
			PORTC=2;
			break;
		case spress:
			PORTC=3;
			break;
		case Unlock:
			PORTB=PORTB&0x01;
			PORTC=4;
			
		default:
			break;
	}


int main(void)
{
	DDRA=0x00; PORTA=0xFF;
	DDRB=0xFF;	PORTB=0x00;
	DDRC=0xFF;	PORTC=0x00;
    while (1) 
    {
		tick();
    }
}

