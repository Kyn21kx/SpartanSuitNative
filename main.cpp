#include "RemoteConnection/Server/UDPServer.h"

using namespace SpartanSuit;

int main()
{
	UDPServer server;
	while(true) {
		server.Update();
	}
	return 0;
}
