#include "RemoteConnection/Server/NetworkDefinitions.h"
#include <cstdio>

using namespace SpartanSuit;

int main()
{
	Socket udpSocket(8080);
	Error err = udpSocket.Init();
	if (err != Error::Ok) {
		printf("Error: %d", err);
	}

	bool hasData;
	char buffer[1024];
	while (true)
	{
		err = udpSocket.TryPoll(&hasData, buffer, 1024);
		if (err != Error::Ok) {
			printf("Polling from UDP failed because of error %d!\n", err);
			return static_cast<int32_t>(err);
		}
		if (!hasData) {
			printf("Data was not received from the UDP client!\n");
			continue;
		}
		Sleep(500);
	}
	return 0;
}