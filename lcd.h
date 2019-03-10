/*
 * LCD.h
 * Created: 12/10/2013 2:52:02 AM
 *  Author: mohamed fawzy
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define RS					     PINB1
#define RW						 PINB2
#define EN						 PINB3
#define LCD_DATA_PORT		     PORTA
#define LCD_DATA_PORT_DIR	     DDRA
#define LCD_CTRL_PORT		     PORTB
#define LCD_CTRL_PORT_DIR		 DDRB

typedef enum
	{
      _LCD_CLEAR=0x01,
      _LCD_CURSOR_OFF=0x0C,
      _LCD_CURSOR_ON=0x0F,
      _LCD_4BIT_MODE=0x28,
      _LCD_8BIT_MODE=0x38,
      _LCD_ON=0x0F,
      _LCD_CURSOR_UNDERLINE=0x0E,
      _LCD_CURSOR_SHIFT_LEFT=0x10,
      _LCD_CURSOR_SHIFT_RIGHT=0x14,
      _LCD_CURSOR_INCREMENT=0x06
	}lcdCmd_t;

void lcdWrite(unsigned char data);
void lcdCmd(unsigned char cmd);
void lcdData(unsigned char data);
void lcdPuts(char *str);
void lcdGotoRowColumn(unsigned char row,unsigned char column);
void lcdInit();
#endif /* LCD_H_ */
