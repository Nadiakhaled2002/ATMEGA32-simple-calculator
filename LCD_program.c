/*
 * LCD_program.c
 *
 *  Created on: Nov 21, 2023
 *      Author: nadia
 */
/*
 * LCD_program.c
 *
 * Created: 10/3/2023 7:31:20 PM
 *  Author: nadia
 */

#include "LCD_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>




void LCD_init(void)
{
	// Intialize LCD pins As OutPut Pins
	DIO_setPinDirection(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);

	_delay_ms(35);

	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	// set Rw pin = 0 (write)
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	private_writeHalfPort(0b0010);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	// Function Set command 2*16 LCD, 4 Bit Mode, 5*7 Font
	LCD_sendCmnd(0b00101000);
	_delay_us(45);

	// Display on off Control(DisplayOn, Cursor on, Blink on)
	LCD_sendCmnd(0b00001111);
	_delay_us(45);

	// Clear Display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);

	// Entry Mode(IncrementOn, ShiftOff)
	LCD_sendCmnd(0b00000110);
}


void LCD_sendCmnd(u8 cmnd)
{
	// set Rs pin = 0 (write command)
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);

	// set Rw pin = 0 (write)
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	// Write The Most 4 bits Of command on Data Pins
	private_writeHalfPort(cmnd>>4);

	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);

	// Write The Least 4 bits Of command on Data Pins
	private_writeHalfPort(cmnd);

	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
}


void LCD_sendChar(u8 data)
{
	// set Rs pin = 1 (write data)
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

	// set Rw pin = 0 (write)
	DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	// Write The Most 4 bits Of data on Data Pins
	private_writeHalfPort(data>>4);

	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);

	// Write The Least 4 bits Of data on Data Pins
	private_writeHalfPort(data);

	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
}




static void private_writeHalfPort(u8 value)
{
	DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(value,0));
	DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(value,1));
	DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(value,2));
	DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(value,3));
}

/*loop on string until it reaches
the null terminator and increment
the counter by one while sending
the lcd charecter by charecter*/

void LCD_writeString(u8*string)
{
	u8 counter =0;
while(string[counter]!='\0')
{
LCD_sendChar(string[counter]);
counter++;
}



}

void LCD_clear(void)
{

  LCD_sendCmnd(0b00000001);
  _delay_ms(2);
}
void LCD_moveCursor(u8 line,u8 position)
{
	if(line==1)
	{
		for(u8 i=0;i<position;i++)
		{
			LCD_sendCmnd(0b00010100);
			_delay_us(39);
		}

	}
if(line==2)
{
	for(u8 i=0;i<40;i++)
			{
				LCD_sendCmnd(0b00010100);
				_delay_us(39);
			}

	for(u8 i=0;i<position;i++)
			{
				LCD_sendCmnd(0b00010100);
				_delay_us(39);
			}


}


}
//1 for right and 0 for left
void LCD_shiftDisplay(u8 direction)
{
	if(direction==1)
	{
		LCD_sendCmnd(0b00011100);
		_delay_us(40);

	}
	if(direction==0)
		{
			LCD_sendCmnd(0b00011000);
			_delay_us(40);

		}

}























