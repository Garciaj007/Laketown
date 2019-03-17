#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "ISocket.h"

class ClientSocket : public ISocket 
{
private:
	UDPsocket socket;
	UDPpacket packet;

	bool Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect);
	bool Recieve(UDPpacket* recieved, uint32_t delay, uint8_t expect);
public:
	ClientSocket();
	~ClientSocket();
	
	bool Connect(IPaddress* address);
	void Close(UDPsocket socket);
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif

