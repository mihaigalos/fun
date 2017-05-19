#ifndef __CONFIG_ATTINY10_RGB_H__
#define __CONFIG_ATTINY10_RGB_H__

#define RED_PIN PB1
#define GREEN_PIN PB0
#define BLUE_PIN PB2

#ifdef RX_PIN
    #undef RX_PIN
    #define RX_PIN PB3
#endif


#endif // __CONFIG_ATTINY10_RGB_H__