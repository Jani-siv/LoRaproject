/*
 * loracon.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Gyy
 */

#ifndef LORACON_H_
#define LORACON_H_
#include <string>
#include <map>
typedef struct loraconnect{
std::map<std::string,std::string> commands = {
		{"sys","sys "},
		{"LoRawan","mac "},
		{"transceiver","radio "},
		{"end","\r\n"}
};

std::map<std::string,int> answers = {
		{"ok",0},
		{"radio_tx_ok",0},
		{"invalid_param",-1},
		{"radio_err",-1},
		{"Requested Information",-2},
		{"Descriptive Error Message",-3},
		{"RN2483 1.0.1",1}
};
std::map<std::string,std::string> syscommands = {
		{"sleep" ,"sleep"},
		{"reset", "reset"},
		{"set", "set"},
		{"get","get"}
		};
std::map<std::string,std::string>::iterator commandsit;
std::map<std::string,int>::iterator answerit;
std::map<std::string,std::string>::iterator syscomit;


}loraconnect;

typedef struct hardware{
	char devaddr[13] = "/dev/serial0";
	char* dev = devaddr;
	int CTS = 17;
	int RTS = 27;
}hardware;

#endif /* LORACON_H_ */
