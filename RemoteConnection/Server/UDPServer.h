#pragma once

#include "NetworkDefinitions.h"

namespace SpartanSuit {
	class UDPServer {
	public:
		UDPServer();
		
		~UDPServer() {
			this->Dispose();
		}
		
		void Dispose();
		
		void Update();

	private:
		constexpr static size_t UDP_DATA_BUFFER_LENGTH = 1024;
		
		Socket m_socket;
		char m_dataBuffer[UDP_DATA_BUFFER_LENGTH];
	};
}


