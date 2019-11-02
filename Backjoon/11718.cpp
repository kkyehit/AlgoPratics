#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void){
	char buf[2048];
	int nread;
	while((nread = read(STDIN_FILENO, buf, 2048)) > 0){
		write(STDOUT_FILENO, buf, nread);
	}
}