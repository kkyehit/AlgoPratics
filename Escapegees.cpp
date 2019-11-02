#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<vector>
#define MOD 1000000007
#define MAX_N 500 
#define MAX_K 100 
#define POW 65530

using namespace std;

int N,K;
/*
int ***cache;

int calc(int selected , int now, int sum){
	if(selected == K) return (sum%N == 0)? 1:0 ;
	if(now > N) return 0;
	
	int &ret = cache[selected][now][sum%N];
	if(ret != -1) return ret% MOD;

	int res = calc(selected, now + 1, sum)% MOD;
	res+= calc(selected + 1, now + 1, (sum + now) )% MOD;
	
	ret = res;
	
	return res;
}

void makeCache(){
	cache = (int ***) malloc(sizeof(int**)*(K+ 1) );
	for(int i = 0; i <= K; i++){
		cache[i] = (int **) malloc(sizeof(int*)*(N+1));
		for(int j = 0; j <= N; j++){
			cache[i][j] = (int *) malloc(sizeof(int )*(N+1));
			for(int k = 0; k <= N; k++)
				cache[i][j][k] = -1;
		}
	}
}*/
/*
int psum[501][101];
int cache[501][101];

void makePsum(){
	for(int i = 0; i <=500; i++){
		psum[i][0] = 0;
		psum[i][1] = i;
	}
	for(int i = 1; i <=N - K; i++){
		for(int j = 2; j <= K; j++){
			psum[i][j] += psum[i][j - 1] + 1;
		}
	}
}
int calc2(int start,int need, int sub){
	int res = 0;
	for(int i = need; i > 0; i--){
		for(int j = start; j < N - i; j++){
			res += ( (sub + psum[start][i] ) % N == 0 ) ? 1 : 0;
		}
	}
	return res;
	
}
int calc(int start,int need){
	if(need == 0) return 0;
	if(start + need > N) return 0;
	
	int res = 0;
	for(int i = need; i > 0; i--){
		for(int j = start; j < N - i; j++){
			if(i == need) res += (psum[start][i]%N ==0)? 1:0 ;\
		}
	}
}*/


int cache[MAX_K + 1][MAX_N + 1];
void test(){
	for(int i = 0; i <= K; i++){
		for(int j = 0; j < N; j++)
			cout<<cache[i][j]<<" ";
		cout<<endl;
	}
}
int search(){
	memset(cache,0,sizeof(cache));
	int tempcache[MAX_K + 1][MAX_N + 1];
	
	for(int i = 0; i < N; i++){
		memset(tempcache,0,sizeof(tempcache));
		for(int k = 1; k <= min(i,99); k++){
			for(int j = 0; j < N; j++){
				tempcache[k + 1][ ( j + i ) % N] =(tempcache[k + 1][ ( j + i ) % N] + cache[k][j] ) % MOD;
			}
		}
		cache[1][i]++;
		for(int k = 1; k <= min(i,99); k++){
			for(int j = 0; j < N; j++){
				cache[k][j] += tempcache[k][j];
			}
		}
	}
	
	return cache[K][0];
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 0 ; i < T; i++){
		scanf("%d %d",&N,&K);
		cout<<search()<<endl;
	}
}