/*************************************
 * adc.h
 * Created: 11/17/2018 9:57:07 AM
 * Author: Eng_Fawzy
 *************************************/ 

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
/*****************************ADCMUX definitions *****************************/
#define REF           ((uint8_t) 1<<6)
#define AVCC5V_REF    1
#define INTERNAL_REF  3 

#define ADC_LEFT_ADJUST_RESULT   ((uint8_t)1<<5)     //ADC left adjust result

/*****************************ADCSRA definitions *****************************/
#define ADC_ENABLE				 ((uint8_t)1<<7)     //ADC Enable
#define ADC_START_CONVERSION     ((uint8_t)1<<6)     //ADC start conversion
#define ADC_INTERRUPT_ENABLE     ((uint8_t)1<<3)     //ADC interrupt enable 
//ADC prescaler
//ADC frequancy must be between 50KHZ and 200KHZ
#define ADCPS_2         1
#define ADCPS_4         2
#define ADCPS_8         3
#define ADCPS_16        4
#define ADCPS_32        5
#define ADCPS_64        6
#define ADCPS_128       7

typedef enum
    {
	  CH0=0,
	  CH1=1,
	  CH2=2,
	  CH3=3,
	  CH4=4,
	  CH5=5,
	  CH6=6,
	  CH7=7
   }adcChanel_t;

void adcInit(void);
uint16_t adcRead(uint8_t);

#endif /* ADC_H_ */