#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 300

using namespace std;

int board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int n, m;

const int d[4][2] = {{1, 0},{0, 1}, {-1, 0}, {0, -1}};

bool isRange(int y, int x){
	if(0 <= y && y < n && 0<= x && x < m) return true;
	return false;
}
void search(int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visit[y][x] = true;
	
	while(!q.empty()){
		int _y = q.front().first, _x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
			if(isRange(_y + d[i][0], _x + d[i][1]))
				if(visit[_y + d[i][0]][_x + d[i][1]] == false && board[_y + d[i][0]][_x + d[i][1]] != 0){
					visit[_y + d[i][0]][_x + d[i][1]] = true;
					q.push(make_pair(_y + d[i][0],_x + d[i][1]));
				}
	}
}

int main(void){
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&board[i][j]);
	
	queue<pair<pair<int, int>, int> > q;
	int sea = 0;
	int res = 0;
	
	while(true){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				sea = 0;
				if(board[i][j] != 0){
					for(int k = 0; k < 4; k++)
						if(isRange(i + d[k][0], j + d[k][1]))
							if(board[i + d[k][0]][j + d[k][1]] == 0) sea++;
					q.push(make_pair(make_pair(i, j), sea) );
				}
			}
		if(q.empty()){
			res = 0;
			break;
		}
		
		res++;
		while(!q.empty()){
			board[q.front().first.first][q.front().first.second] -= q.front().second;
			if(board[q.front().first.first][q.front().first.second] < 0) board[q.front().first.first][q.front().first.second] = 0;
			q.pop();
		}
		
		int group = 0;
		memset(visit, 0, sizeof(visit));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(board[i][j] != 0 && visit[i][j] == false){
					group++;
					search(i,j);
				}
		if(group > 1) break;
	}
	printf("%d\n",res);
}