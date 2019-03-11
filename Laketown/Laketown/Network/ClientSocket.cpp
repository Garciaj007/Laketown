#include "ClientSocket.h"

ClientSocket::ClientSocket(){}

ClientSocket::~ClientSocket(){}

bool ClientSocket::Connect(IPaddress* address) {
	return true;
}

void ClientSocket::Close(UDPsocket socket) {
	SDLNet_UDP_Close(socket);
}

bool ClientSocket::Send(std::string* data) {
	return true;
}

bool ClientSocket::Recieve(std::string* data) {
	return true;
}

bool ClientSocket::Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect) {
	return true;
}

bool ClientSocket::Recieve(UDPpacket* recieved) {
	return true;
}