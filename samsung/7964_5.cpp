#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 300000
#define INF 30000000

using namespace std;

int cache[MAX_N + 2];
bool door[MAX_N + 2];
int n, d;

int search(int index){
	if(index >= n + 1) return 0;
	
	if(cache[index] != -1) return cache[index];
	cache[index] = INF;
	
	for(int i = index + d; i > index; i-- ){
		//if(door[index])cache[index] = min(cache[index], 0 + search(index + i));
		//else cache[index] = min(cache[index], 1 + search(index + i));
		if(index + d > n + 1) continue;
		if(door[i] == 1){
			if(door[index])cache[index] = min(cache[index], 0 + search(i));
			else cache[index] = min(cache[index], 1 + search(i));
			break;
		}
	}
	if(door[index])cache[index] = min(cache[index], 0 + search(min(index + d,n + 1)));
	else cache[index] = min(cache[index], 1 + search(min(index + d,n + 1)));
	
	return cache[index];
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
		printf("#%d %d\n",i,search(0));
	}
}