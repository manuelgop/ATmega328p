#include <90USB1286.h>
#include <stdio.h>
#include <delay.h>



int i;
void main(){
DDRB.7=1;

TCCR0A=0x81;
TCCR0B=0x01;
TCNT0=0x00;
OCR0A=0;
OCR0B=0x00;

while(1){
    
    for(i=0;i<255;i++){
        OCR0A=i;
        delay_ms(5);
    }                
    for(i=255;i>0;i--){
             OCR0A=i;
            delay_ms(5);
        }
}



}
