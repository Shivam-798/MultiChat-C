
#include "../SocketUtil/socketutil.h"



int main() {

    int socketFD = createTCPIpv4Socket();
    struct sockaddr_in* address = createIPv4Address("127.0.0.1", 2000);
    

    int result = connect(socketFD, (struct sockaddr *)address, sizeof *address);// specify the address of server that we want the socket connect to
    // use the IP version 5 or 6 we should cast the pointer

    if(result == 0)
        printf("Connect to server ......");
    char* message;
    message = "GET \\ HTTP/1.1\r\nHost:google\r\n\r\n";
    // because we connecting to socket that only understands the http protocol
    send(socketFD, message, strlen(message), 0);
    
    char buffer[1024];
    recv(socketFD, buffer,1024,0);
    printf("Response was %s\n", buffer);

    return 0;
}