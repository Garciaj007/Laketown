#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "ISocket.h"

class ServerSocket : public ISocket
{
private:
	std::map<UDPsocket, std::vector<UDPpacket>> connections;

	bool Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect);
	bool Recieve(UDPpacket* recieved, uint32_t delay, uint8_t expect);
	bool CloseAll();
public:
	ServerSocket();
	~ServerSocket();

	bool Connect(IPaddress* address);
	void Close(UDPsocket socket);
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif
