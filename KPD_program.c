/*
 * KPD_program.c
 *
 *  Created on: Nov 23, 2023
 *      Author: nadia
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_init(void)
{
 DIO_setPinDirection(KPD_ROW0_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
 DIO_setPinDirection(KPD_ROW1_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
 DIO_setPinDirection(KPD_ROW2_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
 DIO_setPinDirection(KPD_ROW3_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);


  DIO_setPinDirection(KPD_COL0_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
  DIO_setPinDirection(KPD_COL1_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
  DIO_setPinDirection(KPD_COL2_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
  DIO_setPinDirection(KPD_COL3_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);

  DIO_activePinInPullUpResistance(KPD_ROW0_PORT,KPD_ROW0_PIN);
  DIO_activePinInPullUpResistance(KPD_ROW1_PORT,KPD_ROW1_PIN);
  DIO_activePinInPullUpResistance(KPD_ROW2_PORT,KPD_ROW2_PIN);
  DIO_activePinInPullUpResistance(KPD_ROW3_PORT,KPD_ROW3_PIN);

}









void kpd_getValue(u8 *k)
{
if(k != NULL)
{
	*k=KPD_NOT_PRESSED;
	u8 COLP[4]={KPD_COL0_PORT,KPD_COL1_PORT,KPD_COL2_PORT,KPD_COL3_PORT};
	u8 COLPIN[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 rowsPorts[4]={KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
	u8 rowsPins [4]={KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
	u8 kpdKeys[4][4] = KPD_KEYS;
	u8 colCount,rowCount;
	u8 pinValue;
	for(colCount=0;colCount<4;colCount++)
	{
		//activate each column
		DIO_setPinValue(COLP[colCount],COLPIN[colCount],DIO_PIN_LOW);
		for(rowCount=0;rowCount<4;rowCount++)
		{

		//read each row
			DIO_getPinValue(rowsPorts[rowCount],rowsPins[rowCount],&pinValue);
		//if pressed
			if(pinValue==0)
			{
				while(pinValue==0)
				{
					DIO_getPinValue(rowsPorts[rowCount],rowsPins[rowCount],&pinValue);
				}
				*k = kpdKeys[rowCount][colCount];

				return;//terminates the function


			}



		}
			//deactivate current column to acctivate the next one
			DIO_setPinValue(COLP[colCount],COLPIN[colCount],DIO_PIN_HIGH);
		}



}

else
{

}

}

