#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(void){
	freopen("./5430_in","r+",stdin);
	int T, n, index;
	int v[100000];
	int head, tail;
	char p[100001];
	char c;
	scanf("%d",&T);
	while(T--){
		memset(p,0,sizeof(p));
		memset(v,0,sizeof(v));
		
		scanf("%s",p);
		scanf("%d",&n);
		
		index = -1;
		while(index < n){
			c = getchar();
			if(c ==',') index++;
			else if(c =='\n') continue;
			else if(c ==']' || c =='['){
				index++;
				continue;
			} 
			else {
				v[index] *= 10;
				v[index] += c -'0';
			}
		}
		
		bool isError = false;
		head = 0;
		tail = n -1;
		
		for(int i = 0 ; i < strlen(p); i++){
			if(p[i] == 'R'){
				swap(head,tail);
			}else{
				if(head < 0 || tail < 0){
					isError = true;
					break;
				}
				if(head < tail){
					head++;
				}else{
					head--;
				}
			}
		}
		if(isError){
			printf("error\n");
			continue;
		}
		printf("[");
		if(head < tail && head >= 0){
			for(int i = head; i <= tail; i++){
				printf("%d",v[i]);
				if(i < tail)
					printf(",");
			}
		}else if(tail >= 0){
			for(int i = head; i >= tail; i--){
				printf("%d",v[i]);
				if(i > tail)
					printf(",");
			}		
		}
		printf("]\n");
	}
}