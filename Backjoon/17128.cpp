#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 200000

using namespace std;

int initTree(vector<int> &tree, vector<int> &S, int node, int start, int end){
	if(start == end) return tree[node] = S[start];
	return tree[node] = initTree(tree, S, node * 2, start, (start + end) / 2) +initTree(tree, S, node * 2 + 1, (start + end) / 2 + 1, end) ;
}

int getSum(vector<int> &tree, int node, int start, int end, int left, int right){
	if(end < right || left < start) return 0;
	if(left <= start && end <= right) return tree[node];
	return getSum(tree, node * 2, start, (start + end) / 2, left, right) + getSum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<int> &tree, int node, int start, int end, int index, int dif){
	if(index < start || end < index) return;
	tree[node] += dif;
	if(start != end){
		update(tree, node * 2, start, (start + end)/2, index, dif);
		update(tree, node * 2 + 1, (start + end)/2 + 1, end, index, dif);
	}
}

int main(void){
	int N, Q;
	int A[MAX_N];
	scanf("%d %d",&N, &Q);
	for(int i = 0; i < N; i++) scanf("%d",&A[i]);
	
	vector<int> S(MAX_N, 0);
	int tmp = 1;
	for(int i = 0; i < N; i++){
		tmp = 1;
		int k = i;
		for(int j = 0; j < 4; j++){
			tmp *= A[k];
			if(++k == N) k = 0;
		}
		S[i] = tmp;
		//printf("%d ",S[i]);
	}
	//printf("\n");
	vector<int> tree(MAX_N * 4, 0);
	initTree(tree, S, 1, 0, N - 1);
	
	int chCow;
	for(int i = 0; i < Q; i++){
		scanf("%d",&chCow);
		chCow--;
		A[chCow] = (-1) * A[chCow];
		for(int j = 0; j < 4; j++){
			S[chCow] = (-1) * S[chCow];
			update(tree, 1, 0, N - 1, chCow, 2 * S[chCow]);
			if(chCow == 0) chCow = N -1;
			else chCow--;
		}
		printf("%d\n",tree[1]);
	}
}