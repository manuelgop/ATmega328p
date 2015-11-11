/*
 * _8bitTimer.c
 *
 *  Author: SAM
 */
 
#include <stdio.h>
#include <90USB1286.h>
#include <delay.h>  

int extra=0;


interrupt [TIM0_COMPA] void timer0_compa_isr(void)
{

   extra++;
   if(extra>100){
        PORTC ^= (1 << PORTC7);
        extra=0;
        
   }

}

void main(){

DDRC.7=1;//LED DE SALIDA
TCCR0A=0x02;//modo CTC
TCCR0B=0x05;//1024 preescaling
OCR0A=19; //Numero e ticks para 0.01segundos
// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=0x02;



 #asm ("SEI")
while(1){
//  if(OCR0A==195){
//    extra++; 
//    PORTC.7=0;
//        if(extra>10){
//                PORTC.7=1;
//                extra=0;  
//                
//                
//        }
//  }
//}


}

}