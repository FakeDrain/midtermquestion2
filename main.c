//#include "STM32F4xx.h"
//#include <stdlib.h>
#define RCCAHB1En *((int *)0x40023830)
#define GPIODmodreg *((int *)0x40020c00)
#define GPIODdatareg *((int *)0x40020c14)

//cem	99 101 109=309mod4=1
//deniz	100 101 110 105 122=538mod4=2 but I will not use for now
//erdogan	101 114 100 111 103 97 110=736mod4=0
//0 red, 1 blue, 2 orange and 3 is green

//My LEDs are all same color. So I will give location.
//Viewer sees the USB TTL entrance at left!
//GPIOD12=Green->Lower
//GPIOD13=Orange->Left
//GPIOD14=Red->Uppermost
//GPIOD15=Blue->Right

void init_leds(){
	RCCAHB1En=1<<3;
	GPIODmodreg= 1<<24 | 1<<26 | 1<<28 | 1<<30;
}
void turn_name_on(){
	GPIODdatareg=1<<15;
}
void turn_surname_on(){
	GPIODdatareg=1<<14;
}
void turn_surname_off(){
	GPIODdatareg=0<<14;
}
void turn_name_off(){
	GPIODdatareg=0<<15;
}
void delay(){
	int counter = 0;
	while (counter < 500000){
		++counter;
		}
}
int main(){
	init_leds();
	int n=0;
	int s=0;

	while (n < 3) {
	  turn_name_on();
	  delay();
	  turn_name_off();
	  delay();
	  n++;
	}
	while (s < 7) {
		  turn_surname_on();
		  delay();
		  turn_surname_off();
		  delay();
		  s++;
		}
	  //return 0;
}

