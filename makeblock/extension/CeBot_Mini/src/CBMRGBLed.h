#ifndef CBMRGBLed_h
	#define CBMRGBLed_h
	
	#include <stdint.h>
	#include <stdbool.h>
	#include <Arduino.h>

	#define DEFAULT_LED_PIN  (13)
	#define DEFAULT_MAX_LED_NUMBER  (4)
	
	class CBMRGBLed
	{
	public:
		//CBMRGBLed(void);
		CBMRGBLed(int pin);
		//CBMRGBLed(int s1, int s2);
		void setNumber(uint8_t num_led);
		bool setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
		bool setColorAt(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
		void show();
		//~CBMRGBLed(void);

	private:
	
		int _pin;
		uint16_t count_led;
		uint8_t *pixels;
		uint8_t *pixels_bak;
		
		void rgbled_sendarray_mask(uint8_t *array, uint16_t length, uint8_t pinmask, uint8_t *port);
		const volatile uint8_t *ws2812_port;
		volatile uint8_t *ws2812_port_reg;
		uint8_t pinMask;
  
	};

#endif
