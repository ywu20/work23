#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include<sys/socket.h>
#include<netdb.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#ifndef NETWORKING_H
#define NETWORKING_H
#define ACK "HOLA"
#define WKP "mario"

#define HANDSHAKE_BUFFER_SIZE 10
#define BUFFER_SIZE 1000

int server_setup();
int client_setup();
int server_accept(int sd);

#endif
