#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>

#define MAX_N 12
#define INF 2123456789
using namespace std;

int board[MAX_N][MAX_N];
int n;

int core[MAX_N][2];
int c;

int maxValue;
int maxConnect;

int search(int index, int connected, int value){
	if(index >= c){
		if(maxConnect < connected) {
			maxValue = value;
			maxConnect = connected;
		}
		else if(maxConnect == connected) maxValue = min(maxValue,value);
		else if(maxConnect > connected) return INF;
		return maxValue;
	} 
	
	if(core[index][0] == 0 ||core[index][0] == n - 1 ||core[index][1] == 0 ||core[index][1] == n - 1) return search(index + 1,connected + 1,value);
	
	int res = INF, tmp = 0;
	int i;
	for(i = core[index][0] - 1; i >= 0; i--){
		if(board[i][core[index][1]] != 0) break;
		board[i][core[index][1]] = -1;
		tmp++;
	}
	if(i < 0) res = min(res, search(index + 1,connected + 1,value + tmp));
	for( ++i ;i < core[index][0]; i++){
		board[i][core[index][1]] = 0;
		tmp--;
	}
	
	for(i = core[index][0] + 1; i < n; i++){
		if(board[i][core[index][1]] != 0) break;
		board[i][core[index][1]] = -1;
		tmp++;
	}
	if(i == n)  res = min(res, search(index + 1,connected + 1,value + tmp));
	for( --i ;i > core[index][0]; i--){
		board[i][core[index][1]] = 0;
		tmp--;
	}
	
	for(i = core[index][1] - 1; i >= 0; i--){
		if(board[core[index][0]][i] != 0) break;
		board[core[index][0]][i] = -1;
		tmp++;
	}
	if(i < 0) res = min(res, search(index + 1,connected + 1,value + tmp));
	for( ++i ;i < core[index][1]; i++){
		board[core[index][0]][i] = 0;
		tmp--;
	}
	
	for(i = core[index][1] + 1; i < n; i++){
		if(board[core[index][0]][i] != 0) break;
		board[core[index][0]][i] = -1;
		tmp++;
	}
	if(i == n)  res = min(res, search(index + 1,connected + 1,value + tmp));
	for( --i ;i > core[index][1]; i--){
		board[core[index][0]][i] = 0;
		tmp--;
	}
	search(index + 1, connected, value);
	
	return res;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 1; i <=T; i++){
		c = 0;
		scanf("%d",&n);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++){
				scanf("%d",&board[j][k]);
				if(board[j][k] == 1){
					core[c][0] = j;
					core[c++][1] = k;
				}
			}
		maxValue = maxConnect  = -1;search(0,0,0);
		printf("#%d %d\n",i,maxValue);

		/*for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++)
				printf("%02d ",board[j][k]);
			printf("\n");
		}*/
	}
}