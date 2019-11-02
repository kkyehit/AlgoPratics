#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX_N 1000
using namespace std;

const int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int board[MAX_N][MAX_N];
int m,n;

bool isRange(int y, int x){
	if(0<= y && y < n && 0 <= x && x < m) return true;
	return false;
}

int main(void){
	freopen("./7576_in","r",stdin);
	int res = 0;
	queue<pair<pair<int,int>,int> > q;
	scanf("%d %d",&m,&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%d",&board[i][j]);
			if(board[i][j] == 1) q.push(make_pair(make_pair(i,j),0));
		}
	
	if(q.size() == m * n) {
		printf("0\n");
		return 0;
	}
	while(!q.empty()){
		int y = q.front().first.first, x = q.front().first.second, day = q.front().second;
		q.pop();
		res = max(res, day);
		
		for(int i = 0; i < 4; i++){
			if(isRange(y + d[i][0],x + d[i][1])){
				if(board[y + d[i][0]][x + d[i][1]] == 0){
					board[y + d[i][0]][x + d[i][1]] = 1;
					q.push(make_pair(make_pair(y + d[i][0],x + d[i][1]),day +1));
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 0){
				res = -1;
				break;
			}
		}
	}
	printf("%d\n",res);
}