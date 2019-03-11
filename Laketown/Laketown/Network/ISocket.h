#ifndef ISOCKET_H
#define ISOCKET_H

#include <SDL_net.h>
#include <vector>
#include <string>

#define TIMEOUT 2000
#define ERROR 0xff

class ISocket {
protected:
	std::vector<UDPsocket> sockets;
	std::vector<UDPpacket> packets;

	virtual bool Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect) = 0;
	virtual bool Recieve(UDPpacket* recieved) = 0;
public:
	virtual bool Connect(IPaddress* address) = 0;
	virtual void Close(UDPsocket socket) = 0;
	virtual bool Send(std::string* data) = 0;
	virtual bool Recieve(std::string* data) = 0;
};


#endif // !ISOCKET_H

