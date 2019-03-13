//#include <CeBot_Mini.h>
#include "CeBot_Mini.h"


	CBMRGBLed CeBot_Led(13);
	CBMOLED display;

	uint8_t _multitask_SQ;	
	

//acilista yurutulecek otomatik calisan fonksiyondur
void initVariant(void){
	CBMini_init();
}

void CMultitask(void){
}


void CBMini_init(void)
{
	pinMode(PIN_LED,OUTPUT);
	Serial.begin(BAUD_RATE);
	while (!Serial) { ; } //Seri baglantiyi bekle
	
	
	CeBot_Led.setColor(0,255,255,255);
    CeBot_Led.show();
	
	
	Wire.begin();
	Wire.setClock(400000);//100000 (standard mode),400000 (fast mode).10000 (low speed mode), 1000000 fast plus,3400000 (high speed mode),
	//delay(500);
	display.begin();
	display.show();
	/*
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.display();
	display.clearDisplay();
	*/
	_multitask_SQ=0;
	
}
/*oled fonksiyonlari*/
void CBM_OledInit(){


}


/*motor fonksiyonlari*/
void CBM_Move(){
}
void CBM_DCMotorStop(void){
	
}


/*pixel led fonksiyonlari*/
void CBMini_PixelInit(void){
	CeBot_Led.setColor(0,0,0,0);
	CeBot_Led.show();
}
void CBMini_PixelSet(uint8_t index, uint8_t red, uint8_t green, uint8_t blue){
	CeBot_Led.setColor(index,red,green,blue);
	CeBot_Led.show();
}
void CBMini_PixelShow(void){
	CeBot_Led.show();
}

/*oled*/
void CBMini_DisplayInit(void){

}
void CBMini_DisplayClear(void){

}


