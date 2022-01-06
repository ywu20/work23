#include "pipe_networking.h"


int main() {
int sd= server_setup();
while(1){
int client = server_accept(sd);

  printf("client setup\n");
  char inputs[50];
  while (read(client, inputs, 50)){

  printf("Server got: %s \n", inputs);

  char response[50];
  int i;
  for(i=0;i<50;i++){
    response[i] = toupper(inputs[i]);
  }
  write(client, response, 50);
 }

 }


return 0;
}
