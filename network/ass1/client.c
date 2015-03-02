#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#define LISTEN_BACKLOG 49
#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)


int main(int argc, char const *argv[]) {
  // Create the socket
  int mysoc = socket(AF_INET, SOCK_STREAM, 0);
  int client;

  if (mysoc == -1) {
    handle_error("socket create");
  }
  
  // Bind with address

  /* Man page exerpt..

    struct sockaddr_in {
      sa_family_t    sin_family; // address family: AF_INET
      in_port_t      sin_port;   // port in network byte order 
      struct in_addr sin_addr;   // internet address 
    };

    // Internet address.
    struct in_addr {
      uint32_t       s_addr;     // address in network byte order 
    };

  */

  struct sockaddr_in my_addr, client_addr;
  in_port_t myport = 15003;
  struct in_addr myip;
  inet_aton("127.0.0.1", &myip);
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = myport;
  my_addr.sin_addr = myip;

  in_port_t server = 15001;
  struct in_addr serverip;
  inet_aton("127.0.0.1", &serverip);
  client_addr.sin_family = AF_INET;
  client_addr.sin_port = server;
  client_addr.sin_addr = serverip;

  if(bind(mysoc, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in)) == -1){
  	handle_error("bind");
  }

  // Connect to server
  if(connect(mysoc, (struct sockaddr *)&client_addr, sizeof(struct sockaddr)) == -1){
    handle_error("connect");
  }

  // Send/receive data
  char buf[100] = "hello";
  int n = 0, i = 0, j = 5;
  
   while(j){
    send(mysoc, buf, strlen(buf), 0);
      while((n=recv(mysoc, (void *)&buf, 100, 0 )) > 0){
        while(i < n){
          putchar(buf[i++]);
        }
        if(buf[n-1] == '\0')
          break;
      }
      j--;
    }
  

//shutdown(client, SHUT_RDWR);
//close(client);

  shutdown(mysoc, SHUT_RDWR);
  close(mysoc);
  printf("\n%s\n", "done!");
  return 0;
}
