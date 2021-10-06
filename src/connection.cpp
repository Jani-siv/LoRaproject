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
		//clear parity
		this->tty.c_cflag &= ~PARENB;
		// num. stop bits clear stop bit field
		this->tty.c_cflag &= ~CSTOPB;
		//number of bit pre byte
		this->tty.c_cflag |= CS8;
		//flow control no control
		this->tty.c_cflag &= ~CRTSCTS;
		//CREAD and CLOCAL clocal disable modem-specific signal lines such as carrier detect
		//Cread aloow us read data
		this->tty.c_cflag |= CREAD | CLOCAL; //enable read and ignore ctrl lines (CLOCAL = 1)
		// Canonical mode (disable)
		this->tty.c_lflag &= ~ICANON;
		//echo
		this->tty.c_lflag &= ~ECHO; // Disable echo
		this->tty.c_lflag &= ~ECHOE; // Disable erasure
		this->tty.c_lflag &= ~ECHONL; // Disable new-line echo
		//Disable Signal Chars
		this->tty.c_lflag &= ~ISIG;
		//Software Flow Control (disabled)
		this->tty.c_iflag &= ~(IXON | IXOFF | IXANY);
		//Disabling Special Handling Of Bytes On Receive
		this->tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
		//Output Modes
		this->tty.c_oflag &= ~OPOST;
		this->tty.c_oflag &= ~ONLCR;
		//timing
		this->tty.c_cc[VTIME] = 0;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
		this->tty.c_cc[VMIN] = 255;

		//baudrate
		//in
	//	cfsetispeed(&this->tty, B115200);
		//out
	//	cfsetospeed(&this->tty, B115200);
		//all set
		cfsetspeed(&this->tty, B115200);
		tcsetattr(this->serial_port,TCSANOW,&this->tty);
		this->ready = true;
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

int connection::sendMessage(char* message, int len)
{
	if (this->ready == true)
	{
		int ret = write(this->serial_port,message,len);
		std::cout<<"message: "<<message<<std::endl;
		if (ret < 0)
		{
			std::cerr<<"Error sending message: "<<message<<std::endl;
			return -1;
		}
		return 0;
	}
	else
	{
		std::cerr<<"Error device not ready"<<std::endl;
		return -1;
	}
}

int connection::readMessage()
{
memset(&this->buffer,'0',256*sizeof(char));
char *test = this->buffer;
std::cout<<"buffer before reading"<<test<<std::endl;
	int ret = read(this->serial_port,&this->buffer,256);
	if (ret < 0)
	{
		std::cerr<<"error reading message"<<std::endl;
		return -1;
		}
	else
	{
		return 0;
	}

}

void connection::showMessage()
{
	char* mes = this->buffer;
	std::cout<<mes<<std::endl;
}
