#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
	
	// Create socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// Specify address for socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	// INADDR_ANY is 0.0.0.0 address
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	if (connection_status == -1) {
		printf("There was an error making a connection to a remote socket");
	}

	
	// Recieve data from the server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	// Print data returned from the server
	printf("The server sent the data %s\n", server_response);

	close(network_socket);

	return 0;

}
