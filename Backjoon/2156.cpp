#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 10000

using namespace std;

int cache[MAX_N][2];
int wine[MAX_N];
int n;

int search(int index, int flag){
	if(index > n) return 0;
	
	int &ret = cache[index][flag];
	if(ret != -1) return ret;
	
	ret = max(search(index + 1, 0), search(index + 2, 0)+wine[index]);
	if(flag == 0) ret = max(ret, search(index +1, 1) +wine[index]);
	
	return ret;
}

int main(void){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&wine[i]);
	
	memset(cache, -1, sizeof(cache));
	printf("%d\n",search(0,0));
	
}