/*
 * Lora.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: Gyy
 */

#include "Lora.h"

Lora::Lora() {
	// TODO Auto-generated constructor stub
this->initConnection(this->dev);
}

Lora::~Lora() {
	// TODO Auto-generated destructor stub
}

int Lora::loraInit()
{
	int ans = 0;
	std::cout<<"init Lora waiting correct answer from module"<<std::endl;
	char message[] = "sys reset\r\n";
	char* reboot = message;
	char pause[] = "mac pause\r\n";
	char *pauseptr = pause;
	char freq[] = "radio set freq 868000000\r\n";
	char * freqptr = freq;
	char pwr[] = "radio set pwr -3\r\n";
	char *pwrptr = pwr;
	char mode[] = "radio set mod lora\r\n";
	char *modeptr = mode;
	char sf[] = "radio set sf sf7\r\n";
	char *sfptr = sf;
	char bf[] = "radio set bw 125\r\n";
	char *bfptr =bf;
	char resum[] = "mac resume\r\n";
	char *resumptr = resum;
	while (ans != 1)
	{
		this->sendMessage(reboot,13);
	this->readMessage();
	char *messages = this->getMessage();
	ans = this->checkAnswer(messages);
	if (ans != 1)
	{
		std::cout<<"Reboot module wrong init message"<<std::endl;
	}
	}
	ans = -1;
	usleep(200000);
	bool once = false;
	while (ans != 0)
	{
		char * messages=nullptr;
		//pause
		if (once == false)
		{
		this->sendMessage(pauseptr,sizeof(pause));
		usleep(2000);
		once = true;
		}
		//freq
		ans = this->initCommands(freqptr,sizeof(freq));
		//pwr
		ans = this->initCommands(pwrptr,sizeof(pwr));
		//mode
		ans = this->initCommands(modeptr,sizeof(mode));
		//sf
		ans = this->initCommands(sfptr,sizeof(sf));
		//bf
		ans = this->initCommands(bfptr,sizeof(bf));
		//mac resume
		ans = this->initCommands(resumptr,sizeof(resum));

		usleep(2000);
	}
	std::cout<<"Lora init done successfully"<<std::endl;
	this->sleep100ms();
	return 0;
}
int Lora::initCommands(char* messages, int size)
{
	int ans = 0;
	char * mes;
	this->sendMessage(messages,size);
	this->readMessage();
	mes = this->getMessage();
	ans = this->checkAnswer(mes);
return ans;

}
void Lora::loraReceive()
{


}
void Lora::sleep100ms()
{
	char message[] = "sys sleep 100\r\n";
	char * mesptr = message;

		this->sendMessage(mesptr,sizeof(message));
		this->readMessage();
		char * ans = this->getMessage();
		std::cout<<"answer: "<<ans<<std::endl;
		int test = this->checkAnswer(ans);
		std::cout<<"check number: "<<test<<std::endl;
		ans=nullptr;
}
void Lora::loraSend(std::string message)
{
	std::string mes ="radio tx " + message + "\r\n";
	int ans = -1;
	unsigned int sizemes = mes.length();
	char mess[sizemes];
	char *messptr = mess;
	for (int i=0; i< sizemes; i++)
	{
		mess[i] = mes[i];
	}
	while (ans != 0)
	{
	ans = this->initCommands(messptr,sizeof(mess));
	std::cout<<"message"<<ans<<std::endl;
	}
/*
	  deviceSend(port, "radio tx 0123456789")
	  sleep(0.5)
	  line = port.readline()
	  print line.strip()
	  deviceSend(port, "mac resume")
	  */
}

int Lora::checkAnswer(char *answer)
{
	int testInit = 0;
	char initMessage[] = "RN2483 1.0.1";
	int newline = 0, endmessage = 0;
	bool setNewline = false, setEnd=false;
	std::cout<<"answer from function: "<<answer<<std::endl;
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if ((answer[0] == 111 && setNewline == false) || (answer[0] == 105 && setNewline == false) || (answer[0] == 82 && setNewline == false) || (answer[0] == 114 && setNewline == false))
		{
			std::cout<<"skip newline"<<std::endl;
			setNewline =true;
			newline= i;
		}
		if (answer[i] == '\n' && setNewline == false)
		{
			newline = i+1;
			setNewline = true;
		}
		if (answer[i] == 42 && setEnd == false && setNewline == true)
		{
			std::cout<<"end"<<i<<std::endl;
			endmessage=i-2;
			setEnd = true;
		}

	}
	for (int i = 0; i < 6; i++)
	{
	if (initMessage[i] != answer[i])
	{
		testInit = -1;
		break;
	}
	}
	if (testInit == 0)
	{
		return 1;
	}
	else {
		char convertedAnswer[endmessage-newline];
		int j = 0;
	for (int i = newline; i < endmessage; i++)
	{
		convertedAnswer[j] = answer[i];
		j++;
	}
std::cout<<"answer found: "<<convertedAnswer<<std::endl;
	this->commands.answerit = this->commands.answers.find(convertedAnswer);
if (this->commands.answerit == this->commands.answers.end())
{
	return -1;
}
else {
	return this->commands.answerit->second;
}
}}
