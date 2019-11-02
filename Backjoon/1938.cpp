#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 50
#define INF 212345678

using namespace std;

struct point{
	int y, x, l, s;
	point(int _y, int _x, int _l, int _s){
		y= _y; x = _x; l = _l; s = _s;
	}
};

const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char board[MAX_N][MAX_N];
int visit[MAX_N][MAX_N][2] = {-1};
int N;
int startX, startY, startS;
int endX, endY, endS;
	
bool isRange(int y, int x){
	if( 0 <= y && y < N && 0<= x && x < N) return true;
	return false;
}

int main(void){
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--; 
		}
	
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(board[i][j] == 'B'){
				if(isRange(i + 1, j) && isRange(i - 1, j) && board[i + 1][j] == 'B' && board[i - 1][j] == 'B'){
					startY = i; startX = j; startS = 0;
				}else if(isRange(i, j + 1) && isRange(i, j - 1) && board[i][j + 1] == 'B' && board[i][j - 1] == 'B'){
					startY = i; startX = j; startS = 1;
				}
			}
			else if(board[i][j] == 'E'){
				if(isRange(i + 1, j) && isRange(i - 1, j) && board[i + 1][j] == 'E' && board[i - 1][j] == 'E'){
					endY = i; endX = j; endS = 0;
				}else if(isRange(i, j + 1) && isRange(i, j - 1) && board[i][j + 1] == 'E' && board[i][j - 1] == 'E'){
					endY = i; endX = j; endS = 1;
				}
			}
		}
	
/*	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("startY %d startX %d startS %d\n",startY, startX, startS);
	printf("endY %d endX %d endS %d\n",endY, endX, endS);
*/	
	queue<point> q;
	q.push(point(startY,startX,0,startS));
	visit[startY][startX][startS] = 1;
	int res = 0;
	memset(visit, -1, sizeof(visit));
	while(!q.empty()){
		int y = q.front().y, x = q.front().x, level = q.front().l, status = q.front().s;
//		printf("y : %d x : %d s : %d l : %d\n",y, x, status, level);
		q.pop();
		
//		if(board[y][x] == '1') continue;
		if(status == 0){ 
			if(!isRange(y - 1, x) || !isRange(y + 1, x))continue;
			else if(board[y - 1][x] == '1' || board[y + 1][x] == '1') continue;
		}
		else if(status == 1){
			if(!isRange(y, x - 1) || !isRange(y, x + 1))continue;
			else if(board[y][x - 1] == '1' || board[y][ x + 1] == '1') continue;
		}
		
		bool canCh = true;
		for(int i = y - 1; i <= y + 1; i++)
			for(int j = x - 1; j <= x + 1; j++)
				if(!isRange(i,j) || board[i][j] == '1') canCh = false;
		
		
		if(canCh && visit[y][x][status? 0 : 1] == -1) {
			visit[y][x][status? 0 : 1] = 1;
			q.push(point(y, x, level + 1, status? 0 : 1));
		}
		
		for(int i = 0; i < 4; i++)
			if(isRange(y + d[i][0], x + d[i][1]) && visit[y + d[i][0]][x + d[i][1]][status] == -1){
				visit[y + d[i][0] ][x + d[i][1] ][status] = 1;
				if(board[y + d[i][0] ][x + d[i][1] ] == '1') continue;
				q.push(point(y + d[i][0], x + d[i][1] , level + 1, status));	
			}
		
		if(y == endY && x == endX && status == endS){
			res = level;
			break;
		}
	}
	printf("%d\n",res);
}