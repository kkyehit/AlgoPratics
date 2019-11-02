#include <stdio.h>
#include <cstring>
#include <stack>
#define MAX_N 12
#define MAX_M 6

using namespace std;

const int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

char board[MAX_N][MAX_M];
bool cache[MAX_N][MAX_M];

bool isRange(int _y, int _x){
	if(0 <= _y && _y < MAX_N && 0 <= _x && _x < MAX_M) return true;
	return false;
}
bool drop(int _y, int _x){
	if(_x < 0) return drop(_y - 1, MAX_M -1);
	if(_y < 0 ) return true;
	
	if(board[_y][_x] == '.' ) return drop(_y, _x -1);
	
	char C = board[_y][_x];
	int y = _y;
	while(y < MAX_N -1){
		if(board[y+1][_x] == '.'){	
			board[y][_x] = '.';
			board[y+1][_x] =C;
			y++;
		}
		else break;
	}
	return drop(_y, _x -1);
}

int search(int _y, int _x){
	if(_x < 0) return search(_y - 1, MAX_M -1);
	if(_y < 0 ) return 0;
	
	if(board[_y][_x] == '.' || cache[_y][_x]) return search(_y, _x -1);
	
	int res = 0;
	stack<pair<int, int> > s;
	stack<pair<int, int> > ds;
	s.push(make_pair(_y,_x));
	ds.push(make_pair(_y,_x));
	cache[_y][_x] = true;
	while(!s.empty()){
		int y = s.top().first, x = s.top().second;
		s.pop();
		for(int i = 0; i < 4; i++){
			if(isRange(y + d[i][0], x + d[i][1])){
				//printf("[%d,%d]%c [%d,%d]%c\n",_y,_x,board[_y][_x] ,y + d[i][0],x + d[i][1], board[y + d[i][0]][x + d[i][1]]);
				if(board[_y][_x] == board[y + d[i][0]][x + d[i][1]] && !cache[y + d[i][0]][x + d[i][1]]){
					s.push(make_pair(y + d[i][0], x + d[i][1]));
					ds.push(make_pair(y + d[i][0], x + d[i][1]));
					cache[y + d[i][0]][x + d[i][1]] = true;
				}
			}
		}
	}
	if(ds.size() >= 4){
		res = 1;
		while(!ds.empty()){
			//printf("remove[%c] %d %d\n",board[ds.top().first][ds.top().second],ds.top().first,ds.top().second);
			board[ds.top().first][ds.top().second] = '.';
			ds.pop();	
		}
	}
	return res + search(_y, _x - 1);
}

int main(void){
	freopen("./11559_in","r",stdin);
	for(int i = 0; i < MAX_N; i++)
		for(int j = 0; j < MAX_M; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
		}
	
	int res = 0;
	
	while(1){
	/*	for(int i = 0; i < MAX_N; i++){
			for(int j = 0; j < MAX_M; j++){
				printf("%c ",board[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		memset(cache, 0, sizeof(cache));
		if(search(MAX_N - 1, MAX_M - 1) == 0 ) break;
		res++;
		drop(MAX_N - 1, MAX_M - 1);
	}
	/*	for(int i = 0; i < MAX_N; i++){
			for(int j = 0; j < MAX_M; j++){
				printf("%c ",board[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	printf("%d\n",res);
	
}