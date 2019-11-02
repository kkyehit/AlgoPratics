#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#define MAX_N 50

using namespace std; 

const int pivot[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int field[MAX_N][MAX_N];
int n,m,k;

bool isRagne(int y, int x){
	return ((0 <= y && y < n) && (0 <= x && x < m));
}

void eraseField(int y, int x){
	field[y][x] = 0;
	for(int i = 0; i < 4; i++){
		if(isRagne(y + pivot[i][0],x + pivot[i][1])){
			if(field[y + pivot[i][0]][x + pivot[i][1]] == 1){
				eraseField(y + pivot[i][0],x + pivot[i][1]);
			}
		}
	}
}
void printField(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d ",field[i][j]);
	
	printf("\n");
	}
	
}
int search(int index){
	if(index >= n*m) return 0; 
	
	int y = index / m;
	int x = index % m;
	
	if(field[y][x] == 0) return search(index+1);
	
	eraseField(y,x);
	//cout<<y<<" "<<x<<endl;
	//printField();
	return 1+search(index + 1);
}

int main(void){
	freopen("1012.txt","r",stdin);
	int t = 0;
	scanf("%d",&t);
	while(t--){
		memset(field,0,sizeof(field));
		scanf("%d %d %d",&m,&n,&k);
		int tmp = k;
		while(tmp--){
			int y,x;
			scanf("%d %d",&x,&y);
			field[y][x] = 1;
		}
		printField();
		printf("%d\n",search(0));
	}
}