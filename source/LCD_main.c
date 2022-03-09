/*
 * LCD_main.c
 *
 *  Created on: Jan 6, 2022
 *      Author: hanaa
 */

#include <util/delay.h>

#include "../include/LIB/bit.h"
#include "../include/LIB/types.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configuration.h"
#include <stdlib.h>

u8 man[8] = {

		 0x0E,
		  0x0E,
		  0x04,
		  0x0E,
		  0x15,
		  0x04,
		  0x0A,
		  0x11
};
u8 done[8] = {
0x0E,
0x0E,
0x15,
0x0E,
0x04,
0x04,
0x0A,
0x11
};
u8 kman[8] =
{
		 0x1C,
		  0x1C,
		  0x08,
		  0x0B,
		  0x0E,
		  0x08,
		  0x14,
		  0x14
};
u8 ball[8] = {
		 0x00,
		  0x00,
		  0x0E,
		  0x0E,
		  0x0E,
		  0x00,
		  0x00,
		  0x00
};
u8 ball2[8] = {
0x00,
 0x00,
 0x04,
 0x08,
 0x1F,
 0x08,
 0x04,
 0x00
};

u8 nkill[8] = {
		 0x11,
		  0x0A,
		  0x04,
		  0x04,
		  0x0E,
		  0x15,
		  0x0E,
		  0x0E
};
u8 kill[8] = {
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0x19,
  0x1E,
  0x19
};

void main(void)
{
	u8 i=2,j=2,k=1;
	MDIO_voidINIT();
	HLCD_voidInit();
	_delay_ms(20);
		HLCD_voidSendString("  WAR IS ON!");
		_delay_ms(10000);
	HLCD_voidSendSpecialCharacter(man, 0, LCD_u8_LINE2, 1);
	HLCD_voidSendSpecialCharacter(man, 0, LCD_u8_LINE1, 1);
	for(i = 2;i<16;i++)
	{
		_delay_ms(500);
		HLCD_voidClearDisplay();
		HLCD_voidSendSpecialCharacter(man, 0, LCD_u8_LINE2, i);
		HLCD_voidSendSpecialCharacter(man, 0, LCD_u8_LINE1, i);
		_delay_ms(500);
	}
	HLCD_voidClearDisplay();
	HLCD_voidSendSpecialCharacter(man,0,LCD_u8_LINE2,16);
	HLCD_voidSendSpecialCharacter(man,0,LCD_u8_LINE1,16);
	HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE2, 1);
	HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE1, 1);

	for(j = 2;j<16;j++)
		{
			_delay_ms(500);
			HLCD_voidSendSpecialCharacter(ball, 3, LCD_u8_LINE2, j);
			HLCD_voidSendSpecialCharacter(ball, 3, LCD_u8_LINE1, j);
			_delay_ms(500);
			HLCD_voidClearDisplay();
			HLCD_voidSendSpecialCharacter(man,0,LCD_u8_LINE2,16);
			HLCD_voidSendSpecialCharacter(man,0,LCD_u8_LINE1,16);
			HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE2, 1);
			HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE1, 1);
			_delay_ms(500);
		}
	HLCD_voidClearDisplay();
	_delay_ms(500);
	HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE2, 1);
	HLCD_voidSendSpecialCharacter(kman,1, LCD_u8_LINE1, 1);
	HLCD_voidSendSpecialCharacter(kill,2,LCD_u8_LINE2,16);
	HLCD_voidSendSpecialCharacter(kill,2,LCD_u8_LINE1,16);
	_delay_ms(10000);
	HLCD_voidClearDisplay();
	HLCD_voidSendString("  ALL KILLED");
	_delay_ms(10000);
	HLCD_voidClearDisplay();
	for(k=1;k<10;k++)
	{_delay_ms(500);
		HLCD_voidSendString("   CHAMPIONS! ");
		_delay_ms(500);
		HLCD_voidClearDisplay();
	}
	_delay_ms(10000);
	HLCD_voidClearDisplay();
	for(k=1;k<17;k++)
	{
		_delay_ms(500);
		HLCD_voidSendSpecialCharacter(done, 4, LCD_u8_LINE1, k);
		//_delay_ms(500);
		HLCD_voidSendSpecialCharacter(man, 4, LCD_u8_LINE1, k);
		_delay_ms(500);
		HLCD_voidSendSpecialCharacter(man, 4, LCD_u8_LINE2, k);
		//_delay_ms(500);
		HLCD_voidSendSpecialCharacter(done, 4, LCD_u8_LINE2, k);
		_delay_ms(500);
		//HLCD_voidClearDisplay();
	}
	while(1);

}


