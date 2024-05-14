
#include <reg51.h>
#include <intrins.h>
#include <stdio.h>
#include <absacc.h>


void main(){
    TMOD=0x01;
    TH0=0xec;
    TL0=0x78;

    EA=1;
    ET0=1;
    TR0=1;

    i=100;
    count=8;
    P3=0xff;

    led=0xfe;
    P1=led;

    while(1){
    }
}

void timer0() interrupt 1{
    TH0=0xec;
    TL0=0x78;
    i--;

    if(i<=0){
        led=led<<1;
        led=led+1;
        P1=led;
        count--;

        if(count==0){
            led=0xfe;
            P1=led;
            count=8;
        }
        i=100;
    }
}