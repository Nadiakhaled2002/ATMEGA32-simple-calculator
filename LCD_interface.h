/*
 * LCD_interface.h
 *
 * Created: 10/3/2023 7:31:30 PM
 *  Author: nadia
 */


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */

#include "LCD_config.h"
#include "LCD_private.h"

/* Macros For LCD Line Id */
#define LCD_LINE_ONE            1
#define LCD_LINE_TWO            2

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT          1
#define LCD_SHIFT_RIGHT         2


void LCD_init                (void);
void LCD_sendCmnd            (u8 cmnd);
void LCD_sendChar            (u8 data);
void LCD_writeString         (u8*string);
void LCD_clear                (void);

void LCD_moveCursor(u8 line,u8 position);
void LCD_shiftDisplay(u8 direction);



#endif /* LCD_INTERFACE_H_ */
