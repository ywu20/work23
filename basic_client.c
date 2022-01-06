#include "pipe_networking.h"


int main() {
  int server;

  server = client_setup();
  printf("client setup\n");
  //client(server);

  char inputs[50];
   while(1){
   printf("Enter the word: \n");
   fgets(inputs,50,stdin);
   inputs[strlen(inputs)-1] = '\0';
   printf("You inputed: %s\n",inputs);
   int a = write(server, inputs, 50);
   char result [50];
   read(server,result,50);
   printf("Response from server: %s\n", result);
 }

}
