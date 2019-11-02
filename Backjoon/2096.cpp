#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 100000
#define INF 2123456789

using namespace std;

const int d[3] = {-1, 0, 1};
int board[MAX_N][3];
int cache[MAX_N + 1][3][2];
int minValue, maxValue;
int n;

bool isRange(int x){
	if( 0 <= x && x < 3) return true;
	return false;
}

int search(int index, int locate,int flag){
	if(index == n) return board[index - 1][locate];
	
	if(cache[index][locate][flag] != -1) return cache[index][locate][flag];
	
	cache[index][locate][flag] = (flag == 0)? 0 : INF;
	for(int i = 0 ; i < 3; i++)
		if(isRange(locate + d[i]))
			cache[index][locate][flag] = (flag == 0)? 
			max(cache[index][locate][flag], search(index + 1, locate+d[i], flag) + board[index - 1][locate]) : 
			min(cache[index][locate][flag], search(index + 1, locate+d[i], flag) + board[index - 1][locate]);
	return cache[index][locate][flag];
}

int main(void){
	scanf("%d ",&n);
	for(int i = 0; i < n; i++) scanf("%d %d %d",&board[i][0],&board[i][1],&board[i][2]);
	memset(cache, -1, sizeof(cache));
	search(0,1,0);search(0,1,1);
	printf("%d %d\n",cache[0][1][0],cache[0][1][1]);
}