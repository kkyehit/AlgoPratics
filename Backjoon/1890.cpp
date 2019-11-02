#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 100
using namespace std;

const int d[2][2] = {{1,0},{0,1}};
typedef long long int int64;
int64 cache[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int n;

int64 search(int y, int x){
	if(y == n - 1 && x == n - 1) return 1;
	
	int64 &ret = cache[y][x];
	if(ret != -1) return  ret;
	
	int64 p = board[y][x];
	ret = 0;
	for(int i = 0; i < 2; i++) 
		if(0<= y +d[i][0]*p && y +d[i][0] < n*p && 0<= x +d[i][1]*p && x+ d[i][1]*p < n)
			ret += search(y+d[i][0]*p, x+d[i][1]*p);
	return ret;
}

int main(void){
	scanf("%d",&n);
	
	for(int i =0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&board[i][j]);
	
	memset(cache, -1, sizeof(cache));
	printf("%lld\n",search(0,0));
}