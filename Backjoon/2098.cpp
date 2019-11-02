#include<stdio.h>
#include<cstring>
#include<iostream>
#define MAX_N 16
#define MAX_VALUE 1000001
#define FINISH (1<<16) - 1

using namespace std;


int w[MAX_N][MAX_N];
int cache[MAX_N][FINISH];
int n;

int search(int now, int sel){
	if(sel == ((1<<n) - 1)) return (w[now][0])? w[now][0] : MAX_VALUE * MAX_N ;
	
	int &ret = cache[now][sel];
	if(ret != -1) return ret;
	
	ret = MAX_VALUE * MAX_N;
	for(int i = 0; i < n; i++)
		if(w[now][i] != 0 && ((sel & (1<<i)) ==0 ) )
			ret = min(ret, w[now][i] + search(i,sel | (1<<i) ));
	cout<<" ret "<<ret<<" now "<<now<<endl;
	return ret;
}

int main(void){
	freopen("2098in.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&w[i][j]);
	printf("%d",search(0,1));
}