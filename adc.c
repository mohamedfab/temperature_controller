/*************************************
 * adc.c
 * Created: 11/17/2018 9:56:56 AM
 * Author: Eng_Fawzy
 *************************************/ 
#include <avr/io.h>
#include "adc.h"
#include "lcd.h"
void adcInit()
  {
	ADMUX|=(AVCC5V_REF<<6);
	ADCSRA=(ADC_ENABLE)|(ADCPS_128);
  }
  
uint16_t adcRead(uint8_t chnl)
  {
      uint16_t result;
	  ADMUX|=chnl;
	  ADCSRA|=(ADC_START_CONVERSION);
	  while(!(ADCSRA & (1<<ADIF)));
	  ADCSRA|=(1<<ADIF);	 
      result=(ADCL|(ADCH<<8));
	  return result;
	    
  }