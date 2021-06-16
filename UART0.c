#include "UART0.h"
void UART0_init(uint32 baudrate,uint8 frame){
	float br;
	SYSCTL_RCGCUART_R|=0x1; //clock connect to UART
	SYSCTL_RCGCGPIO_R|=0x01; //clock connect to port A
	while((SYSCTL_PRGPIO_R & 0x01)==0){} //
		
	UART0_CTL_R=0;

	GPIO_PORTA_LOCK_R=0x4C4F434B;
	GPIO_PORTA_CR_R|=0xFF; 
	GPIO_PORTA_DEN_R|=0x03;
	GPIO_PORTA_AMSEL_R&=~(0x03);
	GPIO_PORTA_AFSEL_R|=0x03;
	GPIO_PORTA_PCTL_R=0x11;

	UART0_IBRD_R=104;
	UART0_FBRD_R=11;
		
	UART0_CC_R=0;
	
	// to configure the frame 
	
	setbit(UART0_LCRH_R,4);
	if (5==frame){
	
		clrbit(UART0_LCRH_R,5);
		clrbit(UART0_LCRH_R,6);
	}
	else if(6==frame){
		setbit(UART0_LCRH_R,5);
		clrbit(UART0_LCRH_R,6);
	}
	else if(7==frame){
		clrbit(UART0_LCRH_R,5);
		setbit(UART0_LCRH_R,6);
	}
	else{
		setbit(UART0_LCRH_R,5);
		setbit(UART0_LCRH_R,6);
	}
	
	setbit(UART0_CTL_R,8);// to enable TX
	setbit(UART0_CTL_R,9);// to enable RX
	setbit(UART0_CTL_R,0);//to enable uart

}

void UART0_Trans_char(uint8 data){
	while (readbit(UART0_FR_R,5)==1){}
	UART0_DR_R=data;
}

void UART0_Trans_string(char *data){
	uint64 i=0;
	for(i=0;data[i]!=0;i++){
	while (readbit(UART0_FR_R,5)==1){}
	UART0_DR_R=data[i];
	}
}

uint8 UART0_Recieve_char(){
	while (readbit(UART0_FR_R,4)==0){}
	return (uint8) UART0_DR_R;
}

