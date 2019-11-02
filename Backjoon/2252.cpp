#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 32000

using namespace std;

int n, m;
int main(void){
	vector<int > v[MAX_N + 1];
	int cnt[MAX_N + 1] = {0};
	scanf("%d %d",&n,&m);
	
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		cnt[b]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(cnt[i]==0) q.push(i);
	
	while(!q.empty()){
		int p = q.front();
		int pn = v[p].size();
		q.pop();
		
		printf("%d ",p);
		
		for(int i = 0; i < pn; i++)
			if( --cnt[v[p][i]] == 0)
				q.push(v[p][i]);
	}
	printf("\n");
}