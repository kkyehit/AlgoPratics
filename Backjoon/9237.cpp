#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX_N 100000

using namespace std;

int n;
int tree[MAX_N];

bool cmp(int a, int b){
	return a > b;
}

int main(void){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",tree + i);
	sort(tree,tree + n, cmp);
	/*for(int i = 0; i < n; i++)
		printf("%d ",tree[i]);
	printf("\n");*/
	
	for(int i = 0; i < n; i++)
		tree[i] += (i + 1);
	sort(tree,tree + n, cmp);
	
	printf("%d",tree[0] + 1);
}