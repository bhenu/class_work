#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <sys/time.h>

#define LISTEN_BACKLOG 49
#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)


long timevaldiff(struct timeval *starttime, struct timeval *finishtime)
{
  long msec;
  msec=(finishtime->tv_sec-starttime->tv_sec)*1000000;
  msec+=(finishtime->tv_usec-starttime->tv_usec);
  return msec;
}

int main(int argc, char const *argv[]) {
  
  // Create the socket
  int mysoc = socket(AF_INET, SOCK_STREAM, 0);
  int client;
  struct timeval current_time, recv_time;

  if (mysoc == -1) {
    handle_error("socket create");
  }

  // specify address
  struct sockaddr_in my_addr, client_addr;
  in_port_t clientport = htons(8080);
  struct in_addr clientip;
  inet_aton("10.24.0.1", &clientip);
  client_addr.sin_family = AF_INET;
  client_addr.sin_port = clientport;
  client_addr.sin_addr = clientip;

  // Connect to server
  if(connect(mysoc, (struct sockaddr *)&client_addr, sizeof(struct sockaddr)) == -1){
    handle_error("connect");
  }

  char c;
  char buf[1024];
  printf("%s\n", "ask the server to do something!");

  int i = 0;
  while((c=getchar()) != EOF){
    buf[i++] = c;
  }
  buf[i] = '\0';
  printf("%s\n", buf);

  send(mysoc, buf, strlen(buf), 0);
  int n = 0;
  i = 0;
  while((n=recv(mysoc, (void *)&buf, 1024, 0 )) > 0){
    while(i < n){
      putchar(buf[i++]);
    }
    if(buf[n-1] == '\0')
      break;
  }
  
  printf("%s\n", "ask the server to do something!");

  i = 0;
  while((c=getchar()) != EOF){
    buf[i++] = c;
  }
  buf[i] = '\0';
  printf("%s\n", buf);

  send(mysoc, buf, strlen(buf), 0);
  n = 0;
  i = 0;
  while((n=recv(mysoc, (void *)&buf, 1024, 0 )) > 0){
    while(i < n){
      putchar(buf[i++]);
    }
    if(buf[n-1] == '\0')
      break;
  }

  shutdown(mysoc, SHUT_RDWR);
  close(mysoc);
  printf("\n%s\n", "done!");
  return 0;
}


// GET http://www.google.com/ HTTP/1.1
// Host:www.google.com

// CONNECT www.google.com:443 HTTP/1.1
// Host: www.google.com:443