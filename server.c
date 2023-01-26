#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT 8080

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_size;
    char buffer [1024];
    int randomnum;
    int opt = 1;
    int addrlen = sizeof(address);
    int n;

    // create a socket
    server_fd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

     // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to the server address
    n = bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if(n < 0){
        perror("Binding error");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    listen(server_fd, 5);
    printf("Waiting for client...\n");
    

    // accept a connection from a client
    client_address_size = sizeof(client_address);
    client_socket = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size);

    // generate a random number between 100 and 999
    srand(time(NULL));
    randomnumber = (rand() % 900) + 100;
 
    sprintf(buffer, "%d", randomnum);

    printf("CONNECTED TO CLIENT! \n");

    // send the random number to the client
    n = write(client_socket, buffer, sizeof(buffer));
    

    // close the socket
    close(client_socket);
    close(server_fd);

    return 0;
}
