#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#define MOD 20091101

using namespace std;

int N,K;
int psum[100001],D[100000];
void makePsum(){
	psum[0] = 0;
	for(int i = 1 ; i <= N; i++)
		psum[i] =( psum[i - 1] + D[i - 1] ) % K;
}
int first(){
	vector<long long> count(K,0);
	for(int i = 0; i <=N; i++)
		count[psum[i]]++;
	int res = 0;
	for(int i = 0; i < K; i++)
		if(count[i] >= 2) 
			res = (res + (count[i] * (count[i] -1))/2)%MOD;
	return res;
}

int second(){
	int res = 0,start = 0;
	for(int i = 1; i <= N; i++){
		for(int j = start; j < i; j++){
			if(psum[i] == psum[j]){
				start = i;
				res++;
				break;
			}
		}
	}
	return res;
}
int second2(){
	int res = 0;
	vector<int> prev(K,0);
	
	prev[0]++;
	for(int i = 1; i <= N; i++){
		if(prev[psum[i]]){
			res++;
			prev = vector<int>(K,0);
		}
		prev[psum[i]]++;
	}
	return res;
}
void search(){
	makePsum();
	cout<<first()<<" "<<second2()<<endl;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&N,&K);
		for(int j = 0; j < N; j++)
			scanf("%d",&D[j]);
		search();
	}
}