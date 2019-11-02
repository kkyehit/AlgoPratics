#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_V 20000
#define MAX_E 300000
#define INF 9999999

using namespace std;

int V, E, K;

void search(vector< vector <pair<int, int> > > &v){
	int res[V];
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	
	for(int i = 0; i < V; i++)
		res[i] = INF;
	
	pq.push(make_pair(0,K));
	res[K] = 0;
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		int cost = p.first, x = p.second;
		pq.pop();
		
		if(res[x] < cost) continue;
		
		for(int i = 0 ; i < v[x].size(); i++){
			if(cost + v[x][i].second <= res[v[x][i].first]){
				res[v[x][i].first] = cost + v[x][i].second;
				pq.push(make_pair(cost + v[x][i].second,v[x][i].first));
			}
		}
	
	}
	
	for(int i = 0 ; i< V; i++){
		if(res[i] == INF)printf("INF\n");
		else printf("%d\n",res[i]);
	}
}

int main(void){
	
	freopen("1753_in","r+",stdin);
	
	int y, x, w;
	
	scanf("%d %d",&V,&E);
	scanf("%d",&K);
	
	K--;
	
	vector< vector <pair<int, int> > > v(V);
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&y,&x,&w);
		v[y-1].push_back(make_pair(x-1,w));
	}
	search(v);
}