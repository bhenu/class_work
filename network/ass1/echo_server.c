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
  in_port_t myport = 15000;
  struct in_addr myip;
  inet_aton("10.24.46.37", &myip);
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = myport;
  my_addr.sin_addr = myip;

  if (bind(mysoc, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in)) == -1) {
    handle_error("bind");
  }

  // Listen for connections
  if (listen(mysoc, LISTEN_BACKLOG) == -1)
    handle_error("listen");

  // Accept connections
  socklen_t client_addr_size;
  client_addr_size = sizeof(struct sockaddr_in);
  client = accept(mysoc, (struct sockaddr *)&client_addr, &client_addr_size);
  
  if (client == -1)
    handle_error("accept");
  else
    printf("%d\n", client);

  // Send/receive data
  char buf[100] = "no data";
  char response[100];
  int n = 0, i = 0;
  while((n=recv(client, (void *)&buf, 100, 0)) > 0){
    while(i < n){
      response[i] = buf[n -i - 1];
      i++;
    }
    response[i] = '\0';
    send(client, response, n+1, 0);
    if(buf[n-1] == '\0')
      break;
  }
  
  
  shutdown(mysoc, SHUT_RDWR);
  close(mysoc);
  printf("%s\n", "bye");
  return 0;
}