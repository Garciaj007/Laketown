#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "ISocket.h"

class ClientSocket : public ISocket 
{
private:
	bool Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect);
	bool Recieve(UDPpacket* recieved);
public:
	ClientSocket();
	~ClientSocket();
	
	bool Connect(IPaddress* address);
	void Close(UDPsocket socket);
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif

