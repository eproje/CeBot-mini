//#include <CeBot_Mini.h>
#include "CeBot_Mini.h"


	CBMRGBLed CeBot_Led(13);
	CBMOLED display;
	//CBMDCMOTOR M1;
	//CBMDCMOTOR M2;

	uint8_t _multitask_SQ;	
	uint8_t Keyb_Data;
	

//acilista yurutulecek otomatik calisan fonksiyondur
void initVariant(void){
	CBMini_init();
}

void CMultitask(void){
}


void CBMini_init(void)
{
	pinMode(PIN_LED,OUTPUT);
	Serial.begin(CBM_BAUD_RATE);
	
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


void CBMini_DCMotorRun(int motorID,int pwmVal )
{
	bool dir=0;
	pinMode(PIN_M1DIR,OUTPUT);
	pinMode(PIN_M2DIR,OUTPUT);

	if (pwmVal<0){
		pwmVal=pwmVal * -1;
		dir=0;
	}else{
		dir=1;
	}

	if (pwmVal>250){pwmVal=250;}

	switch (motorID)
	{
	case 1:
		digitalWrite(PIN_M1DIR,dir);
		analogWrite(PIN_M1PWM,pwmVal);
	break;
	
	case 2:
		digitalWrite(PIN_M2DIR,dir - 1);
		analogWrite(PIN_M2PWM,pwmVal);
	break;
	
	default:
		digitalWrite(PIN_M1DIR,dir);
		analogWrite(PIN_M1PWM,pwmVal);

		digitalWrite(PIN_M2DIR,dir - 1);
		analogWrite(PIN_M2PWM,pwmVal);
	break;
	}
}

void CBMini_DCMotorStop(void){
	
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

/*mesafe olcer*/
/* mm olarak mesafe bilgisini getirir*/
int CBMini_GetDistance(void){

}

//analog degerlere ait fonksiyonlari*/
double CBMini_GetBatteryVoltage(void){

}

double CBMini_GetTemperature(void){

}

bool CBMini_GetButtonPressed(int index){

}

byte CBMini_GetButton(void){

}
