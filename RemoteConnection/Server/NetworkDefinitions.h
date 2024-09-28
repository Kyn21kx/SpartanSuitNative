#pragma once

#include <cstdint>
#include "../../Error.h"

namespace SpartanSuit {
	class Socket {
	public:
		Socket(int32_t port);
		
		Error Init();

	private:
		int32_t m_fileDescriptor = -1;
		int32_t m_port;
	};


}