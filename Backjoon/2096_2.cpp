#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 100000
#define INF 2123456789

using namespace std;

const int d[3] = {-1, 0, 1};
char board[MAX_N][3];
int minValue, maxValue;
int n;

bool isRange(int x){
	if( 0 <= x && x < 3) return true;
	return false;
}

int search( int flag){
	int cache[2][3] = {0};
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			int tmp = (flag == 0)? 0 : INF;
			for(int k = 0; k < 3; k++){
				if(isRange(j + d[k])){
					tmp = (flag == 0)? max(tmp, board[i][j] + cache[(i+1) % 2][j + d[k]]) :min(tmp, board[i][j] + cache[(i+1) % 2][j + d[k]]);
				}
			}
			cache[i % 2][j] = tmp;
		}
	}
	int res = (flag == 0)? 0 : INF;
	for(int i = 0; i < 3; i++) res = (flag == 0) ? max(res, cache[0][i]) :min(res, cache[0][i]);
	return res;
}

int main(void){
	scanf("%d ",&n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < 3; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] < '0' || '9' < board[i][j] == '\n' ) j--;
			else board[i][j] = board[i][j] - '0';
		}
	printf("%d %d\n",search(0),search(1));
}