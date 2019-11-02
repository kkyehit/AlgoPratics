#include <stdio.h>
#define MAX_N 15

using namespace std;

const int d[8][2] = {{1,0},{1,1},{0, 1},{-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
int board[MAX_N][MAX_N];
int n;

void test(){
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
}

bool isRange(int y, int x){
	if( 0<= y && y < n && 0<= x && x < n) return true;
	return false;
}

void make_board(int _y, int _x, int _b){
	board[_y][_x] += _b;
	for(int i = 0; i < 8; i++){
		int y = _y + d[i][0], x = _x + d[i][1];
		while(isRange(y,x)){
			board[y][x] += _b;
			y = y + d[i][0];
			x = x + d[i][1];
		}
	}
}

int search(int y){
	if(y >= n ) return 1;
	int res = 0;
	for(int i = 0; i < n; i++){
		if(board[y][i]) continue;
		make_board(y, i, 1);
		
		res += search(y + 1);
		make_board(y, i, -1);
	}
	return res;
}
int main(void){
	scanf("%d",&n);
	printf("%d\n",search(0));
}