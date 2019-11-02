#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 100

using namespace std;

int cache[MAX_N + 1][MAX_N],n;

int search(int pre,int rest){
	if(rest == 0) return 1;
	
	int &ret = cache[pre + 1][rest];
	if(ret != -1) return ret;
	
	int res = 0,mult;
	for(int i = 1; i <= rest; i ++){
		mult = (pre == -1) ? 1:(pre + i - 1);
		res += search(i,rest - i) *mult ;
		res %=20090711;
	}
	
	return ret = res;
}

int main(void){
	int c;
	scanf("%d",&c);
	memset(cache,-1,sizeof(cache) );
	while(c--){
		scanf("%d",&n);
		int res = (n/2 != 0 && n%2 == 0) ?search(-1,n) - search(-1,n/2):search(-1,n);
		for(int i = 0; i <n; i+=2){
			res = (res - search(n-i,i/2) + 20090711 ) %20090711;
		}
		cout<<res<<endl;
	}
}