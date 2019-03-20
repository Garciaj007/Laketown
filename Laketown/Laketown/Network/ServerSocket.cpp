#pragma warning(disable : 4996)

#include "ServerSocket.h"
#include <iostream>

bool ServerSocket::Connect(const char* host, uint16_t port) {

	UDPsocket socket = SDLNet_UDP_Open(port);
	IPaddress destination;

	if (!socket) {
		std::cerr << "Failed SDLNet_UDP_Open : " << SDLNet_GetError() << std::endl;
		return false;
	}
	else
	{
		std::cout << "Opened Port : " << port << std::endl;
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

	connections.emplace(socket, destination);

	return true;
}

void ServerSocket::Close(UDPsocket socket) {
	//Removing from map
	for (auto it = connections.begin(); it != connections.end(); it++) {
		if (it->socket == socket) {
			SDLNet_UDP_Close(it->socket);
			connections.erase(it);
		}
	}
}

void ServerSocket::CloseAll() {
	for (auto it = connections.begin(); it != connections.end(); it++) {
		SDLNet_UDP_Close(it->socket);
	}

	connections.clear();
}

bool ServerSocket::Send(std::string* data) {
	for (auto it = connections.begin(); it != connections.end(); it++) {
		//Declaring & Allocating Packet
		UDPpacket* packet = SDLNet_AllocPacket(PACKET_SIZE);

		if (!packet) {
			std::cerr << "Connection: " << it->id << " Failed SDLNet_AllocPacket : " << SDLNet_GetError() << std::endl;
			return false;
		}

		//Setting Packet's Destination
		packet->address = it->address;

		//Fill packet with data
		strcpy((char*)packet->data, data->c_str());
		packet->len = sizeof(data->c_str());

		//Sending Packet
		if (!SDLNet_UDP_Send(it->socket, -1, packet)) {
			std::cerr << "Connection: " << it->id <<  " Failed SDLNet_UDP_Send : " << SDLNet_GetError << std::endl;
			return false;
		}

		//Deallocate Packet
		SDLNet_FreePacket(packet);
	}

	return true;
}

bool ServerSocket::Recieve(std::string* data) {
	for (auto it = connections.begin(); it != connections.end(); it++) {

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
			int status = SDLNet_UDP_Recv(it->socket, packet);

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

	}

	return true;
}