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
	cache[0] = cache[n + 1] = 0;
	for(int i = n; i >= 0; i--){
		cache[i] = INF;
		for(int j = 1; j <= d; j++){
			//printf("%d %d\n",i,j);
			if(i + j > n + 1) break;
			if(door[i]) cache[i] = min(cache[i], cache[i + j]);
			else cache[i] = min(cache[i], 1 + cache[i + j]);
		}
	}
	return cache[0];
}

int main(void){
	int T, tmp;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
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