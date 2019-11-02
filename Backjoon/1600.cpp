#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX_WH 200
#define MAX_K 30
#define MAX_VALUE 999999

using namespace std;

const int dh[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
const int dm[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int K;
int W, H;
int board[MAX_WH][MAX_WH];
int cache[MAX_K][MAX_WH][MAX_WH];

int mini;

bool canMove(int y, int x, int dy, int dx){
	if((0<= (y + dy)) && ((y + dy) < H) &&
	   (0<= (x + dx)) && ((x + dx) < W) ){
		if(board[y+dy][x+dx] == 0)
			return true;
	}
	return false;
}

int getMini(int k, int y, int x){
	if( (y == H -1) && (x == W -1) ) return 0;
	
	int res = MAX_VALUE;
	
	if(k > 0){
		for(int i = 0; i < 8; i++){
			if(canMove(y,x,dh[i][0],dh[i][1])){
				board[y +dh[i][0]][x + dh[i][1]] = -1;
				res = min(res, 1+getMini(k -1,y + dh[i][0],x + dh[i][1]));
				board[y +dh[i][0]][x + dh[i][1]] = 0;
			}
		}
	}
	for(int i = 0; i < 4; i++){
		if(canMove(y,x,dm[i][0],dm[i][1])){
			board[y +dm[i][0]][x + dm[i][1]] = -1;
			res = min(res, 1+getMini(k,y + dm[i][0],x + dm[i][1]));
			board[y +dm[i][0]][x + dm[i][1]] = 0;
		}
	}
	return res;
}

int main(void){
	freopen("./1600_in","r",stdin);
	memset(board,0,sizeof(board));
	memset(cache,-1,sizeof(cache));
	mini = 999999;
	scanf("%d",&K);
	scanf("%d %d",&W, &H);
	for(int i = 0; i < H; i++){
		for(int j = 0; j< W; j++){
			scanf("%d",&board[i][j]);
		}
	}
	int res = getMini(K,0,0);
	if(res == MAX_VALUE) printf("-1\n");
	else printf("%d\n",res);
}