#include "F:/mpproject/zm_macros.h"
#include "F:/mpproject/systick_timer.h"
#include "F:/mpproject/ports.h"
#include "F:/mpproject/lcd.h"
#include "F:/mpproject/UART0.h"
#include "F:/mpproject/UART7.h"
#include "F:/mpproject/led.h"
void SystemInit(){}
	
int main(){
	uint8 distance=100;
	portB_init();
	lcd_init();
	lcd_comm(0x80);
	lcd_string("The Distance Is");
	lcd_comm(0xC0);
	lcd_num(15.5);
	while (1){
	is_distance_equal_100(distance);
	}
}

/*uint8 i=1;
	portF_init();
	while(1){
		for (i=1;i<4;i++){
			setbit(GPIO_PORTF_DATA_R,i);
			wait_ms(1000);
			clrbit(GPIO_PORTF_DATA_R,i);
		}
		for (i=1;i<4;i++){
			clrbit(GPIO_PORTF_DATA_R,i);
		}
	}*/

/*
portF_init();
	lcd_init();
	UART0_init(9600,8);
	UART7_init(9600,8);
	while(1){
	wait_ms(1000);
	lcd_char('z');
	lcd_string("manga");
	uint8 c=UART7_Recieve_char();
	UART0_Trans_char('g');
	UART0_Trans_string("hello");
	}
*/
	/*
		//lcd_char('c');
		//lcd_char('A');
		uint8 i=0;
		for (i=0;i<60;i++){
		lcd_comm(0xC0);
		//lcd_num((16.5+15));
			lcd_num(i);
			wait_ms(1000);
		}*/
	