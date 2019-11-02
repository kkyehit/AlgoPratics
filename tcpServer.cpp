#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"

#include "string"
#include "cstring"
#include "arpa/inet.h"
#include "unistd.h"

#include "sstream"

#define BUF_LEN 128

using namespace std;

string intToString(int n){
	stringstream s;
	s<<n;
	return s.str();
}

int main(int argc, char* argv[]){
	char buffer[BUF_LEN];
	struct sockaddr_in server_addr, client_addr;
	char temp[20];
	int server_fd, client_fd;
	unsigned len, msg_size;
	
	string s;
	char *cstr;
	
	if((server_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
        printf("cannot open stream socket\n");
        exit(0);
	}
	memset(&server_addr, 0x00, sizeof(server_addr));
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(3000);
	
	if(bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        printf("Server : Can't bind local address.\n");
        exit(0);
	}
	if(listen(server_fd, 5) < 0){
		
        printf("Server : Can't listening connect.\n");
        exit(0);
	}
	
	memset(buffer, 0x00, sizeof(buffer));
    printf("Server : wating connection request.\n");
    len = sizeof(client_addr);

	while(1){
		client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &len);
		if(client_fd < 0){
	        printf("Server: accept failed.\n");
    	    exit(0);
		}
		inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
		printf("Server : %s client connected.\n", temp);
 		
		time_t t = time(NULL);
 		struct tm tm = *localtime(&t);
	
		s = intToString(tm.tm_year+1900) +"년 " + intToString(tm.tm_mon+1) +"월 "+intToString(tm.tm_mday) +"일 // "+ intToString(tm.tm_hour) +" : "+ intToString(tm.tm_min) +" : "+ intToString(tm.tm_sec)+'\n';
		
		cstr = (char *)malloc(s.size() * sizeof(char));
		strcpy(cstr,s.c_str());
		
		send(client_fd,cstr,s.length(),0);
		close(client_fd);
	}
}