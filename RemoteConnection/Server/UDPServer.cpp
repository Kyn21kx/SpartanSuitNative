#include "UDPServer.h"
#include "Assert.h"
#include <cstdint>
#include <cstdio>
#include <minwindef.h>
#include <stdio.h>
#include <winsock2.h>

SpartanSuit::UDPServer::UDPServer() {
	WSADATA wsaData;
	int32_t winErr = WSAStartup(MAKEWORD(2, 2), &wsaData);
	SP_ASSERT(winErr == 0, "Failed to initialize WSA with error %d\n", winErr);
	this->m_socket = Socket(8080);
	Error err = this->m_socket.Init();
	SP_ASSERT(err == Error::Ok, "Failed to initialize UDP socket, error: %d", err);
}

void SpartanSuit::UDPServer::Dispose() {
	WSACleanup();
}

void SpartanSuit::UDPServer::Update() {
	bool didReceiveData;
	Error err = this->m_socket.TryPoll(&didReceiveData, this->m_dataBuffer, UDP_DATA_BUFFER_LENGTH);
	if (err != Error::Ok) {
		fprintf_s(stderr, "Polling from UDP failed because of error %d!\n", err);
		return;
	}
	if (!didReceiveData) return;
	constexpr uint64_t delayTimeMs = 500; 
	Sleep(delayTimeMs);
}


