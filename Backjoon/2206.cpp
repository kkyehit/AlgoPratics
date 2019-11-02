#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX_N 1000

using namespace std;
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char board[MAX_N][MAX_N];
int n, m;

struct node{
	int y, x, level;
	bool isBroken;
	node(int _y, int _x, int _level, bool _isBroken){
		y = _y; x = _x; level = _level,isBroken = _isBroken;
	}
};
bool isRange(int y,int x){
	if(0<=y && y < n && 0<=x && x < m) return true;
	return false;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] != '0' && board[i][j] != '1') j--;
		}
	bool visited[MAX_N][MAX_N][2] = {false};
	queue<node> q;
	q.push(node(0,0,1,false));
	int res = -1;
	while(!q.empty()){
		int y = q.front().y, x = q. front().x, level = q.front().level;
		bool isBroken = q.front().isBroken;
		q.pop();
		//printf("%d %d %d\n",y,x,level);
		
		if( y == n - 1 && x == m - 1){
			res = level;
			break;
		}
		
		int newY, newX;
		for(int i = 0; i < 4; i++){
			newY = y + d[i][0]; newX = x + d[i][1];
			if(isRange(newY, newX)){
				if(board[newY][newX] == '0') {
					if(visited[newY][newX][isBroken]) continue;
					q.push(node(newY,newX,level + 1,isBroken));
					visited[newY][newX][isBroken] = true;
				}
				else if(!isBroken){
					if(visited[newY][newX][!isBroken]) continue;
					q.push(node(newY,newX,level + 1,!isBroken));
					visited[newY][newX][!isBroken] = true;
				} 
			}
		}
	}
	printf("%d\n",res);
}