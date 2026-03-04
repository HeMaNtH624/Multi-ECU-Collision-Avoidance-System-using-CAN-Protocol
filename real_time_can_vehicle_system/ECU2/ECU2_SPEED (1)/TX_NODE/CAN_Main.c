#include<LPC21XX.H>
#include"CAN.H"
//#include"delay.h"
#include"SPEED.H"
#include"LCD_DISPLAY.H"

int main(){
	CAN2_MSG m1;
	int Speed;
	SPI_INIT(3);		//3 IS MODE '11'
	CAN2_INIT();
	LCD_INIT();
	
	m1.id = 0x00000150;
	m1.rtr = 0;	//data frame
	m1.dlc = 4;

	while(1){
		Speed=SPEED(READ(0));
		
		m1.byteA = Speed;
		m1.byteB = 0;

		CAN2_TX(m1);


		LCD_CMD(0X80);
		LCD_INTEGER(m1.byteA);
			
		delaymilisec(500);

		LCD_CMD(0X01);
	}
}
