#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

#define MAX_N 20000
#define MAX_M 50000

using namespace std;

int h[MAX_N + 1];
int N, M;

int main(void){
	scanf("%d %d",&N, &M);
	int a, b;
	vector<int> v[MAX_N + 1];
	for(int i = 0; i < M; i++){
		scanf("%d %d",&a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bool visit[MAX_N + 1] = {0};
	int resX = -1, resD = -1, resC = -1;
	
	queue<pair<int, int> > q;
	q.push(make_pair(1, 0));
	visit[1] = true;
	while(!q.empty()){
		int x = q.front().first, distance = q.front().second;
		q.pop();
		
		if(resD < distance){
			resD = distance;
			resX = x;
			resC = 1;
		}else if( resD == distance){
			resX = min(resX, x);
			resC++;
		}
		
		int v_size = v[x].size();
		for(int i = 0; i < v_size; i++){
			if(visit[v[x][i]]) continue;
			visit[v[x][i]] = true;
			q.push(make_pair(v[x][i], distance + 1));
		}
	}
	
	printf("%d %d %d\n",resX, resD, resC);
}