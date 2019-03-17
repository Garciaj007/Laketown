#include "ServerSocket.h"

ServerSocket::ServerSocket() { }

ServerSocket::~ServerSocket() { }

bool ServerSocket::Connect(IPaddress* address) {
	return true;
}

void ServerSocket::Close(UDPsocket socket) {
	//Removing from map
	connections.erase(socket);
}

bool ServerSocket::CloseAll() {
	for (auto it = connections.begin(); it != connections.end(); it++) {
		Close(it->first);
	}

	connections.clear();
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

bool ServerSocket::Recieve(UDPpacket* recieved, uint32_t delay, uint8_t expect) {
	return true;
}