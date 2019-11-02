#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "cstring"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "string.h"
#include "arpa/inet.h"

#define BUF_LEN 128

using namespace std;

int main(int argc, char* argv[]){
	int s,n;
	char *haddr;
	struct sockaddr_in server_addr;
	
	char buf[BUF_LEN+1];
	
	if(argc != 2){
		printf("usage : %s ip_Address\n",argv[0]);
		exit(0);
	}
	haddr = argv[1];
	if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0){
		printf("cannot create socket\n");
		exit(0);
	}
	
	bzero((char *)&server_addr, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(3000);
	
	if(connect(s, (struct sockaddr *)&server_addr,sizeof(server_addr))){
		printf("can`t connect.\n");
		exit(0);
	}
	
	while((n = recv(s, buf, BUF_LEN, 0 )) > 0){
		buf[n] = '\0';
		printf("%s",buf);
	}
	close(s);
	
	return 0;
}