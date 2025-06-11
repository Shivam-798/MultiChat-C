#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main() {
    int socketFD = socket(AF_INET, SOCK_STREAM, 0); // socket funtion and requires three parameters , 
    //first one is domain, means address faimly Here i use IPv4
    //second parameter is Type of scoket either TCP or UDP  ---> SOCK_STREAM (means that we are asking for a TCP socket here)
    // third one which is the protocol determines the layer beneath the transport layer that are using, means when packet ready in transport layer then we pass them network layer
    // Here write 0  means we are saying that we want the IP Layer
    //socket always return file discripter (which is not a negative number (int)) then it means that socket is created sucessfually

    char * ip = "74.125.130.113";
    struct sockaddr_in address; // socket address structure is the parent structure we could say becase scoket API is both used for IPv4 and Ipv6
    //This sockaddr_in used IPv4

    address.sin_family = AF_INET;
    address.sin_port = htons(80);// it grabs the port number you passing it and it get the byte inside it port number unsigned sort integer
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr); //---> this function extract number from IP and unsigned it the put in address
    //address.sin_addr.s_addr; // for this ip address is an unsigned integer 
    // in IP add has four part of integer number inside it so required four bite
    // we can extract number inside a IP we left the . 
    // and make them an on-site byte and put it inside an on-site integer and then assign it to this property

    int result = connect(socketFD, (struct sockaddr *)&address, sizeof address);// specify the address of server that we want the socket connect to
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