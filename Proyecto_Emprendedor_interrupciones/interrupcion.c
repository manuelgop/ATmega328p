#include <mega328p.h>
#include <delay.h>

#define ADC_VREF_TYPE 0x60

// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}


// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
// Place your code here
  PORTB.0=1;
  delay_ms(3000);
  PORTB.0=0;

}

unsigned int valorpot=0;
void main(){

DDRB.0=1; //LED Y MOTOR
PORTD.2=1; //PULL-UP PB


// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Falling Edge
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-14: Off
// Interrupt on any change on pins PCINT16-23: Off
EICRA=0x02;
EIMSK=0x01;
EIFR=0x01;
PCICR=0x00;

DIDR0=0x00;
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x81;
ADCSRB&=0x7F;
ADCSRB|=0x80;

// Global enable interrupts
#asm("sei")

while(1){

valorpot = read_adc(0);
 
if(valorpot==254){
        PORTB.0=1;


}else{
    PORTB.0=0;
}


}
}