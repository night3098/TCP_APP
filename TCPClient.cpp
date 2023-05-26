# include <iostream>
# include <signal.h>
# include "TCPClient.h"
# include <time.h>
# include <bits/stdc++.h>
# include <string.h>
# include <sys/types.h>
# include <fstream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>

#define _WIN32_WINNT 0x501

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;
using nullptr_t = decltype(nullptr);

TCPClient::TCPClient() {
	sock = -1;
	port = 0;
	address = "";
}

bool TCPClient::setup(string address, int port) {
	if(sock == -1) {
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == -1) {
			cout << "���������� ������� �����" << endl;
		}
	}
	if(inet_addr(address.c_str()) == -1) {
		struct hostent *he;
		struct in_addr **addr_list;
		
		addr_list = (struct in_addr **) he->h_addr_list;
		
		for(int i = 0; addr_list[i] != NULL; i++) {
			server.sin_addr = *addr_list[i];
			break;
		}
	}
	else {
		server.sin_addr.s_addr = inet_addr(address.c_str());
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	if (connect(sock, (struct sockaddr *)&server, sizeof (server)) < 0) {
		cout << "Connect error" << endl;
		return false;
	}
		
	return true;
}

bool TCPClient::send(string data) {
	if (sock != -1) {
		/*
		if (send(sock, strlen(data.c_str()), 0) < 0) {
			cout << "Send fail" << endl;
			return false;
		}
		*/
	}
	else {
		return false;
	}
	return true;
}

string TCPClient::receive(int size) {
	char buffer[size];
	memset(&buffer[0], 0, sizeof(buffer));
	string reply;
	if (recv(sock, buffer, size, 0) < 0) {
		cout << "Receive fail" << endl;
		return nullptr;
	}
	buffer[size] = '\0';
	reply = buffer;
	return reply;
}

string TCPClient::read() {
	char buffer[1] = {};
	string reply;
	while (buffer[0] != '\n') {
		if(recv(sock, buffer, sizeof(buffer), 0) < 0) {
			cout << "Receive fail" << endl;
			return nullptr;
		}
		reply += buffer[0];
	}
	return reply;
}

void TCPClient::exit() {
	close(sock);
}
