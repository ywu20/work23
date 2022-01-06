#include "pipe_networking.h"


/*=========================
  server_setup
  args:

  creates the WKP (upstream) and opens it, waiting for a
  connection.

  removes the WKP once a connection has been made

  returns the file descriptor for the upstream pipe.
  =========================*/

int server_setup() {
    printf("HELLO\n");
  	struct addrinfo *hints, *results;
  	hints = calloc(1, sizeof(struct addrinfo));
  	hints->ai_family = AF_INET;
  	hints->ai_socktype = SOCK_STREAM; // TCP socket
  	hints->ai_flags = AI_PASSIVE;     // only needed on server

    printf("struct done\n");
  	getaddrinfo(NULL, "50000", hints, &results); //Server sets node to NULL

    printf("set null\n");
  	int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  	bind(sd, results->ai_addr, results->ai_addrlen);
    printf("bind\n");
    listen(sd, 10);
    printf("listen\n");

    free(hints);
    freeaddrinfo(results);
  	return sd;
}

int server_accept(int sd){

  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  int client_socket = accept(sd,(struct sockaddr *)&client_address, &sock_size);
  printf("accept\n");
  return client_socket;
}
int client_setup() {
  	struct addrinfo *hints, *results;
  	hints = calloc(1, sizeof(struct addrinfo));
  	hints->ai_family = AF_INET;
  	hints->ai_socktype = SOCK_STREAM; // TCP socket
  	//hints->ai_flags = AI_PASSIVE;     // only needed on server

    printf("struct done\n");
    getaddrinfo("127.0.0.1", "50000", hints, &results); //Server sets node to NULL

    printf("getaddrinfo\n");
  	int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

    printf("Bind\n");

    connect(sd, results->ai_addr, results->ai_addrlen);
    //printf("result->aiaddr:%s", results->ai_addr);
    printf("connect\n");

    free(hints);
    freeaddrinfo(results);
  	return sd;
}
