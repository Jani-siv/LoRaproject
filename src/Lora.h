/*
 * Lora.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Gyy
 */

#ifndef LORA_H_
#define LORA_H_
#include "connection.h"
#include "loracon.h"
#include <iostream>
#include <cstring>
#include <string>

class Lora : public connection{
public:
	char devaddr[13] = "/dev/serial0";
	char* dev = devaddr;
	Lora();
	int loraInit();
	void loraReceive();
	void loraSend(std::string message);
	void sleep100ms();
	virtual ~Lora();
private:
	bool init = false;
	int checkAnswer(char *answer);
	int initCommands(char* messages, int size);
	connection con();

	loraconnect commands;
};

#endif /* LORA_H_ */
