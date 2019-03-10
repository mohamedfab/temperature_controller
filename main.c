/************************************
 * children_incubator.c
 * Created: 11/16/2018 9:40:32 PM
 * Author: Eng_Fawzy
 ************************************/ 

#include <avr/io.h>
#include "myKit.h"
#include <util/delay.h>
#include "lcd.h"
#include "adc.h"
#include "tempSensor.h"

#define FAN       PINC4
#define HEATER    PINB5

#define TURN_FAN_ON   (PORTC&=~(1<<FAN))
#define TURN_FAN_OFF   (PORTC|=(1<<FAN))

#define TURN_HEATER_ON   (PORTC&=~(1<<HEATER))
#define TURN_HEATER_OFF   (PORTC|=(1<<HEATER))

void actuatorsInit()
	{
	 DDRC|=(1<<FAN);
	 PORTC|=(1<<FAN);
	 DDRC|=(1<<HEATER);
	 PORTC|=(1<<HEATER);
	}

void displayFormat()
   {
	lcdCmd(_LCD_CURSOR_OFF);
	lcdGotoRowColumn(1,1);
	lcdPuts("Temp| ");
	lcdPuts("Fan | ");
	lcdPuts("Heat");
	lcdGotoRowColumn(2,5);
	lcdData('|');
	lcdGotoRowColumn(2,11);
	lcdData('|');
   }
int main(void)
{
	uint16_t temp;
	actuatorsInit();
	lcdInit();
	adcInit();
	displayFormat();
    while(1)
        {
         lcdGotoRowColumn(2,2);
		 temp=sensorTempRead();
		 lcdData(temp%1000/100+48);
		 lcdData(temp%1000%100/10+48);
		 lcdData(temp%1000%100%10+48);
		 
		 if (temp>=17&&temp<=20) 
			{
			 TURN_FAN_OFF;
			 TURN_HEATER_OFF;
			 lcdGotoRowColumn(2,7);
			 lcdPuts("OFF");
			 lcdGotoRowColumn(2,13);
			 lcdPuts("OFF");
			}
		 else if (temp>20)
		     {
		        TURN_FAN_ON;
				TURN_HEATER_OFF;
				lcdGotoRowColumn(2,7);
				lcdPuts("ON ");
				lcdGotoRowColumn(2,13);
				lcdPuts("OFF");
				   
			}
		else if (temp<20)
		   {  
			TURN_FAN_ON;
			TURN_HEATER_ON;
			lcdGotoRowColumn(2,7);
			lcdPuts("ON ");
			lcdGotoRowColumn(2,13);
			lcdPuts("ON ");
		   }	
		 
		 }
}