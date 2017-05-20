# Fun with an AtTiny10 : control a RGB led via Software UART

## Prerequisites

- breakout for AtTiny10, i.e. : hardware/TinyOne.
- RESET disabled in the fuse on the AtTiny10 (i.e. : 0xFE). Necessary since Reset pin used for uart, other pins used for the RGB
- make.exe in PATH
- avr-objcopy.exe in PATH
- environment variable Tiny10DescriptionFiles pointing to the AtTiny10 
base description files (i.e. : C:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.1.102)

## How to

### Build

Call **make all** from a bash / batch console to build. Call **make clean** to remove a previous build.

### Control

Hit up a terminal and send the tiny commands via an USB to UART adapter. The AtTiny10 speaks a custom-rolled implementation of UART, which can be found [here][1]. Default settings are 38400(bps)/8N1.

If you can read regex, here's what you can send: [rgbc]{1}[0-9]{3}.

r = red, g = green, b = blue, and afterwards 3 decimals (000-255). Example : r200 

c = clear. Example : c000

Decimals represent light intensity, with 000 being off and 255 being maximum on.

## How it looks like
Here's an example of r050 followed by b050 (red + blue = magenta):

![r050_b050][r050_b050]

[1]: https://github.com/mihaigalos/Drivers/tree/52bb31ab689eac574f0edddc15ebfab5033ef556/AVR/SoftwareUart
[r050_b050]:  https://github.com/mihaigalos/fun/blob/master/attiny10_rgb/photos/r050_b050.jpg