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
#include "connection.h"
using namespace std;
//


int
main()
{
	//device settings
	char device[] = "/dev/serial1";
	char *deviceptr = nullptr;
	deviceptr = device;

	connection con(deviceptr);

	//define uart connection between LoRa module and Raspberry pi
  cout << "sadf" << endl;
  return 0;
}
