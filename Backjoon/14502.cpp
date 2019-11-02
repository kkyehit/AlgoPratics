#include <stdio.h>
#include <cstring>
#include <vector>
#include <stack>
#define MAX_NM 8

using namespace std;

const int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int N, M;
int board[MAX_NM][MAX_NM];

void test(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%d",board[i][j]);
		}
		printf("\n");
	}
}

int maxinum;
int getZero(){
	int res = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(board[i][j] == 0) res++;
	return res;
}

void spread(vector<pair<int, int> > &v,int flag){
	stack<pair<int, int> > s;
	
	for(int i = 0; i < v.size(); i++)
		s.push(v[i]);

	while(!s.empty()){
		pair<int, int> p = s.top();
		s.pop();
		for(int i = 0 ; i < 4; i++){
			if( 0 <= p.first + d[i][0] && p.first + d[i][0] < N && 
			  0 <= p.second + d[i][1] && p.second + d[i][1] < M){
				if(board[p.first + d[i][0]][p.second + d[i][1]] != 1 &&
					board[p.first + d[i][0]][p.second + d[i][1]] != flag){
					board[p.first + d[i][0]][p.second + d[i][1]] = flag;
					s.push(make_pair(p.first + d[i][0],p.second + d[i][1]));
				}
			}
		}
	}
}


void put1(vector<pair<int, int> > &v, int cnt,int _i, int _j){
	if(cnt == 3){
		spread(v,2);
		maxinum = max(maxinum, getZero());
		spread(v,0);
		for(int i = 0; i < v.size(); i++)
			board[v[i].first][v[i].second] = 2;
		return;
	}
	for(int i = _i; i < N; i++){
		for(int j = (i ==_i )?_j:0 ; j < M; j++){
			if(board[i][j] == 0){
				board[i][j] = 1;
				put1(v,cnt + 1,i,j);
				board[i][j] = 0;
			}
		}
	}
}

int main(void){
	freopen("./14502_in","r",stdin);
	memset(board, 0, sizeof(board));
	scanf("%d %d", &N, &M);
	
	vector<pair<int, int> > v;
	
	maxinum = -1;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			scanf("%d",&board[i][j]);
			if(board[i][j] == 2) v.push_back(make_pair(i,j));
		}
	}
	put1(v,0,0,0);
	printf("%d\n",maxinum);
//	spread(v,2);
	
//	spread(v,0);
//	for(int i = 0; i < v.size(); i++)
//		board[v[i].first][v[i].second] = 2;

}