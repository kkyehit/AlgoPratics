#include <stdio.h>
#include <cstring>
#define MAX_N 500

using namespace std;
const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int M, N;
int board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

bool canGo(int h, int y, int x){
	if(0 <= y && y < M && 0 <= x && x < N)
		if(board[y][x] < h) return true;
	return false;
}

int search(int y, int x){
	if(y == M -1 && x == N -1) return 1;
	
	int ret = cache[y][x];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i = 0 ; i < 4; i++)
		if(canGo(board[y][x], y + d[i][0], x + d[i][1]))
			ret += search(y + d[i][0], x + d[i][1]);
	return ret;
}

int main(void){
	freopen("./1520_in","r",stdin);
	memset(board, 0, sizeof(board));
	memset(cache, -1, sizeof(cache));
	scanf("%d %d",&M, &N);
	for(int i = 0 ; i < M ; i++)
		for(int j = 0 ; j < N; j++)
			scanf("%d",&board[i][j]);
	printf("%d\n",search(0,0));
}