#include "ServerSocket.h"

ServerSocket::ServerSocket() { }

ServerSocket::~ServerSocket() { }

bool ServerSocket::Connect(IPaddress* address) {
	return true;
}

void ServerSocket::Close(UDPsocket socket) {

}

bool ServerSocket::Send(std::string* data) {
	return true;
}

bool ServerSocket::Recieve(std::string* data) {
	return true;
}

bool ServerSocket::Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect) {
	return true;
}

bool ServerSocket::Recieve(UDPpacket* recieved) {
	return true;
}