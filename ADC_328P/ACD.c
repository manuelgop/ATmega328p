#include <mega328p.h>
#include <stdio.h>
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

int valorVerde, valorRojo, valorAzul;
void main(){
DDRD.6=1;
DDRD.5=1;
DDRB.3=1;

//PWM 1 Y 2
TCCR0A=0xA1;
TCCR0B=0x09;
//TCCR0B=0x01;
TCNT0=0x00;
OCR0A=0;
OCR0B=0x00;

///para el PWM3
TCCR2A=0x81;
TCCR2B=0x01;
TCNT2=0;
OCR2A=0;
OCR2B=0;   



//// ADC initialization
//// ADC Clock frequency: 1000.000 kHz
//// ADC Voltage Reference: AVCC pin
//// ADC High Speed Mode: On
//// Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
//// ADC4: On, ADC5: On, ADC6: On, ADC7: On
//DIDR0=0x00;
//ADMUX=ADC_VREF_TYPE & 0xff;
//ADCSRA=0x81;
//ADCSRB&=0x7F;
//ADCSRB|=0x80;
//// ADC initialization
//    // ADC Clock frequency: 250.000 kHz
//    // ADC Voltage Reference: AREF pin
//    // ADC High Speed Mode: Off
//    // Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
//    // ADC4: On, ADC5: On, ADC6: On, ADC7: Off
//    DIDR0=0x80;
//    ADMUX=ADC_VREF_TYPE & 0xff;
//    ADCSRA=0x8B;
//    ADCSRB&=0x7F; 
//    
               // ADC initialization
// ADC Clock frequency: 1000.000 kHz
// ADC Voltage Reference: AVCC pin
// ADC High Speed Mode: On
// Only the 8 most significant bits of
// the AD conversion result are used
// Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
// ADC4: On, ADC5: On, ADC6: On, ADC7: On
//DIDR0=0x00;
//ADMUX=ADC_VREF_TYPE & 0xff;
//ADCSRA=0x82;

DIDR0=0x00;
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x81;
ADCSRB&=0x7F;
ADCSRB|=0x80;


while(1){
    
    valorVerde = read_adc(0);     
    OCR0A = valorVerde;
    
    valorRojo = read_adc(1);
    OCR0B = valorRojo;
    
    valorAzul= read_adc(2);
    OCR2A=valorAzul;
}



}
