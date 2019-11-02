#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#define MAX_N 10

using namespace std; 

int n,m;
int chair[MAX_N][MAX_N];
int cache[MAX_N][MAX_N][1<<10][2];
const int pivot[5][2] = {{0,0},{0,-1},{0,1},{-1,-1},{-1,1}};

bool isRange(int y,int x){
	if(((0 <= x) && (x < m)) &&((0 <= y) && (y < n)))
		return true;
	return false;
}

bool checkAround(int y, int x){
	bool res = true;
	for(int i = 0; i < 5; i++)
		if(isRange(y + pivot[i][0], x + pivot[i][1])){
			if(chair[y + pivot[i][0]][x + pivot[i][1]] == 1) res = false;
		}
	return res;
}
int search(int y, int x,int up, int now,int prev){
	if(x >= m ) return search(y + 1, 0 , now, 0, 0);
	if(y >= n ) return 0;
	
	int &ret = cache[y][x][up][prev];
	if(ret != -1) return ret;
	
	int res = 0;
	if(chair[y][x] != -1)
		if(checkAround(y,x)){
			chair[y][x] = 1;
			res = max(res, 1 + search(y, x + 1, up, now || (1<<x), 1));
			chair[y][x] = 0;
		}
	res = max(res, search(y, x + 1, up, now, 0));
	
	return ret = res;
}

void test(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ",chair[i][j]);
		}
		printf("\n");
	}	
}

int main(void){
	freopen("1014.txt","r",stdin);
	int c;
	scanf("%d",&c);
	char tmp;
	while(c--){
		memset(cache,-1,sizeof(cache));
		scanf("%d %d",&n,&m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%c",&tmp);
				if(tmp == 'x') chair[i][j] = -1;
				else if(tmp == '.') chair[i][j] = 0;
				else j--;
			}
		}
		//test();
		printf("%d\n",search(0,0,0,0,0));
	}
}