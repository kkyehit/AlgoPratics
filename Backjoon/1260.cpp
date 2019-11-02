#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N, M, V;
int board[1000][1000];
bool visit[1000];

void dfs(){
	memset(visit, 0, sizeof(visit));
	stack<int> s;
	vector<int> res;
	s.push(V);
	
	while(!s.empty()){
		int index = s.top();
		s.pop();
		
		if(visit[index] == 1) continue;
		visit[index] = 1;
		res.push_back(index + 1);
		
		for(int i = N - 1; i >= 0; i--){
			if(board[index][i] == 1 && visit[i] == 0){
				s.push(i);
			}
		}
	}
	int i = 0;
	for(; i < res.size()-1; i++){
		printf("%d ",res[i]);
	}
	printf("%d",res[i]);
}

void bfs(){
	memset(visit, 0, sizeof(visit));
	vector<int> res;
	queue<int> q;
	q.push(V);
	
	while(!q.empty()){
		int index = q.front();
		q.pop();
		
		if(visit[index] == 1) continue;
		
		visit[index] = 1;
		res.push_back(index + 1);

		for(int i = 0; i < N; i++){
			if(board[index][i] == 1 && visit[i] == 0){
				q.push(i);
			}
		}
	}
	int i = 0;
	for(; i < res.size()-1; i++){
		printf("%d ",res[i]);
	}
	printf("%d",res[i]);
}

int main(void){
	freopen("./1260_in","r",stdin);
	int y, x;
	memset(board, 0, sizeof(board));
	scanf("%d %d %d",&N, &M,&V);
	V--;
	for(int i = 0 ; i < M; i++){
		scanf("%d %d",&y,&x);
		board[y-1][x-1] = board[x-1][y-1] = 1;
	}
	dfs();
	printf("\n");
	bfs();
	printf("\n");
}