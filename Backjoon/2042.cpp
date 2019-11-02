#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

#define MAX_N 1000000

using namespace std;

long long int list[MAX_N + 1] = {0};
long long int tree[MAX_N*4] = {0};
int treeSize = 0;
int N, M, K;

int init(int left, int right, int node){
	if(right < left) return 0;
	treeSize = max(treeSize, node + 1);
	if(right == left) return tree[node] = list[left];
	return tree[node] = init(left, (right + left)/2, node * 2) + init((right + left)/2 + 1, right, node * 2 + 1);
}

/*
void set(int left, int right, int node, int locate, int value){
	if(locate < left || locate < right) return ;
	tree[node] += value;
	if(left < right){
		set(left, (left + right) / 2, node * 2, locate, value);
		set((left + right) / 2 + 1, right, node * 2 + 1, locate, value);
	}
}
*/

int set(int locate, int value){
	int left = 1, right = N, mid;
	int node = 1;
	stack<int> s;
	while(left < right){
		s.push(node);
		mid = (left + right)/2;
		if(locate <=mid){
			right = mid;
			node *= 2;
		}else{
			left = mid + 1;
			node = node * 2 + 1;
		}
	}
	tree[node] = value;
	while(!s.empty()){
		int n = s.top();
		s.pop();
		
		tree[n] = tree[n*2] + tree[n*2 + 1];
	}
}

long long int getRagne(int nodeL, int nodeR, int node, int l, int r){
	//printf("nodeL : %d nodeR : %d node : %d l : %d r : %d\n",nodeL,nodeR,node,l,r);
	if(nodeR < nodeL) return 0;
	if(nodeR < l || r < nodeL) {
	//	printf("return 0\n");
		return 0;
	}
	if(l <= nodeL && nodeR <= r) {
		return tree[node];
	}
	
	int mid = (nodeR + nodeL) /2;
	return getRagne(nodeL, mid, node * 2,  l, r) + getRagne(mid + 1, nodeR, node * 2 + 1,  l, r);
}

int main(void){

	scanf("%d %d %d",&N, &M, &K);
	for(int i =1; i <= N; i++) scanf("%lld",&list[i]);
	
	queue<pair<int, int> > q;
	q.push(make_pair(0, N - 1));
	
	memset(tree, 0, sizeof(tree));
	init(1, N, 1);
	
/*	printf("\n");
	for(int i = 1 ;i < treeSize; i++){
		printf("%lld ",tree[i]);
	}
	printf("\n");
	*/
	int opt, a, b;
	for(int i = 0; i < (M + K); i++){
		scanf("%d %d %d", &opt, &a, &b);
		if(opt == 1){
			set(a, b);
			list[a] = b;
			//set(1, N, 1, a, b - list[a]);
			
			/*for(int i = 1 ;i < treeSize; i++){
				printf("%lld ",tree[i]);
			}
			printf("\n");
			*/
		}
		else if(opt == 2){
			printf("%lld\n",getRagne(1, N, 1, a, b));
		}
	}
}