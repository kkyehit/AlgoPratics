#include <stdio.h>
#include <cstring>
#include <queue>
#include <stack>

#define MAX_N 12
#define MAX_M 6

using namespace std;

const int d[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

char board[MAX_N][MAX_M];
bool searched[MAX_N][MAX_M];

stack<pair<int, int> > drop(stack<pair<int, int> > &s){
	stack<pair<int, int> > res;
	vector<pair<int, int> > v;
	while(!s.empty()){
		int y = s.top().first, x = s.top().second;
		s.pop();
		if(board[y][x] == '.') continue;
		char C = board[y][x];
		
		while(y < MAX_N -1){
			if(board[y+1][x] == '.'){	
				board[y][x] = '.';
				board[y+1][x] =C;
				y++;
			}
			else break;
		}
		v.push_back(make_pair(y,x));
	}
	for(int i = v.size() -1; i >= 0; i--)
		res.push(v[i]);
	return res;
}

bool isSame(char a[MAX_N][MAX_M],char b[MAX_N][MAX_M]){
	for(int i = 0; i < MAX_N; i++)
		for(int j = 0; j < MAX_M; j++)
			if(a[i][j] != b[i][j]) return false;
	return true;
}
bool isRange(int y, int x){
	if(0 <= y && y < MAX_N && 0 <= x && x < MAX_M) return true;
	return false;
}

int search(stack<pair<int, int> > &_s){
	char prev[MAX_N][MAX_M];
	int cnt = 0;
	memcpy(prev, board, sizeof(board));
	while(true){
		stack<pair<int, int> > s(_s);
		memset(searched, 0, sizeof(searched));
		
		while(!s.empty()){
			int y = s.top().first, x = s.top().second;
			s.pop();
			
			if(board[y][x] == '.') continue;
			stack<pair<int, int> > store, sear;
			store.push(make_pair(y,x));
			sear.push(make_pair(y,x));
			
			searched[y][x] = true;
			
			while(!sear.empty()){		
				int _y = sear.top().first, _x = sear.top().second;
				sear.pop();
				
				if(board[_y][_x] == '.') continue;
				
				for(int i = 0 ; i < 4; i++){
					if(isRange(_y + d[i][0],_x + d[i][1])){
						if(board[_y][_x] == board[_y + d[i][0]][_x + d[i][1]]){
							if(searched[_y + d[i][0]][_x + d[i][1]]) continue;
							searched[_y + d[i][0]][_x + d[i][1]] = true;
							store.push(make_pair(_y + d[i][0],_x + d[i][1]));
							sear.push(make_pair(_y + d[i][0],_x + d[i][1]));
						}
					}
				}
			}
			if(store.size() >= 4){
				cnt++;
				while(!store.empty()){
					board[store.top().first][store.top().second] = '.';
					//printf("remove : %d %d\n",store.top().first,store.top().second);
					store.pop();
				}
				//printf("\n");
			}
		}
		_s = drop(_s);
		
		/*for(int i = 0; i < MAX_N; i++){
			for(int j = 0; j < MAX_M; j++){
				printf("%c[%c] ",board[i][j],prev[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		
		if(isSame(prev,board)) break;
		else memcpy(prev, board, sizeof(board));
		
	}
	return cnt;
}

int main(void){
	freopen("./11559_in","r",stdin);
	stack<pair<int, int> > s;
	for(int i = 0; i < MAX_N; i++)
		for(int j = 0; j < MAX_M; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
			else if(board[i][j] != '.') s.push(make_pair(i,j));
		}
	printf("%d\n",search(s));
}