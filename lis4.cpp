#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;

void initCache(int *cache,int n){
	for(int i = 0; i < n; i++)
		cache[i] = -1;
}

int path[101];
int search(int* seq, int* cache, int n, int index){
	if(n == 0) return 0;
	int &ret = cache[index+1];
	if(ret != -1) return ret;
	ret = 1;
	int temp = 1,bestNext = -1;
	for(int i = index+1; i < n; i++){
		if(index == -1 || seq[index] < seq[i]) {
			temp += search(seq,cache,n,i);
		}
		if(temp > ret) {
			ret = temp;
			bestNext = i;
		}
		temp = 1;
	}
	path[index+1] = bestNext;
	return ret;
}
void printPath(int n){
	for(int i =0; i < n; i ++)
		cout<<path[i]<<" ";
	cout<<endl;
}
void printSeq(vector<int> &s){
	for(int i =0; i < s.size(); i ++)
		cout<<s[i]<<" ";
	cout<<endl;
}
void reconstruct(int start, vector<int> &seq, int *s){
	if(start != -1) seq.push_back(s[start]);
	int next = path[start+1];
	if(next != -1) reconstruct(next,seq,s);
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
		memset(path,-1,sizeof(int)*101);
		scanf("%d",&N);
		seq = new int[N];	
		cache = new int[N+1];
		initCache(cache,N+1);
		
		for(int j = 0; j < N; j++)
			scanf("%d",seq+j);
		
		res[i] = search(seq,cache,N,-1) - 1;
		vector<int> s;
		reconstruct(-1,s,seq);
		printSeq(s);
	
		printPath(N);
		
		delete seq;
		delete cache;
	}
	for(int i = 0; i < C; i++)
		printf("%d\n",res[i]);
}