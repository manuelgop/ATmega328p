#include <stdio.h>
#include <90USB1286.h>
#include <delay.h>  

int cliflag =0;

//// Timer 0 output compare A interrupt service routine
//interrupt [TIM0_COMPA] void timer0_compa_isr(void)
//{
//
//    PORTC ^= (1 << PORTC7); 
//
//}

interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here
     PORTC ^= (1 << PORTC7);
    cliflag=1;
    

}

void main(){
    DDRC.7=1;//LED SALIDA
    PORTD.0=1;//BOTON DE ENTRADA  con pullup
    
    EICRA=0x02;
    EIMSK=0x01;
    EIFR=0x01;
    PCICR=0x00;
//    
//    TCCR0A=0x02;//modo CTC
//    TCCR0B=0x05;//1024 preescaling
//    OCR0A=195; //Numero e ticks para 0.01segundos
    // Timer/Counter 0 Interrupt(s) initialization
    //TIMSK0=0x02;
         




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
        if(cliflag == 0){
                #asm ("SEI")
        }else{
             #asm ("CLI")
             delay_ms(750);
             cliflag=0;
        }  
}


}