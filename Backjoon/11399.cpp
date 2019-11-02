#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

#define MAX_N 1000

using namespace std;

int p[MAX_N], n;

int main(void){
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",p + i);
	sort(p,p + n);
	
	int pSum[MAX_N],res = 0;
	memset(pSum,0,sizeof(pSum));
	res = pSum[0] = p[0];
	for(int i = 1 ; i < n; i++){
		pSum[i] = pSum[i - 1] + p[i];
		res += pSum[i];
	}
	printf("%d\n",res);
}