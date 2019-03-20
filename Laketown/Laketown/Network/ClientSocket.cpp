#pragma warning(disable : 4996)

#include "ClientSocket.h"
#include <iostream>

bool ClientSocket::Connect(const char* host, uint16_t port) {

	//Opening port for socket
	socket = SDLNet_UDP_Open(port);

	if (!socket) {
		std::cerr << "Failed SDLNet_UDP_Open : " << SDLNet_GetError() << std::endl;
		return false;
	}
	else
	{
		std::cout << "Opened Port : " << SDLNet_Read16(&destination.port) << std::endl;
	}

	//Resolving host
	if (!SDLNet_ResolveHost(&destination, host, port)) {
		std::cerr << "Failed SDLNet_ResolveHost : " << SDLNet_GetError() << std::endl;
		return false;
	}
	else
	{
		std::cout << "Destination Address : " << host << std::endl;
	}

	return true;
}

void ClientSocket::Close(UDPsocket socket) {
	//Closing the Socket
	SDLNet_UDP_Close(socket);
}

bool ClientSocket::Send(std::string* data) {
	//Declaring & Allocating Packet
	UDPpacket* packet = SDLNet_AllocPacket(PACKET_SIZE);

	if (!packet) {
		std::cerr << "Failed SDLNet_AllocPacket : " << SDLNet_GetError() << std::endl;
		return false;
	}

	//Setting Packet's Destination
	packet->address = destination;

	//Fill packet with data
	strcpy((char*)packet->data, data->c_str());
	packet->len = sizeof(data->c_str());

	//Sending Packet
	if (!SDLNet_UDP_Send(socket, -1, packet)) {
		std::cerr << "Failed SDLNet_UDP_Send : " << SDLNet_GetError << std::endl;
		return false;
	}

	//Deallocate Packet
	SDLNet_FreePacket(packet);

	return true;
}

bool ClientSocket::Recieve(std::string* data) {

	uint32_t timeBegan, currentTime;

	//Declaring & Allocating Packet
	UDPpacket* packet = SDLNet_AllocPacket(PACKET_SIZE);

	if (!packet) {
		std::cerr << "Failed SDLNet_AllocPacket : " << SDLNet_GetError() << std::endl;
		return false;
	}

	//Time Started
	timeBegan = SDL_GetTicks();

	while (true) {
		//Recieving Packet
		int status = SDLNet_UDP_Recv(socket, packet);

		//Current Time
		currentTime = SDL_GetTicks();

		//Checking if connection has timed out
		if (currentTime - timeBegan > TIMEOUT) {
			std::cerr << "Failed SDLNet_UDP_Recv : Connection timed out" << std::endl;
			return false;
		}

		if (status < 0) {
			std::cerr << "Failed SDLNet_UDP_Recv : " << packet->data[0] << std::endl;
			return false;
		}
		else if (status > 0) {
			//Address of incoming packet
			std::cout << "Data Recieved from : " << SDLNet_ResolveIP(&packet->address) << " | " << SDLNet_Read16(&packet->address.port) << std::endl;

			//Setting end of data to null
			packet->data[packet->maxlen - 1] = 0;

			//Setting the data
			data = reinterpret_cast<std::string*>((char *)packet->data);

			break;
		}

		//Wait until something has been recieved
		SDL_Delay(200);
	}

	//Deallocate Packet
	SDLNet_FreePacket(packet);

	return true;
}

//bool ClientSocket::Send(UDPpacket* send, UDPpacket* response, uint32_t delay, uint8_t expect) {
//	uint32_t timeBegan, currentTime;
//	int error;
//
//	response->data[0] = 0;
//	timeBegan = SDL_GetTicks();
//
//	do {
//		currentTime = SDL_GetTicks();
//
//		if (currentTime - timeBegan > TIMEOUT) {
//			std::cerr << "SDLNet_UDP_SEND: Connection timed out" << std::endl;
//			return false;
//		}
//		if (!SDLNet_UDP_Send(socket, -1, send)) {
//			std::cerr << "SDLNet_UDP_SEND: " << SDLNet_GetError() << std::endl;
//			return false;
//		}
//
//		error = SDLNet_UDP_Recv(socket, response);
//
//		if (!error)
//			SDL_Delay(delay);
//
//	} while (!error || (response->data[0] != expect && response->data[0] != ERROR));
//
//	if (response->data[0] == ERROR) {
//		std::cerr << "SDLNet_UDP_SEND: Recieved Error: " << response->data[0] << std::endl;
//		return false;
//	}
//
//	return true;
//}
//
//bool ClientSocket::Recieve(UDPpacket* recieved, uint32_t delay, uint8_t expect) {
//
//	uint32_t timeBegan, currentTime;;
//	int error;
//
//	recieved->data[0] = 0;
//	timeBegan = SDL_GetTicks();
//
//	do {
//		currentTime = SDL_GetTicks();
//
//		if (currentTime - timeBegan > TIMEOUT) {
//			std::cerr << "SDLNet_UDP_RECV: Connection timed out" << std::endl;
//			return false;
//		}
//
//		error = SDLNet_UDP_Recv(socket, recieved);
//
//		if (!error)
//			SDL_Delay(delay);
//
//	} while (!error || ((recieved->data[0] != expect && recieved->data[0] != ERROR)));
//
//	if (recieved->data[0] == ERROR) {
//		std::cerr << "SDLNet_UDP_SEND: Recieved Error: " << recieved->data[0] << std::endl;
//		return false;
//	}
//
//	return true;
//}
