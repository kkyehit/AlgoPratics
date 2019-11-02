#include <stdio.h>
#include <cstring>
#include <stack>
#define MAX_N 500

using namespace std;
const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int M, N;
int board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int search(int y, int x){
	if(y == 0 && x == 0) return 1;
	
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i = 0 ; i < 4; i++){
		int _y = y + d[i][0], _x = x + d[i][1];
		if(0 <= _y && _y < M && 0 <= _x && _x < N)
			if(board[_y][_x] > board[y][x]) 
				ret += search(_y, _x);
		
	}
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
	printf("%d\n",search(M -1, N - 1));
}