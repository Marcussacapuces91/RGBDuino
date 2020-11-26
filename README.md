# RGBDuino
"RGBDuino UNO compatible board designed and developed specialy for students to learn coding using a microcontroller. We named it RGBDuino UNO to encourage everyone to be a maker by getting started with this amazing board." 

The original repository did not however contain any schematics nor hardware details, bom lists or details to help makers.
This fork tries to change that. Either by reverse engineering or getting them to release the required files.

## Features
* Atmel ATmega328P microcontroller (As used on original Arduino UNO)
* Input USB 5V
* 500mA (Max) 3.3V Voltage regulator
* 10 blue leds and 2 RGB programable leds.
* Micro usb for power and programming using
* WCH CH341, USB to serial ic with speeds from 50bps to 2Mpbs, supporting 5v and 3.3v.
* Buzzer for "music"
* 1 programmable button (aka, user Input to be defined)
* 1 reset button
* A cute Duck or awesome Makergirl design printed on the PCB

## Important Pin assignments

Pin D9 is connected to the signal pin of the buzzer module
Or, according to PDF, pin 8. Switch the buzzer to off, to use pin8 for different things.
Pin 12 and Pin 13 are connected to the two RGB led.
Pin2 should be the user button (next to reset, be carefull) Its the one close to the header,
reset is to the outside of the board.

# Examples

## Buzzer test
Included is an empty text file, the title seems to be in Thai and reads:
``How do you know?`` (``ทไร๙ฦ๗ฒโสิด๚ย๋.txt``)
or ``What is 9? 7?``


# Drivers for the serial device

The original included driver package did not seem to be from the original hardware manufacturer, as such, its been deleted.
Users are adviced to see if drivers for the WCH CH341 are automaticly installed (By Windows or Linux) or find a solution, drivers on the following website:
http://wch-ic.com/search?q=CH341&t=downloads

# Backup of original firmware
A backup has been made using the following command with extra verbosity.
also backups from eeprom and fuses can be found. It is not expected those to be in any special condition.
(also odd the eeprom contains the first bit from flash?)

```bash
$ avrdude -c arduino -D -P /dev/ttyUSB0 -n -p m328p -v -v -v -Uflash:r:flash.hex:i
```
Its output:
```bash
avrdude: Version 6.3, compiled on Jul  7 2020 at 19:38:43
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/etc/avrdude.conf"
         User configuration file is "/home/user1/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : /dev/ttyUSB0
         Using Programmer              : arduino
         AVR Part                      : ATmega328P
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PC2
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    20     4    0 no       1024    4      0  3600  3600 0xff 0xff
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           flash         65     6   128    0 yes     32768  128    256  4500  4500 0xff 0xff
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           efuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : Arduino
         Description     : Arduino
         Hardware Version: 3
         Firmware Version: 4.4
         Vtarget         : 0.3 V
         Varef           : 0.3 V
         Oscillator      : 28.800 kHz
         SCK period      : 3.3 us

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: safemode read 1, lfuse value: 0
avrdude: safemode read 2, lfuse value: 0
avrdude: safemode read 3, lfuse value: 0
avrdude: safemode: lfuse reads as 0
avrdude: safemode read 1, hfuse value: 0
avrdude: safemode read 2, hfuse value: 0
avrdude: safemode read 3, hfuse value: 0
avrdude: safemode: hfuse reads as 0
avrdude: safemode read 1, efuse value: 0
avrdude: safemode read 2, efuse value: 0
avrdude: safemode read 3, efuse value: 0
avrdude: safemode: efuse reads as 0
avrdude: reading flash memory:

Reading | ################################################## | 100% 4.21s

avrdude: writing output file "flash.hex"

avrdude: safemode read 1, lfuse value: 0
avrdude: safemode read 2, lfuse value: 0
avrdude: safemode read 3, lfuse value: 0
avrdude: safemode: lfuse reads as 0
avrdude: safemode read 1, hfuse value: 0
avrdude: safemode read 2, hfuse value: 0
avrdude: safemode read 3, hfuse value: 0
avrdude: safemode: hfuse reads as 0
avrdude: safemode read 1, efuse value: 0
avrdude: safemode read 2, efuse value: 0
avrdude: safemode read 3, efuse value: 0
avrdude: safemode: efuse reads as 0
avrdude: safemode: Fuses OK (E:00, H:00, L:00)

avrdude done.  Thank you.

```

### Original eeprom

```bash
$ avrdude -c arduino -D -P /dev/ttyUSB0 -n -p m328p -v -v -v -Ueeprom:r:eeprom.hex:i
```

# License
Original project doesnt seem to provide any license information.
As per indicated image and words, its asummed to be OSHW,
The AdafruitNeoPixel library, wich is included by the original repo:
GNU GPL version 3

