# LoRaproject
This project is one of my school project and i'm planning use c++ to established connection between two Microchip RN2483 module.
development board is Raspberry pi 4 and toolchain what i will use is arm-none-linux-gnueabihf-
Linux distro in raspberry pi is Debian

***Setup***
Raspberry pi 4 terminal
To get serial communication work in this program it need configure diffrently than default settings
in commandline write sudo raspi-config and go interface options
there select p6 Serial port
Would you like shell to .... -> NO
would you like the serial port hardware to be enabled -> YES
finish and reboot
after modification in /dev/ folder you will find serial0 and serial1.
before modification /dev/ only have one serial and it was serial1

Links:
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/

