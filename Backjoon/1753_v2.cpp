#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_INT 2123456789
#define MAX_V 20000

using namespace std;

int V,E,K;
int visit[MAX_V];
vector<pair<int,int> > list[MAX_V];

int main(void){
	scanf("%d %d %d",&V,&E,&K);
	fill_n(visit, MAX_V, MAX_INT);
	
	K--;
	int u,v,w;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&u,&v,&w);
		u--;v--;
		list[u].push_back(make_pair(v,w));
	}
	
	priority_queue<pair<int, int> , vector< pair<int, int> >, greater<pair<int, int> > >pq;
	pq.push(make_pair(0, K));
	
	visit[K] = 0;
	
	while(!pq.empty()){
		int value = pq.top().first, point = pq.top().second;
		int list_n = list[point].size();
		pq.pop();
		
		if(visit[point] < value) continue;
		
		for(int i = 0; i < list_n; i++){
			int nextp = list[point][i].first, nextv = list[point][i].second;
			if(nextv + value < visit[nextp]){
				visit[nextp] = nextv + value;
				pq.push(make_pair(nextv + value, nextp));
			}
		}
		
	}
	for(int i = 0; i < V ; i++){
		if(visit[i] == MAX_INT) printf("INF\n");
		else printf("%d\n",visit[i]);
	}
	
}