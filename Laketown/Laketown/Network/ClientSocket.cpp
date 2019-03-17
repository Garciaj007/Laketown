#include "ClientSocket.h"
#include <iostream>

ClientSocket::ClientSocket(){}

ClientSocket::~ClientSocket() { Close(socket); }

bool ClientSocket::Connect(IPaddress* address) {
	UDPsocket socket;

	socket = SDLNet_UDP_Open(address->port);

	if (!socket) {
		std::cerr << "SDLNet_UDP_OPEN: " << SDLNet_GetError() << std::endl;
		return false;
	}

	return true;
}

void ClientSocket::Close(UDPsocket socket) {
	//Closing the Socket
	SDLNet_UDP_Close(socket);
}

bool ClientSocket::Send(std::string* data) {
	
	return true;
}

bool ClientSocket::Recieve(std::string* data) {
	return true;
}

bool ClientSocket::Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect) {
	uint32_t timeBegan, currentTime;
	int error;

	response->data[0] = 0;
	timeBegan = SDL_GetTicks();

	do {
		currentTime = SDL_GetTicks();

		if (currentTime - timeBegan > TIMEOUT) {
			std::cerr << "SDLNet_UDP_SEND: Connection timed out" << std::endl;
			return false;
		}
		if (!SDLNet_UDP_Send(socket, -1, send)) {
			std::cerr << "SDLNet_UDP_SEND: " << SDLNet_GetError() << std::endl;
			return false;
		}
		
		error = SDLNet_UDP_Recv(socket, response);

		if (!error)
			SDL_Delay(delay); 

	} while (!error || (response->data[0] != expect && response->data[0] != ERROR));
	
	if (response->data[0] == ERROR) {
		std::cerr << "SDLNet_UDP_SEND: Recieved Error: " << response->data[0] << std::endl;
		return false;
	}

	return true;
}

bool ClientSocket::Recieve(UDPpacket* recieved, uint32_t delay, uint8_t expect) {

	uint32_t timeBegan, currentTime;;
	int error;

	recieved->data[0] = 0;
	timeBegan = SDL_GetTicks();

	do {
		currentTime = SDL_GetTicks();
		
		if (currentTime - timeBegan > TIMEOUT) {
			std::cerr << "SDLNet_UDP_RECV: Connection timed out" << std::endl;
			return false;
		}

		error = SDLNet_UDP_Recv(socket, recieved);

		if (!error)
			SDL_Delay(delay);

	} while (!error || ((recieved->data[0] != expect && recieved->data[0] != ERROR)));

	if (recieved->data[0] == ERROR) {
		std::cerr << "SDLNet_UDP_SEND: Recieved Error: " << recieved->data[0] << std::endl;
		return false;
	}

	return true;
}