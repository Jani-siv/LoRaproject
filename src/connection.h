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
//#include <sys/ioctl.h>
//#include <linux/posix_types.h>
class connection {
public:
	connection(char* devicename);
	virtual ~connection();
	int testDevice();
	int sendMessage(char* message,int len);
	int readMessage();
	void showMessage();

private:
	bool ready = false;
	char *devicename;
	int serial_port=0;
	struct termios tty;
	char buffer[256];


};

#endif /* CONNECTION_H_ */
