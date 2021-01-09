#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

	char server_message[256] = "This is the server!!!";
	
	// Create socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// Specify address for socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	// INADDR_ANY is 0.0.0.0 address
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	// Listen for a connection
	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	// Send the message
	send(client_socket, server_message, sizeof(server_message), 0);

	close(server_socket);
	
	return 0;

}
