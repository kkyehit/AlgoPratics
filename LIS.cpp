#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void initCache(int *cache,int n){
	for(int i = 0; i < n; i++)
		cache[i] = -1;
}
int search(int* seq, int* cache, int n, int index){
	if(n == 0) return 0;
	int &ret = cache[index+1];
	if(ret != -1) return ret;
	ret = 1;
	int temp = 1;
	for(int i = index+1; i < n; i++){
		if(index == -1 || seq[index] < seq[i]) {
			temp += search(seq,cache,n,i);
		}
		if(temp > ret) ret = temp;
		temp = 1;
	}
	return ret;
}
int lis1(int* seq, int n){
	if(n == 0) return 0;
	int temp = 1;
	int lastnum = 0;
	int res = 1;
	for(int i = 0; i < n - 1; i++){
		lastnum = seq[i];
		for(int j = i + 1 ; j < n; j++){
			if(lastnum < seq[j]) {
				temp++;
				lastnum = seq[j];
			}
		}
		if(temp > res) res = temp;
		temp = 1;
	}
	return res;
}
int main(void){
	int C,N;
	int *seq;
	int *cache;
	int *res;
	scanf("%d",&C);
	res = new int[C];
	for(int i = 0; i < C; i++){
		scanf("%d",&N);
		seq = new int[N];	
		cache = new int[N+1];
		initCache(cache,N+1);
		for(int j = 0; j < N; j++)
			scanf("%d",seq+j);
		
		res[i] = search(seq,cache,N,-1) - 1;
		
		delete seq;
		delete cache;
	}
	for(int i = 0; i < C; i++)
		printf("%d\n",res[i]);
}