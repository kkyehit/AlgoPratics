#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#define MAX_WH 200
#define MAX_K 30
#define MAX_VALUE 999999

using namespace std;

const int dh[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
const int dm[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int K;
int W, H;
int board[MAX_WH][MAX_WH];
bool cache[MAX_K][MAX_WH][MAX_WH];

bool canMove(int y, int x, int dy, int dx){
	if((0<= (y + dy)) && ((y + dy) < H) &&
	   (0<= (x + dx)) && ((x + dx) < W) ){
		if(board[y+dy][x+dx] == 0)
			return true;
	}
	return false;
}
int getMini(){
	queue<pair<pair<int, int>,pair<int, int> > > q;
	q.push(make_pair(make_pair(0,0),make_pair(K,0)));
	
	while(!q.empty()){
		pair<pair<int, int>,pair<int, int> > p = q.front();
		int y = p.first.first, x = p.first.second, k = p.second.first, move = p.second.second;
		q.pop();
		
		if((y == H -1) &&(x == W - 1)) return move;
		
		if(cache[k][y][x]) continue;
		cache[k][y][x] = true;
		
		
		for(int i = 0; i < 4; i++)
			if(canMove(y,x,dm[i][0],dm[i][1])){
				q.push(make_pair(make_pair(y + dm[i][0],x + dm[i][1]),make_pair(k,move + 1)));
			}
		
		if(k > 0)
			for(int i = 0; i < 8; i++)
				if(canMove(y,x,dh[i][0],dh[i][1])){
					q.push(make_pair(make_pair(y + dh[i][0],x + dh[i][1]),make_pair(k - 1,move + 1)));
				}
		
		
		
	}
	return -1;
}

int main(void){
	freopen("./1600_in","r",stdin);
	memset(board,0,sizeof(board));
	memset(cache,0,sizeof(cache));
	scanf("%d",&K);
	scanf("%d %d",&W, &H);
	for(int i = 0; i < H; i++){
		for(int j = 0; j< W; j++){
			scanf("%d",&board[i][j]);
		}
	}
	printf("%d\n",getMini());
}