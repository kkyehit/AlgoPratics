#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

vector<int> list(MAX_N);
int n, m;

vector<int> treeInit(vector<vector<int> > &tree, int node, int start, int end){
	if(start == end) {
		tree[node].push_back(list[start]);
		return tree[node];
	}
	vector<int> left = treeInit(tree, node * 2, start, (start + end)/ 2);
	vector<int> right = treeInit(tree, node * 2 + 1, (start + end)/ 2 + 1, end);
	int leftSize = left.size(), rightSize = right.size();
	int leftIndex = 0, rightIndex = 0;
	while(leftIndex < leftSize && rightIndex < rightSize){
		if(left[leftIndex] <= right[rightIndex])
			tree[node].push_back(left[leftIndex++]);
		else
			tree[node].push_back(right[rightIndex++]);
	}
	for(;leftIndex < leftSize;) tree[node].push_back(left[leftIndex++]);
	for(;rightIndex < rightSize;) tree[node].push_back(right[rightIndex++]);
	return tree[node];
}

int getCnt(vector< vector<int> > &tree, int node, int start, int end, int left, int right, int k){
	if(end < left || right < start) return 0;
	if(left <= start && end <= right) return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	return getCnt(tree, node * 2, start, (start + end) / 2, left, right, k) + getCnt(tree, node * 2 + 1, (start + end) /2 + 1, end, left, right, k);
}

int main(void){
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++) scanf("%d",&list[i]);
	int i, j, k;
	
	
	vector< vector<int> > tree(MAX_N * 4, vector<int>());
	treeInit(tree, 1, 0, n -1);
	while(m--){
		scanf("%d %d %d",&i, &j, &k);
		int left = -2123456789, right = 2123456789;
		int mid;
		while(left <= right){
			mid = (left + right) / 2;
			int kth = getCnt(tree, 1, 0, n - 1, i - 1, j - 1, mid);
			if( kth < k) left = mid + 1;
			else right = mid - 1;
		}
		printf("%d\n",left);
	}
}