#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "ISocket.h"

class ServerSocket : public ISocket
{
private:
	bool Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect);
	bool Recieve(UDPpacket* recieved);
public:
	ServerSocket();
	~ServerSocket();

	bool Connect(IPaddress* address);
	void Close(UDPsocket socket);
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif
