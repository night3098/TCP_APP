# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <sys/types.h>
# include <vector>
# include <signal.h>

#include <sys/wait.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

class TCPClient {
	private:
		int sock;
		string address;
		int port;

		struct sockaddr_in_server {
    		short int          sin_family;  // Семейство адресов
    		unsigned short int sin_port;    // Номер порта
    		struct in_addr     sin_addr;    // IP-адрес
			struct sockaddr;
   			unsigned char      sin_zero[8]; // "Дополнение" до размера структуры sockaddr
		};

		struct sockaddr_in_server server;

	public:
		TCPClient();
		bool setup(string address, int port);
		bool send(string data);
		string receive(int size = 4090);
		string read();
		void exit();
};
