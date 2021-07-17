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
    
    char *msg = "hello!!";
    char buf[256] = {0, };
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    write(client_socket, msg, sizeof(msg));
    read(client_socket, buf, sizeof(buf));

    printf("Msg from server: %s\n", buf);

    return 0;
}