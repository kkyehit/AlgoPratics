#include <stdio.h>
#include <cstring>
#include <queue>

#define MAX_N 100

using namespace std;

char board[MAX_N][MAX_N];
bool visit[MAX_N][MAX_N];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;

int main(void){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
		}
	
	memset(visit, 0, sizeof(visit));
	queue<pair< pair<int, int>, int > > q;
	q.push(make_pair(make_pair(0,0),1) );
	visit[0][0] = true;
	
	while(!q.empty()){
		int y = q.front().first.first, x = q.front().first.second, level = q.front().second;
		q.pop();
		if(y == n - 1 && x == m - 1){
			printf("%d\n",level);
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int newY = y + d[i][0], newX = x + d[i][1];
			if(0 <= newY && newY < n && 0<= newX && newX < m){
				if( (!visit[newY][newX]) && (board[newY][newX] =='1')){
					q.push(make_pair(make_pair(newY,newX), level + 1));
					visit[newY][newX] = true;
				}
			}
		}
	}
}