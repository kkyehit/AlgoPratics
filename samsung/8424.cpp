#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
#define MAX_N 1000

using namespace std;

struct point{
	int x, y, level;
	point(int _x, int _y, int _level){
		x = _x; y = _y; level = _level;
	}
};

int n;
bool board[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];

int main(void){
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		memset(board, false, sizeof(board));
		memset(visited, -1, sizeof(visited));
		scanf("%d",&n);
		int x, y;
		for(int i = 0; i < n; i++) {
			scanf("%d %d",&x, &y);
			board[x][y] = true;
		}
		
		int maxVal = -1;
		queue<point> q;
		for(int i = 1; i <= n; i++){
			if(board[1][i]) q.push(point(1, i, 0));
		}
		while(!q.empty()){
			int x = q.front().x, y = q.front().y, level = q.front().level;
			q.pop();
			
			for(int i = 1; i <= n; i++){
				if(board[y][i]) {
					if(visited[i] != -1){
						maxVal = max(maxVal, level - visited[y]);
						continue;
					}
					q.push(point(y, i, level + 1));
					visited[i] = level + 1;
				}
			}
		}
		printf("#%d %d\n",t,maxVal);
	}
}