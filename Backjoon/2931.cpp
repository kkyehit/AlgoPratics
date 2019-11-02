#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 750
using namespace std;

const int d[4][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}};
const char b[7] = {'|','-','+','1','2','3','4'};
vector<pair<int, int> > cToD[7];

int R, C;
char board[MAX_N][MAX_N];
pair<int, int> M, Z;

bool isRange(int y, int x){
	if( 0<=y && y < R && 0<=x && x < C) return true;
	return false;
}

int Y, X, TYPE;
bool search(int y, int x, int direct, bool added){
//printf("y : %d x : %d d : %d\n",y,x,direct);
	if(!isRange(y,x)) return false;
	if(y == Z.first && x == Z.second) return true;
//printf("y : %d x : %d d : %d\n",y,x,direct);
	
	if(board[y][x] == '.'){
		if(added) return false;
		
		int newDirect = -1;
		for(int i = 0; i < 7; i++){
			for(int j = 0; j < cToD[i].size(); j++){
				if(cToD[i][j].first == direct){
					board[y][x] = b[i];
					newDirect = cToD[i][j].second;
					if( search(y + d[newDirect][0], x + d[newDirect][1], newDirect, true) ) {
						Y = y; X = x; TYPE = i;
						board[y][x] = '.';
						return true;
					}
					break;
				}
			}
		}
		
		board[y][x] = '.';
		return false;
	}
	
	int flag = -1;
	if(board[y][x] == '|') flag = 0;
	else if(board[y][x] == '-') flag = 1;
	else if(board[y][x] == '+') flag = 2;
	else if('1' <= board[y][x]  && board[y][x] <= '4') flag = 3 + (board[y][x] - '1');
	
	if(flag == -1) return false;
	
	for(int i = 0; i < cToD[flag].size(); i++)
		if(cToD[flag][i].first == direct)
			return search(y + d[cToD[flag][i].second][0], x + d[cToD[flag][i].second][1], cToD[flag][i].second, added);
		
	
	return false;
}

int main(void){
	freopen("./2931_in","r",stdin);
	
	scanf("%d %d",&R,&C);
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
			else if(board[i][j] == 'M') M = make_pair(i,j);
			else if(board[i][j] == 'Z') Z = make_pair(i,j); 
		}
	
	/*printf("%d %d\n",R,C);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}*/
	
	cToD[0].push_back(make_pair(0,0));
	cToD[0].push_back(make_pair(2,2));
	
	cToD[1].push_back(make_pair(1,1));
	cToD[1].push_back(make_pair(3,3));

	cToD[2].push_back(make_pair(1,1));
	cToD[2].push_back(make_pair(3,3));
	cToD[2].push_back(make_pair(0,0));
	cToD[2].push_back(make_pair(2,2));

	cToD[3].push_back(make_pair(2,1));
	cToD[3].push_back(make_pair(3,0));
	
	cToD[4].push_back(make_pair(0,1));
	cToD[4].push_back(make_pair(3,2));	
	
	cToD[5].push_back(make_pair(1,2));
	cToD[5].push_back(make_pair(0,3));
	
	cToD[6].push_back(make_pair(1,0));
	cToD[6].push_back(make_pair(2,3));	
	
	int res = false;
	for(int i = 0; i < 4; i++)
		if(board[M.first + d[i][0]][M.second + d[i][1]] != '.' &&
		   (res = search(M.first + d[i][0], M.second + d[i][1], i, false)) )
			break;
	if(!res)
		for(int i = 0; i < 4; i++)
			if (search(M.first + d[i][0], M.second + d[i][1], i, false))
				break;
			
	//printf("m[%d %d]\n",M.first,M.second);
	//search(M.first + d[2][0], M.second + d[2][1], 2, false);
	printf("%d %d %c\n",Y + 1,X + 1,b[TYPE]);
}