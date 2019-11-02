#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#define MAX_N 10000
#define MAX_W 10000
#define INFY 20000*10000

using namespace std;

int onetagon[2][MAX_N+1];
int cache[MAX_N + 1][MAX_N + 1];
int n,w;

int search(int u, int d){
	if((u > n) && (d > n)) return 0;
	if((u > n) || (d > n)) return 1;
	
	int &ret = cache[u][d];
	if(ret != -1) return ret;
	
	if((u == n) || (d == n)){
		if(u == d)return ((onetagon[0][u] + onetagon[0][d]) <= w)?1:2;
		if(u < d){
			int uSum = ((onetagon[0][u] + onetagon[0][u + 1]) <= w)?2:3;
			int udSum = ((onetagon[0][d] + onetagon[1][d]) <= w)?2:3;
			//cout<<" u "<<u<<" d "<<d<<" uSum "<<uSum<<" udSum "<<udSum<<endl;
			return ret = min(uSum,udSum);
		}
		int dSum = ((onetagon[1][d] + onetagon[1][d + 1]) <= w)?2:3;
		int udSum = ((onetagon[0][u] + onetagon[1][u]) <= w)?2:3;
			//cout<<" u "<<u<<" d "<<d<<" dSum "<<dSum<<" udSum "<<udSum<<endl;
		return ret = min(dSum,udSum);
	}
	
	int res = INFY;
	int uSum = ((onetagon[0][u] + onetagon[0][u + 1]) <= w)?1:2;
	int dSum = ((onetagon[1][d] + onetagon[1][d + 1]) <= w)?1:2;
	if(u == d){
		int udSum = ((onetagon[0][u] + onetagon[1][d]) <= w)?1:2;
		res = min(res, udSum + search(u + 1, d + 1));
		res = min(res, uSum + dSum + search(u + 2, d + 2));
		if(dSum == 1)res = min(res, 1 + dSum + search(u + 1, d + 2));
		if(uSum == 1)res = min(res, uSum + 1 + search(u + 2, d + 1));
	}else if(u < d){
		if(uSum == 1)res = min(res, uSum + search(u + 2, d));
		res = min(res, 1 + search(u + 1, d));
	}else if(d < u){
		if(dSum == 1) res = min(res, dSum + search(u, d + 2));
		res = min(res, 1 + search(u, d + 1));
	}
	//cout<<"u "<<u<<" d "<<d<<" usum "<<uSum<<" dSum "<<dSum<<endl;
	//cout<<"res "<<res<<endl;
	return ret = res;
}

int initAndSearch(){
	
	int res = INFY;
	memset(cache,-1,sizeof(cache));
	
	onetagon[0][n] = onetagon[0][0];
	onetagon[1][n] = onetagon[1][0];
	
	const int pivot[4][2]={{0,0},{0,1},{1,0},{1,1}};
	for(int i = 0; i < 4; i++){
		res = min(res,search(pivot[i][0],pivot[i][1]));
	}
	return res;
}



int main(void){
	freopen("1006in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&w);
		for(int i = 0; i < 2 ; i++)
			for(int j = 0; j < n ; j++)
				scanf("%d",&onetagon[i][j]);
		printf("%d\n",initAndSearch());
	}
}