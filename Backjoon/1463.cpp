#include<stdio.h>
#include<iostream>
#include<cstring>
#define INFY 1110002

using namespace std; 

int cache[1000001];

int cal(int n){
	if(n == 1) return 0;
	
	int &ret = cache[n];
	if(ret != -1) return ret;
	
	int a, b, c;
	a = b = INFY;
	if(n % 2 == 0 ) a = cal(n / 2) + 1;
	if(n % 3 == 0 ) b = cal(n / 3) + 1;
	c =  cal(n - 1) + 1;
	return  ret = min(min(a, b),c);
}

int main(void){
	memset(cache,-1,sizeof(cache));
	int n, res = 0;
	scanf("%d",&n);
	res = cal(n);
	printf("%d\n",res);
}