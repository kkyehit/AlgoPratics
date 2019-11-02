#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 1000000

using namespace std;

typedef long long int int64;

int64 initTree(vector<int64> &tree, vector<int64> &list, int node, int start, int end){
	if(start == end) return tree[node] = list[start];
	return tree[node] = initTree(tree, list, node * 2, start, (start + end )/2) + initTree(tree, list, node * 2 + 1, (start + end )/2 + 1, end); 
}

void update(vector<int64> &tree, int node, int start, int end, int index, int64 value){
	if(index < start || end < index) return;
	tree[node] += value;
	if(start != end){
		update(tree, node * 2, start, (start + end) / 2, index, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	}
}
int64 getSum(vector<int64> &tree, int node, int start, int end, int left, int right){
	if(end < left || right < start) return 0;
	if(left <= start && end <= right ) return tree[node];
	return getSum(tree, node * 2, start, (start + end) / 2, left, right) + getSum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void){
	int N, M, K;
	int64 tmp;
	vector<int64> list(MAX_N, 0);
	vector<int64> tree(MAX_N * 4, 0);
	scanf("%d %d %d",&N,&M,&K);
	for(int i = 0; i < N; i++){
		scanf("%lld",&tmp);
		list[i] = tmp;
	}
	
	initTree(tree, list, 1, 0, N - 1);
	
	int64 opt, a, b;
	for(int i = 0; i < M + K; i++){
		scanf("%lld %lld %lld",&opt,&a,&b);
		if(opt == 1) {
			update(tree, 1, 0, N - 1, a - 1, b - list[a - 1] );
			list[a - 1] = b;
		}
		else if(opt == 2) printf("%lld\n",getSum(tree, 1, 0, N - 1, a - 1, b - 1));
	}
}