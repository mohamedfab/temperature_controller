/********************************************
 * LCD.c
 * Created: 12/10/2013 2:51:48 AM
 *  Author: mohamed fawzy
 *  Tester: mohamed fawzy
 ******************************************/ 
#include "myKit.h"
#include <util/delay.h>
#include "lcd.h"

static void enablePulse()
        {
	      LCD_CTRL_PORT|=(1<<EN);
	      _delay_us(1);
	      LCD_CTRL_PORT&=~(1<<EN);
	     _delay_ms(5);
       }
	   
void lcdWrite(unsigned char data)
{
	LCD_DATA_PORT=(LCD_DATA_PORT&0X0F)|(data&0xf0);
	enablePulse();
	_delay_ms(5);
	LCD_DATA_PORT=(LCD_DATA_PORT&0X0F)|(data<<4);
	enablePulse();
	_delay_ms(5);
}

void lcdCmd(unsigned char cmd)
{
	LCD_CTRL_PORT&=~(1<<RW);  //write mode
	LCD_CTRL_PORT&=~(1<<RS);  //cmd mode
	lcdWrite(cmd);
}


void lcdData(unsigned char data)
{
	LCD_CTRL_PORT&=~(1<<RW);  //write mode
	LCD_CTRL_PORT|=(1<<RS);  //cmd mode
	lcdWrite(data);
}

void lcdPuts(char *str)
{
	while(*str !='\0')
	{
		lcdData(*str++);
	}
}

void lcdGotoRowColumn(unsigned char row,unsigned char column)
   {
	column--;
	switch (row)
	   {
		case 1:
		      lcdCmd(0x80+column);
		      break;
		case 2:
		      lcdCmd(0xC0+column);
		      break;
		case 3:
		      lcdCmd(0x94+column);
		      break;
		case 4:
		      lcdCmd(0xD4+column);
		      break;
	   }
    }
	
void lcdInit()
{
	/*configure micro controller pins*/
	
	LCD_DATA_PORT_DIR|=0xF0;
	LCD_DATA_PORT&=0x0F;
	
	LCD_CTRL_PORT_DIR=(1<<RS)|(1<<RW)|(1<<EN);
	LCD_CTRL_PORT&=~((1<<RS)|(1<<RW)|(1<<EN));
	//LCD_DATA_PORT|=(1<<PINC3);
	
	
	MCUCSR = 0x80;
	MCUCSR = 0x80;

	/*initialize LCD*/
	_delay_ms(10);
	LCD_CTRL_PORT&=~(1<<RW);  //write mode
	LCD_CTRL_PORT&=~(1<<RS);  //cmd mode
	
	LCD_DATA_PORT|=(1<<PINA4);
	LCD_DATA_PORT|=(1<<PINA5);
	
	enablePulse();
	enablePulse();
	enablePulse();
	
	LCD_DATA_PORT&=~(1<<PINA4); //clear enable pin
	enablePulse();
	lcdCmd(0x28);
	lcdCmd(0x0F);    //display on cursor off
	lcdCmd(0xF0);
	lcdCmd(0x01);   //clear LCD
	lcdCmd(0x06);  //increment cursor (shift cursor to right)
}
