#include <stdio.h>
#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAX_N 1000000 

using namespace std;

typedef long long int int64;

int N, M, K;
int treeSize;

int64 initTree(vector<int64> &tree, vector<int64> &list, int node, int start, int end){
	treeSize = max(treeSize, node + 1);
	if(start == end) return tree[node] = list[start] % MOD;
	return tree[node] = ((initTree(tree, list, node * 2, start, (start + end) / 2) % MOD ) * (initTree(tree, list, node * 2 + 1, (start + end) / 2 + 1, end) % MOD) ) % MOD;
}
int64 update(vector<int64> &tree,int node, int start, int end, int index, int64 value){
	if(index < start ||  end < index) return tree[node] % MOD;
	if(start == end) return tree[node] = value % MOD;	
	return tree[node] = ( (update(tree, node * 2, start , (start +end) / 2, index, value) % MOD) * ( update(tree, node * 2 + 1, (start +end) / 2 + 1, end, index, value) %MOD) ) % MOD;
}

int64 getValue(vector<int64> &tree, int node, int start, int end, int left, int right){
	if(end < left || right < start) return 1;
	if(left <= start && end <= right) return tree[node] % MOD;
	return ( (getValue(tree, node * 2, start, (start + end) / 2 , left, right) % MOD) * (getValue(tree,node * 2 + 1, (start + end) / 2 + 1, end, left, right) % MOD) ) % MOD;
}

int main(void){
	scanf("%d %d %d",&N, &M, &K);
	
	vector<int64> list(MAX_N, 0);
	vector<int64> tree(MAX_N * 4, 1);
	
	for(int i =0 ; i < N; i++)
		scanf("%lld",&list[i]);
	
	treeSize = 0;
	initTree(tree, list, 1, 0, N - 1);
	
	int64 a, b, c; 
	for(int i = 0; i < M + K; i++){
		scanf("%lld %lld %lld",&a, &b, &c);
		if(a == 1){
			list[b - 1] = c; 
			update(tree, 1, 0, N - 1, b - 1, c);
			
		}if(a == 2){
			printf("%lld\n",getValue(tree, 1, 0, N - 1, b - 1, c - 1) % MOD);
		}
	}
}