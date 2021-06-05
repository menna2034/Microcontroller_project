#ifndef uart7
#define uart7
#include "macros.h"
#include "systick_timer.h"
void UART7_init(uint32 baudrate,uint8 frame);
void UART7_Trans_char(uint8 data);
void UART7_Trans_string(char *data);
uint8 UART7_Recieve_char();
//char* UART7_Revieve_string(char* data);
#endif