#include <stdio.h>

#include <sys.types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h>
int fd; // socket
int portNo=1234;
int backlog =5; //max queue size

int main(){
 fd = socket(AF_INET, SOCK_STREAM,0);
 if(fd != -1)
  if(bind(fd, (int *)&portNo, sizeof(portNo)) == 0){
   if(listen(fd,backlog != -1){
    
   }
  }//else CANT BIND
 } //else CANT CREATED SCKT
 printf("%s",errno);
	
}
