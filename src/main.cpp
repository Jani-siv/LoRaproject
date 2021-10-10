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
std::string mes ="12345";
	Lora lora;

	if (argc > 1)
		{
		int answer = atoi(argv[1]);
		std::cout<<"selected: "<<answer<<std::endl;

		switch(answer)
		{
			case 0:
				std::cout<<"selected transmitter"<<std::endl;
				lora.loraInit();
				usleep(2000);
				while(1)
				{
				lora.loraSend(mes);
				}
				break;

			case 1:
				std::cout<<"selected receiver"<<std::endl;
				lora.loraInit();
				usleep(2000);

				lora.loraReceive();
				std::cout<<"message from other device:"<<std::endl;
				std::cout<<lora.rmessage<<std::endl;

				std::cout<<"message from other device:"<<std::endl;
				std::cout<<lora.rmessage<<std::endl;
				break;

			default:
			std::cout<<"***LORA PROJECT****"<<std::endl;
			std::cout<<"use 0 to transmitter"<<std::endl;
			std::cout<<"use 1 to receiver"<<std::endl;
			return 0;
				break;
		}


		}
	else
	{
		std::cout<<"***LORA PROJECT****"<<std::endl;
		std::cout<<"use 0 to transmitter"<<std::endl;
		std::cout<<"use 1 to receiver"<<std::endl;
	}
	//lora.sleep100ms();


  return 0;
}
