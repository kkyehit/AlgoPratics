#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>

using namespace std;

int cache[101][101];
int search(int pre,int n){
	if( n == 0) return 1;
	if(pre == -1){
		int res = 0;
		for(int i =1; i <= n; i++){
			res += search(i,n-i);
			res %= 10000000;
		}
		return res;
	}
	int &ret = cache[pre][n];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i =1; i <= n; i++){
		ret += search(i,n-i)*(pre+i-1);
		ret %= 10000000;
	}
	
	return ret;
}

int main(void){
	int C,n;
	memset(cache,-1,sizeof(int)*101*101);
	search(-1,100);
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d",&n);
		cout<<search(-1,n)<<endl;
	}
}