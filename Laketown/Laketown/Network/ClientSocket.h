#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "ISocket.h"
#include <vector>

class ClientSocket : public ISocket 
{
private:
	UDPsocket socket;
	IPaddress destination;
public:
	ClientSocket() { }
	~ClientSocket() { Close(socket); }
	
	bool Connect(const char* host, uint16_t port);
	void Close(UDPsocket socket);
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif

