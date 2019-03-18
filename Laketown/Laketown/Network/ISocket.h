#ifndef ISOCKET_H
#define ISOCKET_H

#include <SDL_net.h>
#include <vector>
#include <map>
#include <string>

constexpr auto TIMEOUT = 2000;
constexpr auto ERROR = 0xff;
constexpr auto PACKET_SIZE = 65535;

class ISocket {
	
public:
	virtual bool Connect(const char* host, uint16_t port) = 0;
	virtual void Close(UDPsocket socket) = 0;
	virtual bool Send(std::string* data) = 0;
	virtual bool Recieve(std::string* data) = 0;
};


#endif // !ISOCKET_H

