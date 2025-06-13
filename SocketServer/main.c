#include "../SocketUtil/socketutil.h"


int main() {

    //create server side socket

    int serverSocketFD = createTCPIpv4Socket();

    struct sockaddr_in *serverAddress = createIPv4Address("",2000);

    int result = bind(serverSocketFD, (struct sockaddr *)serverAddress, sizeof(*serverAddress));
    // this server port 2000 listen incoming connection

    if(result == 0)
        printf("socket was bound successful.....\n ");
    
    int listenResult = listen(serverSocketFD, 10);
    // incoming socket to connect server socket upto only 10 means server 10 connection store in qurue
    struct sockaddr_in clientAddress;
    int clientAddressSize = sizeof(clientAddress);
    int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &clientAddressSize);

    char buffer[1024];
    recv(clientSocketFD, buffer, 1024, 0);

    printf("Response was %s \n", buffer);

    return 0;

}