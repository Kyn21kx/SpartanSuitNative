#include "NetworkDefinitions.h"

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
//Unix equivalent headers
#endif

constexpr int32_t MAX_LINE_BUFFER_BYTES = 1024;

using namespace SpartanSuit;

Socket::Socket(int32_t port)
{
	this->m_port = port;
}

Error SpartanSuit::Socket::Init()
{
	sockaddr_in clientAddress = {};
	sockaddr_in serverAddress = {};

	char buffer[MAX_LINE_BUFFER_BYTES];

	this->m_fileDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
	if (this->m_fileDescriptor < 0) {
		return Error::NetworkInitializationError;
	}
	// Filling server information 
	serverAddress.sin_family = AF_INET; // IPv4 
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_port = htons(this->m_port);

	//Bind the socket to the address of the server
	const auto* addressPtr = reinterpret_cast<const sockaddr*>(&serverAddress);
	int32_t rc = bind(this->m_fileDescriptor, addressPtr, sizeof(serverAddress));
	if (rc < 0) {
		return Error::NetworkBindingError;
	}

	socklen_t len = sizeof(clientAddress);  //len is value/result 
	auto* clientAddressPtr = reinterpret_cast<sockaddr*>(&clientAddress);
	int32_t n = recvfrom(
		this->m_fileDescriptor, 
		buffer, 
		MAX_LINE_BUFFER_BYTES, 
		MSG_WAITALL, 
		clientAddressPtr, 
		&len
	);
}
