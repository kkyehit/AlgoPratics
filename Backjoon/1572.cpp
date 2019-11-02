#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 250000
#define MAX_K 5000
#define MAX_INPUT 65536

using namespace std;

typedef long long int int64;

int update(vector<int64> &tree, int node,int start, int end, int pos, int value){
	if(pos < start || end < pos) return tree[node];
	if(start == end) return tree[node] += value;
	return tree[node] = update(tree, node * 2, start, (start + end) /2 , pos, value) + 
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, pos, value);
}

int getValue(vector<int64> &tree, int node,int start, int end, int pos){
	if(start == end) return start;
	if(tree[node * 2] >= pos) return getValue( tree, node * 2, start, (start + end) / 2, pos);
	return getValue( tree, node * 2 + 1, (start + end)/2 + 1, end, pos - tree[node * 2]);
}

int main(void){
	int n,k;
	int tmp;
	vector<int> list;
	vector<int64> tree ( (MAX_INPUT + 1) * 4, 0);
	int64 sum = 0;
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i++) {scanf("%d",&tmp); list.push_back(tmp);}
	for(int i = 0; i < k - 1; i++) update(tree, 1, 0, MAX_INPUT, list[i], 1);
	for(int i = k - 1; i < n; i++) {
		update(tree, 1, 0, MAX_INPUT, list[i], 1);
		sum += getValue(tree, 1, 0, MAX_INPUT, (k + 1)/2);
		printf("sum : %lld .... list[i] : %d\n",sum,list[i]);
		update(tree, 1, 0, MAX_INPUT, list[i - k + 1], -1);
	}
	printf("%lld\n",sum);
}
