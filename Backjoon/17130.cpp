#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 1000
using namespace std;

const int d[3][2] = {{0, 1}, {1, 1}, {-1, 1}};
int N, M;
int ry, rx;

char board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

bool isRange(int y, int x){
	if(0<=y && y < N && 0 <= x && x < M) return true;
	return false;
}

int search(int y, int x){
	if(!isRange(y, x)) return -1;
	if(board[y][x] == '#') return -1;
	if(cache[y][x] != -2) return cache[y][x];
	int res = 0;
	if(board[y][x] == 'O') {
		for(int i = 0; i < 3; i++) res = max(res, search(y + d[i][0], x + d[i][1]));
		return cache[y][x] = res;
	}
	res = -1;
	for(int i = 0; i < 3; i++) res = max(res, search(y + d[i][0], x + d[i][1]));
	return cache[y][x] =  (res == -1)? -1 : (res + ((board[y][x] == 'C')? 1 : 0));
	
}

int main(void){
	scanf("%d %d",&N, &M);
	for(int i =0; i < N; i++){
		for(int j = 0 ; j < M; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
			else if(board[i][j] == 'R') { ry = i; rx = j; }
		}
	}
	fill(&cache[0][0], &cache[MAX_N-1][MAX_N], -2);
	printf("%d\n",search(ry,rx));
}