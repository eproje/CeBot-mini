#include "CBMOLED.h"
byte tetrisScreen[14][25] = { { 1 } ,{ 1 } };
byte pageArray[8] = { 0 };

void CBMOLED::begin(void){
	OLEDCommand(OLED_DISPLAY_OFF);
	delay(20);
	OLEDCommand(OLED_DISPLAY_ON);
	delay(20);
	OLEDCommand(OLED_NORMAL_DISPLAY);
	delay(20);
	OLEDCommand(0x8D);
	delay(20);
	OLEDCommand(0x14);
	delay(20);
	OLEDCommand(OLED_NORMAL_DISPLAY);
}
/*
CBMOLED::displayClear(void){
	
}
*/

void CBMOLED::cls(void){
	fillScreen(0);
}
void CBMOLED::fillScreen(byte value)
{
	for (int r = 1; r < 21; r++)
	{
		for (int c = 2; c < 12; c++)

		{
			tetrisScreen[c][r] = value;
		}
	}
}


void CBMOLED::show(void){
	OLEDCommand(OLED_SET_ADDRESSING);
	OLEDCommand(OLED_VERTICAL_ADDRESSING);


	OLEDCommand(OLED_SET_COLUMN);
	OLEDCommand(0);                //Set column start
	OLEDCommand(127);              //Set column end

	OLEDCommand(OLED_SET_PAGE);
	OLEDCommand(0);               //Set page start
	OLEDCommand(7);               //Set page end
	
	for (int r = 0; r < 128; r++) {

		for (int c = 0; c < 8; c++)
		{
			/*if (c == 0) OLEDData(1);//ust
			else if (c == 7) OLEDData(128);//alt
			else OLEDData(0);
			*/
			OLEDData(128);
		}

	}
}

// I2C 
void CBMOLED::OLEDCommand(byte command) {

	Wire.beginTransmission(OLED_ADDRESS);
	Wire.write(OLED_COMMAND);
	Wire.write(command);
	Wire.endTransmission();
	
}
void CBMOLED::OLEDData(byte data) {

	Wire.beginTransmission(OLED_ADDRESS);
	Wire.write(OLED_DATA);
	Wire.write(data);
	Wire.endTransmission();
}