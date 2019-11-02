#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#define MAX_N 10000
#define MAX_W 10000
#define INFY 20000*10000

using namespace std;

int onet[2][MAX_N+5];
int cache[MAX_N + 5][2];
int n,w;

int search(int u, int flag){
	if( u > n) return 0;
	if(u == n){ 
		if(flag == 0)
			return ((onet[0][u] + onet[0][u]) <= w) ? 1 : 2;
		return 1;
	}
	
	int &ret = cache[u][flag];
	if(ret != -1) return ret;
	
	int res = INFY;
	if(flag == 0){
		int f1 = ((onet[0][u] + onet[1][u]) <= w)? 1 : 2;
		res = min(res, search(u + 1,0) + f1);
		
		int f2 = ((onet[0][u] + onet[0][u + 1]) <= w)? 1 : 2;
		int f3 = ((onet[1][u] + onet[1][u + 1]) <= w)? 1 : 2;
		int f4 = f2 + f3;
		res = min(res, search(u + 2,0) + f4);
		
		res = min(res, search(u,1) + 1);
		res = min(res, search(u + 1,1) + 1 + f2);
		
	}else{
		int f1 = ((onet[1][u] + onet[1][u + 1]) <= w)? 1 : 2;
		int f2 = ((onet[0][u + 1] + onet[1][u + 2]) <= w)? 1 : 2;
	
		res = min(res, search(u + 2,1) + f1 + f2);
		res = min(res, search(u + 2,0) + f1 + 1);
	}
	//cout<<"u "<<u<<" flag "<<flag<<" res "<<res <<endl;
	return ret = res;
}

int initAndSearch(){
	
	int res = INFY;
	
	for(int i = 0 ; i < 4; i++){
		memset(cache,-1,sizeof(cache));
		if( i == 0) onet[0][n] = onet[1][n] = INFY;
		else swap(onet[i%2][n],onet[i%2][0]);
		//cout<<search(0,0)<<endl;
		res = min(res,search(0,0) - 2);
	}
	
	return res;
}



int main(void){
	freopen("1006in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(onet,0,sizeof(onet));
		scanf("%d %d",&n,&w);
		for(int i = 0; i < 2 ; i++)
			for(int j = 0; j < n ; j++)
				scanf("%d",&onet[i][j]);
		printf("%d\n",initAndSearch());
	}
}