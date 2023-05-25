# include <iostream>
# include <signal.h>
# include "TCPClient.h"
# include <time.h>
# include <bits/stdc++.h>
# include <string.h>
# include <sys/types.h>
# include <fstream>
# include <sys/socket.h>

TCPClient tcp;
using namespace std;

void sig_exit(int s) {
	tcp.exit();
	exit(0);
	
	while(1) {
		srand(time(NULL));
		string str = to_string(rand() % 10000);
		tcp.send(str);
		string rec = tcp.receive();
		
		if(rec != "") {
			cout << "Server speak: " << rec << endl;
		}
		
		sleep(1);
	}
}

int main(int argc, char* argv[]) {
	signal(SIGINT, sig_exit);
	tcp.setup("127.0.0.1", 3098);

	return 0;
}
