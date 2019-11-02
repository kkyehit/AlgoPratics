#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 300

using namespace std;

int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int board[MAX_N][MAX_N];
int group[MAX_N][MAX_N];
int N, M;

bool search1(int y, int x){
	if(x > M) return search1(y + 1, 0);
	if(y > N) return false;
	
	if(board[y][x] == 0) return search1(y, x + 1);
	
	int sea = 0;
	for(int i = 0; i < 4; i++)
		if(0<= y + d[i][0] && y + d[i][0] < N && 0<= x + d[i][1] && x + d[i][1] < M)
			if(board[y + d[i][0]][x + d[i][1]] == 0) sea++;
	if(sea == 0) return search1(y, x + 1);
	else search1(y, x + 1);
	
	board[y][x] = board[y][x] - sea;
	if(board[y][x] < 0) board[y][x] = 0;
	return true;
}

void search2(int y, int x){
	group[y][x] = 1;
	for(int i = 0; i < 4; i++)
		if(0<= y + d[i][0] && y + d[i][0] < N && 0<= x + d[i][1] && x + d[i][1] < M)
			if(board[y + d[i][0]][x + d[i][1]] != 0 && group[y + d[i][0]][x + d[i][1]] == 0) 
				search2(y + d[i][0], x + d[i][1]);
}

int main(void){
	scanf("%d %d",&N, &M);
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d",&board[i][j]);
	
	int res = 0;
	
	while(search1(0, 0)){
		res++;
	
		memset(group, 0, sizeof(group));
		int gr = 1;
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if(group[i][j] == 0 && board[i][j] != 0){
					search2(i, j);
					gr++;
				}
		
		if(gr > 2) break;
	}
	
	printf("%d\n",res);
}