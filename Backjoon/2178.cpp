#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

int n, m;
bool board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool canGo(int y, int x){
	if(0 <= y && y < n && 0<= x && x < m)
		if(board[y][x] && !visit[y][x])
			return true;
	return false;
}

int search(){
	queue<pair<pair<int,int>,int> > q; 
	q.push(make_pair(make_pair(0,0),1));
	while(!q.empty()){
		int y = q.front().first.first, x = q.front().first.second, level = q.front().second;
		if(y == n - 1 && x == m - 1) return level;
		q.pop();
		for(int i = 0; i < 4; i++)
			if(canGo(y + d[i][0], x + d[i][1])){
				q.push(make_pair(make_pair(y + d[i][0],x + d[i][1]),level + 1));
				visit[y + d[i][0]][x + d[i][1]] = true;
			}
	}
	return -1;
}

int main(void){
	freopen("./2178_in","r",stdin);
	char c;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j++){
			scanf("%c",&c);
			if(c == '\n') {
				j--;
				continue;
			}
			else if(c == '1') board[i][j] = true;
			else if(c == '0') board[i][j] = false;
			visit[i][j] = false;
		}
	printf("%d\n",search());
}
