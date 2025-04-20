#include "NetworkDefinitions.h"
#include <cstdio>
#include <winsock2.h>

constexpr int32_t MAX_LINE_BUFFER_BYTES = 1024;


SpartanSuit::Socket::Socket(int32_t port)
{
	this->m_port = port;
}

SpartanSuit::Error SpartanSuit::Socket::Init()
{
	char buffer[MAX_LINE_BUFFER_BYTES];

	this->m_fileDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
	if (this->m_fileDescriptor < 0) {
		return Error::NetworkInitializationError;
	}
	// Filling server information 
	this->m_serverAddress.sin_family = AF_INET; // IPv4 
	this->m_serverAddress.sin_addr.s_addr = INADDR_ANY;
	this->m_serverAddress.sin_port = htons(this->m_port);

	//Bind the socket to the address of the server
	int32_t rc = bind(this->m_fileDescriptor, this->GetServerAddressPointer(), sizeof(m_serverAddress));
	if (rc < 0) {
		return Error::NetworkBindingError;
	}

	return Error::Ok;
}

SpartanSuit::Error SpartanSuit::Socket::TryPoll(bool* receivedData, char* outBuffer, size_t length)
{
	*receivedData = false;

	socklen_t len = sizeof(m_clientAddress);  //len is value/result 
	int32_t n = recvfrom(
		this->m_fileDescriptor,
		outBuffer,
		length - 1,
		0,
		this->GetClientAddressPointer(),
		&len
	);

	printf("Bytes received: %d\n", n);
	
	if (n < 0) {
		int32_t err = WSAGetLastError();
		printf("Error code: %d\n", err);
	}
	
	//Null terminate the UDP buffer
	if (n >= length) {
		return Error::OutOfBoundsError;
	}
	outBuffer[length] = 0;
	fprintf(stdout, "Datagram: %s\n", outBuffer);
	sendto(this->m_fileDescriptor, outBuffer, n, 0, this->GetClientAddressPointer(), len);

	*receivedData = n > 0;

	
	return Error::Ok;
}

sockaddr* SpartanSuit::Socket::GetClientAddressPointer()
{
	return reinterpret_cast<sockaddr*>(&this->m_clientAddress);
}

const sockaddr* SpartanSuit::Socket::GetServerAddressPointer() const
{
	return reinterpret_cast<const sockaddr*>(&this->m_serverAddress);
}
