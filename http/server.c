#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {

	FILE *html_data;
	html_data = fopen("./index.html", "r");
	printf("bye");

	// Read file into response_data
	char response_data[1024];
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	// http_header contains header and response_data
	strcat(http_header, response_data);
	
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
	printf("bye");
	// Listen for a connection
	listen(server_socket, 5);

	int client_socket;
        char test[2048] = "hello";
	// Int	
	while(1) {
		client_socket = accept(server_socket, NULL, NULL);
		printf("Hello");
		// Send the message
		send(client_socket, test, sizeof(test), 0);
		close(client_socket);
	}
	
	return 0;

}
