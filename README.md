# LoRaproject
This project is one of my school project and i'm planning use c++ to established connection between two Microchip RN2483 module.
development board is Raspberry pi 4 and toolchain what i did use is arm-none-linux-gnueabihf-
Linux distro in raspberry pi is Debian

***Project***

Raspberry uses linux uart to make connection betweeen module and rpi4
using command 0 or 1 give you option to select sender or receiver mode
I did need add one led to gpio 22 to indicate p2p connection when used this in field test.
p2p connection was working around 700m +14db. All options for connection is hard coded for easier use in field test.

To use as standalone you need make this work as service and set linux load it during boot time.

Links:
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/

