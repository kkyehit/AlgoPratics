#include <stdio.h>
#include <cstring>
#include <stack>

#define MAX_N 750

using namespace std;

const int d[4][2] = {{-1,-1},{-1,1},{1,1},{1,-1}};

char board[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][4];
int n, m;

bool isRange(int y, int x ){
	if(0 <= y && y < n &&  0 <= x && x < m) return true;
	return false;
}

bool check(int y, int x){
	int i = 0;
	for(i = 0; i < 4; i++){
		if(cache[y][x][i] == -1) return false;
	}
	return true;
}

int init(){
	stack<pair<int, int> > s;
	s.push(make_pair(0,0));
	s.push(make_pair(0,0));
	int y, x;
	
	y = x = 0;
	while(!s.empty()){
		//printf("y %d x %d\n",y,x);
		if(isRange(y,x)){
			if(!check(y,x)){
				//printf("y %d x %d\n",y,x);
				if(board[y][x] == 1){
					for(int i = 0; i < 4; i++){
						if(isRange(y + d[i][0], x + d[i][1])){
							if(cache[y + d[i][0]][x + d[i][1]][i] == -1){
								s.push(make_pair(y + d[i][0],x + d[i][1]));
							}else{
								cache[y][x][i] = 1 + cache[y + d[i][0]][x + d[i][1]][i];
							}
						}else{
							cache[y][x][i] = 1;
						}
					}
				}else{
					for(int i = 0; i < 4; i++){
						cache[y][x][i] = 0;
					}
				}
			}
			s.push(make_pair(y,x + 1));
		}else if(0 <= y && y < n){
			s.push(make_pair(y + 1,0));
		}
		y = s.top().first; x = s.top().second;
		s.pop();
	}
}
int search(){
	stack<pair<int, int> > s;
	s.push(make_pair(0,0));
	int y, x;
	int minCrital = -1;	
	
	y = x = 0;
	while(!s.empty()){
		int length = min(cache[y][x][1],cache[y][x][2]);
		printf("%d %d %d\n",y,x,length);
		int i;
		if(isRange(y,x)){
			for(i = length; i > 1; i--){
				if(i < minCrital){
					break;
				}
				if( (i < cache[y+(d[1][0] * (i - 1))][x+(d[1][1] * (i - 1))][2] ) 
			   	&& (i < cache[y+(d[2][0] * (i - 1))][x+(d[2][1] * (i - 1))][1])){
					minCrital = i;
				}
			}	
			s.push(make_pair(y,x+1));
		}else if(0 <= y && y < n){
			s.push(make_pair(y + 1,0));
		}
		y = s.top().first; x = s.top().second;
		s.pop();
	}
	return minCrital;
}

int main(void){
	int T;
	char c;
	scanf("%d",&T);
	for(int i = 1 ; i <= T; i++){
		memset(cache,-1,sizeof(cache));
		scanf("%d %d",&n,&m);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++){
				scanf("%c",&board[j][k]);
				if(board[j][k] == '\n') k--;
				else board[j][k] = board[j][k] - '0'; 
			}
		init();
		printf("%d\n",search());
		
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++)
				for(int l = 0; l < 4; l++)
					if(cache[j][k][l] == -1) printf("cache[%d][%d][%d] == -1\n",j,k,l);
	}
}