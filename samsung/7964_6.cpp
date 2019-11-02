#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 300000
#define INF 30000000

using namespace std;

int cache[MAX_N + 2];
bool door[MAX_N + 2];
int n, d;

int search(){
	//if(door[index])cache[index] = min(cache[index], 0 + search(index + i));
	//else cache[index] = min(cache[index], 1 + search(index + i));
	int index = 0, res = 0;
	while(index < n + 1){
		if(!door[index]) res++;
		int i = 0;
		bool ch = false;
		for(int i = index + d; i > index; i-- ){
			if(i > n + 1) continue;
			if(door[i]){
				index = i;
				ch = true;
				break;
			}
		}
		if(!ch){
			index = index + d;
		}
	}
	
	return res;
}

int main(void){
	int T, tmp;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d",&n,&d);
		for(int j = 1; j <= n; j++){
			scanf("%d",&tmp);
			if(tmp) door[j] = true;
			else door[j] = false;
		}
		door[0] = door[n + 1] =true;	
		printf("#%d %d\n",i,search());
	}
}