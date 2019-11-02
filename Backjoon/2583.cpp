#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 100
using namespace std;

int board[MAX_N][MAX_N];
int N, M, K;
const int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int fill(int y, int x){
	if(0<=y && y < M && 0<= x && x < N ){
		if(board[y][x] == -1) return 0;
		board[y][x] = -1;
		int sum = 1;
		for(int i = 0; i < 4; i++)
			sum += fill(y + d[i][0], x + d[i][1]);
		return sum;
	}
	return 0;
}
int main(void){
	memset(board,0,sizeof(0));	
	scanf("%d %d %d",&M, &N, &K);
	int x1,y1,x2,y2;
	while(K--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int i = y1; i < y2; i++)
			for(int j = x1; j < x2; j++)
				board[i][j] = -1;
	}
	
	vector<int> res;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if(board[i][j] == 0)
				res.push_back(fill(i,j));
	
	int res_size = res.size();
	sort(res.begin(), res.end());
	printf("%d\n",res_size);
	for(int i = 0; i < res_size; i++)
		printf("%d ",res[i]);
}