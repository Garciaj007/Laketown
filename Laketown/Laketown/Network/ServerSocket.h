#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "ISocket.h"
#include <map>
#include <set>

class ServerSocket : public ISocket
{
	struct Connection {
		//Members 
		int id;
		UDPsocket socket;
		IPaddress address;

		//Constructor
		Connection(UDPsocket socket, IPaddress address) :socket(socket), address(address) { id = id++; }
	};

	struct ConnectionCompare {
		bool operator()(const Connection& lhs, const Connection& rhs) const {
			return lhs.id < rhs.id;
		}
	};

private:
	std::set<Connection, ConnectionCompare> connections;

public:
	ServerSocket() { }
	~ServerSocket() { CloseAll(); }

	bool Connect(const char* host, uint16_t port);
	void Close(UDPsocket socket);
	void CloseAll();
	bool Send(std::string* data);
	bool Recieve(std::string* data);
};

#endif
