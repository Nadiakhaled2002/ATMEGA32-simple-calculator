/*
 * main.c
 *
 *  Created on: Jan 4, 2024
 *      Author: nadia
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"



int main(void)
{


KPD_init();
LCD_init();
u8 x=0;
u8 y=0;
u8 c=0;
u8 Key;
u8 r=0;
LCD_writeString("1 +,2 -,3 *,4 /");
LCD_moveCursor(1,25);
LCD_writeString("'*'for repeat ");
_delay_ms(5000);
LCD_clear();
LCD_moveCursor(0,0);
do{
	//setting the r=0 to stay in the do loop until r=*
	r=0;
	//while that does'nt end until the kpd is pressed
while(!x)
{
	kpd_getValue(&Key);
			if(Key!=KPD_NOT_PRESSED)
			{

				x=Key-48; //conerting the number from char to number

			}

		}
LCD_sendChar(x+48);
while(!c)
{




	kpd_getValue(&Key);
			if(Key!=KPD_NOT_PRESSED)
			{

				switch(Key) //switch case on key to figure the operation the user wants
				{
				case '1':
			        	{
			        		c='+';
			        		break;
			        	}
				case '2':
						{
							c='-';
							break;
						}
				case '3':
						{
							c='*';
							break;
						}
				case '4':
						{
							c='/';
							break;
						}
				}

			}

		}
LCD_sendChar(c);
//getting the second number
while(!y)
{




	kpd_getValue(&Key);
			if(Key!=KPD_NOT_PRESSED)
			{

				y=Key-48;

			}

		}
LCD_sendChar(y+48);
LCD_sendChar('=');
//performing the operation that the user choosed
switch(c)
{
case '+':
{
	s16 arr[100];
	s16 i=0;
	s16 j,r;
	s16 a=x+y;
	//separating the number to be able to send it as a char to the LCD
	if(a==0)
	 	{
	 		LCD_sendChar(a+48);
	 	}
	while(a!=0)
	{
		r=a%10;
		arr[i]=r;
		i++;
		a=a/10;
	 }
	// to be able to send the number we have to reverse the array as digits are stored in the array backwards
	for(j=i-1;j>-1;j--)
	{
	LCD_sendChar(arr[j]+48);
	}

	break;
}

 case '-':
 {
 	s16 arr[100];
 	s16 i=0;
 	s16 j,r;
 	s16 a=x-y;
 	if(a==0)
 	{
 		LCD_sendChar(a+48);
 	}
 	while(a!=0)
 	{
 		r=a%10;
 		arr[i]=r;
 		i++;
 		a=a/10;
 	 }
 	for(j=i-1;j>-1;j--)
 	{
 	LCD_sendChar(arr[j]+48);
 	}

 	break;
 }
   case '*':
   {
   	s16 arr[100];
   	s16 i=0;
   	s16 j,r;
   	s16 a=x*y;
   	if(a==0)
   	 	{
   	 		LCD_sendChar(a+48);
   	 	}
   	while(a!=0)
   	{
   		r=a%10;
   		arr[i]=r;
   		i++;
   		a=a/10;
   	 }
   	for(j=i-1;j>-1;j--)
   	{
   	LCD_sendChar(arr[j]+48);
   	}

   	break;
   }
   case '/':
      {
      	s16 arr[100];
      	s16 i=0;
      	s16 j,r;
      	s16 a=x/y;
      	if(a==0)
      	 	{
      	 		LCD_sendChar(a+48);
      	 	}
      	while(a!=0)
      	{
      		r=a%10;
      		arr[i]=r;
      		i++;
      		a=a/10;
      	 }
      	for(j=i-1;j>-1;j--)
      	{
      	LCD_sendChar(arr[j]+48);
}     	}

      	break;
      }
//if the user then pressed * then the loop will operate again until the user press any other char
while(!r)
{




	kpd_getValue(&Key);
			if(Key!=KPD_NOT_PRESSED)
			{

				r=Key;
				LCD_clear();
				if(r=='*')
				{

					LCD_sendChar(r);
					_delay_ms(5000);
//we have to reset all the variables to be able to get another numbers
					LCD_clear();
					x=0;
					y=0;
					c=0;


				}
				else
				{
					LCD_writeString("BYE");

				}

			}

		}
}while(r=='*');


}


