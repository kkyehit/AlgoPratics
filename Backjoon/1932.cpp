#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX 500
#define INFY 1<<30

using namespace std;

int triangle[MAX][MAX];
int cache[MAX][MAX];

int search(int y, int x, const int &n){
	//cout<<y<<" "<<x<<" "<<n<<endl; 
	if(y == n) return 0;
	if(x < 0 || x >= y + 1) return 0;
	
	int & ret = cache[y][x];
	if(ret != -1) return ret;
	//cout<<triangle[y][x]<<" "<<max(search(y + 1,x -1),search(y+1, x + 1))<<endl;
	return ret = triangle[y][x] + max(search(y + 1,x ,n),search(y+1, x + 1,n));
}

int main(void){
	memset(cache,-1,sizeof(cache));
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i + 1; j++)
			scanf("%d",&triangle[i][j]);
	cout<<search(0,0,n)<<endl;
}