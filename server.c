#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage %s <PORT>\n", argv[0]);
        return 1;
    }
    
    char buf[1024] = {0, };
    char *response = "Hello Client!";
    int server_socket, connection_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    
    listen(server_socket, 5);
    
    client_addr_size = sizeof(client_addr);
    connection_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);

    read(connection_socket, buf, sizeof(buf));
    printf("Msg: %s\n", buf);

    write(connection_socket, response, strlen(response));
    
    close(server_socket);
    close(connection_socket);
    return 0;
}