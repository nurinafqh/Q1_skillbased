#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];
    int n;

    // create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
        perror("Error opening socket");

    // configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("192.168.68.102");

    // connect to the server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    printf("Connected to server\n");

    // receive the random number from the server
    n = read(client_socket, buffer, sizeof(buffer)-1);
    if(n < 0)
        perror("Error read from socket");

    //display the random number
    printf("welcome....\n");
    printf("your generated number is: %s\n", buffer);

    // close the socket
    close(client_socket);
    return 0;
}