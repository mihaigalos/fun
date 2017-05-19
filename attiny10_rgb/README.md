# Fun with an AtTiny10 : control a RGB led via Software UART



## Prerequisites


- breakout for AtTiny10, i.e. : hardware/TinyOne.
- make.exe in PATH
- avr-objcopy.exe in PATH
- environment variable Tiny10DescriptionFiles pointing to the AtTiny10 
base description files (i.e. : C:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATtiny_DFP\1.1.102)

## How to

### Build

Call **make all** from a bash / batch console to build. Call **make clean** to remove a previous build.

### Control

Hit up a terminal and send the tiny commands via Software UART. Default settings are 8N1@38400bps.

If you can read regex, here's what you can send [rgbc]{1}[0-9]{3}.

r = red, g = green, b = blue, and afterwards 3 decimals (000-255). Example : r200 

c = clear. Example : c000

Decimals represent light intensity, with 000 being off and 255 being maximum on.

In photos/ one can find an example of r050 followed by b050 (red + blue = magenta).