#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX 11

using namespace std;

int cache[MAX + 1];

int search(int n){
	if(n < 0 ) return 0;
	if(n == 0) return 1;
	
	int &ret = cache[n];
	if(ret != -1) return ret;
	
	return ret = search(n - 1) + search (n - 2) + search(n - 3);
}

int main(void){
	memset(cache,-1,sizeof(cache));
	int n, res, t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res = search(n);
		printf("%d\n",res);
	}
}