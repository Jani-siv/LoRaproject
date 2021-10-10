/*
 * connection.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Gyy
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <stdio.h>
#include <string.h> //memset
//25 working
#define BUFFER_SIZE 30
//#include <sys/ioctl.h>
//#include <linux/posix_types.h>
class connection {
public:
	connection();
	virtual ~connection();
	int initConnection(char* devicename);
	std::string macAddress;
private:
	bool ready = false;
	char *devicename = nullptr;
	int serial_port=0;
	struct termios tty;

	int testDevice();

protected:
	char * getMessage();
	char buffer[BUFFER_SIZE];
	int sendMessage(char* message,int len);
	int readMessage();
	void showMessage();
	int checkMessage(char *message, int len);

};

#endif /* CONNECTION_H_ */
