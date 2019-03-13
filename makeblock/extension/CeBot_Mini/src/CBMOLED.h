#ifndef CBMOLED_h
	#define CBMOLED_h
	
	#include <Arduino.h>
	#include <Wire.h>

	
#define OLED_ADDRESS	        	0x3C //gerekirse bu adresi degistirebilirsiniz  
#define OLED_COMMAND	            0x80
#define OLED_DATA	                0x40
#define OLED_DISPLAY_OFF	        0xAE
#define OLED_DISPLAY_ON	            0xAF
#define OLED_NORMAL_DISPLAY	    	0xA6
#define OLED_INVERSE_DISPLAY     	0xA7
#define OLED_SET_BRIGHTNESS	        0x81
#define OLED_SET_ADDRESSING	        0x20
#define OLED_HORIZONTAL_ADDRESSING	0x00 
#define OLED_VERTICAL_ADDRESSING	0x01
#define OLED_PAGE_ADDRESSING	    0x02 

#define OLED_SET_COLUMN             0x21
#define OLED_SET_PAGE	            0x22
	
	class CBMOLED
	{
	public:
		void begin(void);
		void cls(void);
		void show(void);
	private:

		void OLEDCommand(byte command) ;
		void OLEDData(byte data);	
		void fillScreen(byte value);
  
	};	
#endif