#pragma once

#include <cstdint>
#include "../../Error.h"
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
//Unix equivalent headers
#endif

namespace SpartanSuit {
	class Socket {
	public:
		Socket(int32_t port);
		
		Error Init();

		Error TryPoll(bool* receivedData, char* outBuffer, size_t length);

	private:
		const sockaddr* GetServerAddressPointer() const;
		
		sockaddr* GetClientAddressPointer();

		int32_t m_fileDescriptor = -1;
		int32_t m_port;

		sockaddr_in m_clientAddress = {};
		sockaddr_in m_serverAddress = {};
	};


}