#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#define MAX_SIZE 1000
char log_c[15];
char lat_c[15];
char in;
float logg[MAX_SIZE];
float lat[MAX_SIZE];
long int counter=0;
float distance=0;
char input;
int i=0;
int j=0;
char UART_RX(){
    scanf("%c",&in);
    return in;
}
void get_inputs(){
    while(1){
        input=UART_RX();
        if(input!='$')
            continue;
        input=UART_RX();
        if(input!='G')
            continue;
        input=UART_RX();
        if(input!='P')
            continue;
        input=UART_RX();
        if(input!='G')
            continue;
        input=UART_RX();
        if(input!='G')
            continue;
        input=UART_RX();
        if(input!='A')
            continue;
        input=UART_RX();
        if(input!=',')
            continue;
        input=UART_RX();
        while(input!=',')  // skip first no (time)
        {
            input=UART_RX();
        }
        input=UART_RX();
        for(i=0;input!=',';i++){
            lat_c[i]=input;
            input=UART_RX();
        }
        input=UART_RX();
        while(input!=',')
        {
            input=UART_RX();
        }
        input=UART_RX();
        for(j=0;input!=',';j++){
            log_c[j]=input;
            input=UART_RX();
        }
        break;
    }
    logg[counter]=(float)(atof(log_c));
    lat[counter]=(float)(atof(lat_c));
    logg[counter]=logg[counter]/100.00;
    lat[counter]=lat[counter]/100.00;
    counter++;

}


void get_distance(){
    float abs_log=0;
    float abs_lat=0;
    if(counter ==1){
        distance =0;
    }
    else{
    abs_log=abs(logg[counter-1])-abs(logg[counter-2]);
    abs_lat=abs(lat[counter-1])-abs(logg[counter-2]);
    distance+=(float)(sqrt(pow(abs_log,2)+pow(abs_lat,2)));
    }


}
int main()
{

}
