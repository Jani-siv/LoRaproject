//============================================================================
// Name        : main.cpp
// Author      : Jani
// Version     : 0.01
// Copyright   : Your copyright notice
// Description : Linux LoRa school project
//				 p2p connection between 2 raspberry pi 4
//				 toolchain: arm-none-linux-gnueabihf-
//				 core: arm cortex a72 cortex a53
//				 distro: Debian
//				 LoRa module: Microship rn2483 433Mhz 868Mhz
//
//ToDo make library what test and open uart connection between devices
//ToDo make library what send message
//ToDo make module commands in own file
//ToDo make master and slave select in main
//ToDo create Github repo
// device what we use for communication is /dev/serial1

//============================================================================

#include <iostream>
//library for connection

#include "Lora.h"
#include <string>
using namespace std;

//


int
main(int argc, char *argv[])
{
	//device settings
std::string mes ="123456789";
	Lora lora;
	lora.loraInit();
	usleep(2000);
	lora.loraSend(mes);
	lora.sleep100ms();


  return 0;
}
