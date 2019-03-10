/*
 * tempSensor.c
 *
 * Created: 11/18/2018 10:43:18 AM
 *  Author: Eng_Fawzy
 */ 
#include <stdint.h>
#include "adc.h"
#include "tempSensor.h"

void sensorInit(void)
   {
	adcInit();
   }

double sensorTempRead()
	{
	   uint16_t adcResult;
	   double temp;
	   adcResult=adcRead(SENSOR_CHANEL);
	   temp=4.8*adcResult;
	   temp=temp/10;
	   return (uint16_t)temp;
    }