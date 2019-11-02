#include <stdio.h>
#include <deque>
#include <iostream>
#include <string>
#include <cstring>
#define MAX_L 100000

using namespace std;

int my_stoi(char *str){
	int res = 0;
	for(int i = 0 ; i<strlen(str); i++){
		res *= 10;
		res += str[i] -'0';
	}
	return res;
}

int main(void){
	freopen("./5430_in","r+",stdin);
	int T, n, tmp, index;
	bool start = false, error = false;
	char c;
	scanf("%d",&T);
	while(T--){
		char p[MAX_L] = {0};
		char list[MAX_L*4 + 2] = {0};
		start = true;
		error = false;
		
		scanf("%s %d %s",p,&n,list);
		
		deque<int> dq;
		char *next = strtok(list,"[,]");
		while(next != NULL){
			dq.push_back(my_stoi(next));
			next = strtok(NULL,"[,]");
		}
		
		for(int i = 0 ; i < strlen(p); i++){
			if(p[i] == 'R') start = !start;
			else{
				if(dq.empty()){
					error = true;
					break;
				}
				if(start) dq.pop_front();
				else dq.pop_back();
			}
		}
		
		if(error){
			printf("error\n");
		}else{
			printf("[");
			if(start && !dq.empty()){
				for(int i = 0 ; i < dq.size()-1; i++){
					printf("%d,",dq[i]);
				}printf("%d",dq.back());
			}else if(!dq.empty()){
				for(int i = dq.size() -1 ; i > 0; i--){
					printf("%d,",dq[i]);
				}printf("%d",dq.front());
			}
			printf("]\n");
		}
	}
}