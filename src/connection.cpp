/*
 * connection.cpp
 *
 *  Created on: Oct 5, 2021
 *      Author: Gyy
 */

#include "connection.h"

connection::connection(char* devicename) {
	// TODO Auto-generated constructor stub
this->devicename = devicename;
int serial_port = this->testDevice();
if (serial_port < 0)
{
	std::cerr<<"Error opening file"<<std::endl;
}
else
{
	this->serial_port = serial_port;

	if (tcgetattr(this->serial_port, &this->tty) != 0)
	{
		std::cerr<<"Error from tcgetattr!!!"<<std::endl;
	}
	else
	{

	}

}
}

connection::~connection() {
	// TODO Auto-generated destructor stub
	if (this->serial_port >= 0)
	{
		close(this->serial_port);
		std::cout<<"serial is now closed"<<std::endl;
	}
}

int connection::testDevice()
{
	int ret = open(this->devicename,O_RDWR);
	return ret;
}

