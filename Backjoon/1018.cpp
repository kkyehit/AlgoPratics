#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define INFY 999999

using namespace std;
char board[50][50];
int n, m;

int search(int pivoty, int pivotx, int y, int x, char flag){
	if((x - pivotx) == 8) return search(pivoty, pivotx, y + 1, pivotx, (flag =='W')?'B':'W');
	if((y - pivoty) == 8) return 0;
	
	//cout<<" "<<y<<" "<<x<<" "<<flag<<" "<<board[y][x]<<endl;
	
	if(board[y][x] == flag) return search(pivoty,pivotx,y,x + 1, (flag =='W')?'B':'W');
	return 1 + search(pivoty,pivotx,y,x + 1, (flag =='W')?'B':'W');
}

int slice(){
	int res = INFY;
	for(int i = 0 ; i <= n - 8 ; i++)
		for(int j = 0; j <= m - 8; j++){
			res = min(res,search(i,j,i,j,'W'));
			res = min(res,search(i,j,i,j,'B'));
		}
	return res;
}
int main(void){
	freopen("1018.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < m; j++){
			scanf("%c",&board[i][j]);
			if(board[i][j] == '\n') j--;
		}
	printf("%d\n",slice());
}