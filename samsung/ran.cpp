#include <iostream>
#include <stdio.h>

using namespace std;

void _7964(){
	printf("1\n");
	int n = 300000, d= 2;
	printf("%d %d\n",n,d);
	for(int i = 0; i < n; i++){
		printf("%d ",0);
	}
	printf("\n");
}

void _7830(){
	printf("1\n750 750\n");
	for(int i = 0; i < 750; i++){
		for(int j = 0; j < 750; j++){
			printf("%d",1);
		}
		printf("\n");
	}
}

int main(){
	_7830();
}