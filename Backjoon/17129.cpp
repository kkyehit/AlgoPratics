#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 3000

using namespace std;
//식구 : 2, 청국장 3, 스시 4, 맥앤치즈 5,
const int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int n, m;
int X, Y;

struct point{
	int y, x, level;
	point(int _y, int _x, int _level){
		y = _y; x = _x; level = _level;
	}
};

bool isRange(int y, int x){
	if(0<=y && y < n && 0<=x && x < m) return true;
	 return false;
}

int main(void){
	scanf("%d %d",&n, &m);
	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n'){j--;}
			if(board[i][j] == '2'){Y = i; X = j;}
		}
	
	fill(&visit[0][0], &visit[MAX_N - 1][MAX_N], false);
	
	int res = -1;
	queue<point> q;
	q.push(point(Y, X, 0));
	visit[Y][X] = true;
	while(!q.empty()){
		int y = q.front().y, x = q.front().x, level = q.front().level;
		q.pop();
		
		if(board[y][x] != '0' && board[y][x] != '2'){
			res = level;
			break;
		}
		
		for(int i = 0; i < 4; i++)
			if(isRange(y + d[i][0], x + d[i][1]) && board[y + d[i][0]][x + d[i][1]] != '1' && !visit[y + d[i][0]][x + d[i][1]]){
				visit[y + d[i][0]][x + d[i][1]] = true;
				q.push(point(y + d[i][0], x + d[i][1], level + 1));
			}
	}
	if(res == -1) printf("NIE\n");
	else printf("TAK\n%d\n",res);
}