#ifndef CeBotmini_H
#define CeBotmini_H
	#include <Arduino.h>
	
	#include "CBMRGBLed.h" //pixel led kutuphanesi
	#include "CBMOLED.h"//oled kutuphanesi
	
	
	
	//#include <Adafruit_GFX.h>
	//#include <Adafruit_SSD1306.h>
//	Adafruit_SSD1306 display(OLED_RESET);	
	/*pinler*/
	#define PIN_M1DIR 7
	#define PIN_M1PWM 6
	#define PIN_M1DIR 4
	#define PIN_M1PWM 5
	
	#define PIN_LED 13
	#define PIN_BUZZER 8
	/*seri port*/
	#define BAUD_RATE 115200

	
	
	//degiskenler
	
	
	/*fonksiyonlar*/
	/*main*/
	void CBMini_init(void);
	/*pixel led*/
	void CBMini_PixelInit(void);
	void CBMini_PixelSet(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
	void CBMini_PixelShow(void);
	/*oled*/
	void CBMini_DisplayInit(void);
	/*motor*/
	void CBM_DCMotorStop(void);

	
#endif //