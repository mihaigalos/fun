/*
 * attiny10_rgb.cpp
 *
 * Created: 5/6/2017 1:30:50 PM
 * Author : Mihai
 *
 * Drive an RGB LED using Attiny10.
 * Send desired color over software uart to the Attiny10.
 * 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h> // for memset()
#include <stdlib.h> // for atoi()

#include "SoftwareUart.h"
#include "Test_SoftwareUart.h"

volatile uint8_t pwmTickCount_ = 0;

volatile uint8_t r_intensity_=0;
volatile uint8_t g_intensity_=0;
volatile uint8_t b_intensity_=0;

uint8_t uart_buffer_[4];

inline void readUart(){
    for(uint8_t i = 0; i<sizeof(uart_buffer_); ++i){
        uart_buffer_[i] = uart_read();
    }     
}

void parseColor(volatile uint8_t& color){
    color = (uart_buffer_[1]-'0')*100+
            (uart_buffer_[2]-'0')*10+
            (uart_buffer_[3]-'0');
}

inline void parseUart(){
    // expecting format rRRR or gGGG or bBBB, or cXXX, where RRR, GGG, BBB = 3 decimal number for r,g,b values; X = any character
    
            if ('r' == uart_buffer_[0]) {
                parseColor(r_intensity_);
            }                
    else    if ('g' == uart_buffer_[0]) {
        parseColor(g_intensity_);
    }        
    else    if ('b' == uart_buffer_[0]) {
        parseColor(b_intensity_);
    }        
    else    if ('c' == uart_buffer_[0]) {
        r_intensity_ = 0; g_intensity_ =0; b_intensity_ = 0;
    }        
        
    memset(uart_buffer_, 0, sizeof(uart_buffer_));
}    

ISR(TIM0_COMPA_vect)
{
    
    if (pwmTickCount_ > g_intensity_) {
        PORTB |= (1 << PB0);
    }
    else {
        PORTB &= ~(1 << PB0);
    }
    if (pwmTickCount_ > r_intensity_) {
        PORTB |= (1 << PB1);
    }
    else {
        PORTB &= ~(1 << PB1);
    }
    if (pwmTickCount_ > b_intensity_) {
        PORTB |= (1 << PB2);
    }
    else {
        PORTB &= ~(1 << PB2);
    }
    
    pwmTickCount_++;

}

ISR(PCINT0_vect){
    if(0 == (PINB &(1<<RX_PIN))){
        readUart();
        parseUart();
    }
}

int main(void)
{	
	// Set CPU speed by setting clock prescaler:
	// CCP register must first be written with the correct signature - 0xD8
	CCP = 0xD8;
	//  CLKPS[3:0] sets the clock division factor
	CLKPSR = 0;


	// set up Output Compare A
	// WGM[3:0] is set to 0010
	// prescaler is set to clk/8 (010)
	TCCR0A = 0;
	TCCR0B = (1 << 1) | (1 << WGM02);
	// set Output Compare A value
	OCR0A = 39;
	// enable Output Compare A Match interrupt
	TIMSK0 |= (1 << OCIE0A);
	
	// enable interrupts
	
    uart_init();
    DDRB |= (1<<0) | (1<<1) | (1<<2);
    
	// enable interrupts
    PCICR = (1<<PCIE0);     // Pin Change Interrupt Enable 0 active, any change on any enabled PCINT[3:0] pin will cause an interrupt.
    PCMSK = (1<<RX_PIN);    // 
    sei();
    
    while (1) ;
    
}

