#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 100
#define MAX_INT 2123456789

using namespace std;

const int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int board[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];

int M, N;
int startX, startY, startD;
int endX, endY, endD;
int minLevel;

struct point{
	int y, x, direct, level;
	point(int _y, int _x, int _d, int _l){
		y = _y; x = _x; direct = _d; level = _l;
	}
	
	bool operator < (const point &p) const{
		if(level < p.level) return true;
		return false;
	}
};

int main(void){
	scanf("%d %d",&M, &N);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			scanf("%d",&board[i][j]);
	
	scanf("%d %d %d",&startY, &startX, &startD);
	scanf("%d %d %d",&endY, &endX, &endD);
	startY--; startX--; startD--;
	endY--; endX--; endD--;
	minLevel = MAX_INT;
	
	memset(visit, -1, sizeof(visit));
	
	queue<point> q;
	q.push(point(startY,startX,startD,0));
	while(!q.empty()){
		int y = q.front().y, x = q.front().x, direct = q.front().direct ,level = q.front().level;
		q.pop();
		
		if(level > minLevel) continue;
		
		if(visit[y][x] == -1) visit[y][x] = level;
		else if(visit[y][x] > level) visit[y][x] = level;
		else continue;
		
		if(y == endY && x == endX){
			if(direct == endD) minLevel = level;
			else if((direct / 2) == ( endD / 2 ) ) minLevel = min(minLevel, level + 2);
			else if((direct / 2) != ( endD / 2 ) ) minLevel = min(minLevel, level + 1);
		}
		
		for(int i = 0; i < 4; i++){
			int newY = y + d[i][0], newX = x + d[i][1], newlevel = level;
			if(0<=newY && newY < M && 0<= newX && newX < N){
				if(board[newY][newX] == 1) continue;
				else if(direct == i) newlevel = level;
				else if((direct / 2) == ( i / 2 ) ) newlevel += 2;
				else if((direct / 2) != ( i / 2 ) ) newlevel += 1;
				for(int j = 1; j <= 3; j++){
					newY = y + d[i][0] * j; newX = x + d[i][1] * j;
					if(0<=newY && newY < M && 0<= newX && newX < N){
						if(board[newY][newX] == 1) break;
						q.push(point(newY,newX,i, newlevel + 1));
					}
				}
			}
		}
	}
	printf("%d\n",minLevel);
}