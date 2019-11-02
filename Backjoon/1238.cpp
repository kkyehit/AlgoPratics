#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000
#define INF 2123456789

using namespace std;

int main(void){
	int n, m, X;
	int distanceFromX[MAX_N+1];
	vector<pair<int, int> >v[MAX_N + 1];
	scanf("%d %d %d",&n, &m, &X);
	
	int a, b, c;
	for(int i = 0 ; i < m; i++){
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;
	
	fill_n(distanceFromX, MAX_N + 1, INF);
	pq.push(make_pair(0,X));
	distanceFromX[X] = 0;
		
	while(!pq.empty()){
		int x = pq.top().second, cost = pq.top().first;
		int vsize = v[x].size();
		pq.pop();
		
		int newX, newCost;
		//printf("x %d, cost %d, vsize %d\n",x, cost, vsize);
		for(int j = 0; j < vsize; j++){
			newX = v[x][j].first; newCost = cost + v[x][j].second;
			if(newCost < distanceFromX[newX]){
				distanceFromX[newX] = newCost;
				pq.push(make_pair(newCost, newX));
			}
		}
	}
	int maxTime = 0;
	for(int i = 1; i <= n; i++){
		if(i == X) continue;
		int distanceTo[MAX_N + 1];
		fill_n(distanceTo, MAX_N + 1, INF);
		
		pq.push(make_pair(0,i));
		distanceTo[i] = 0;
		
		while(!pq.empty()){
			int x = pq.top().second, cost = pq.top().first;
			int vsize = v[x].size();
			pq.pop();
			
			int newX, newCost;
			for(int j = 0; j < vsize; j++){
				newX = v[x][j].first; newCost = cost + v[x][j].second;
				if(newCost < distanceTo[newX]){
					distanceTo[newX] = newCost;
					pq.push(make_pair(newCost, newX));
				}
			}
		}
		if(maxTime < (distanceFromX[i] + distanceTo[X]) )
			maxTime = (distanceFromX[i] + distanceTo[X]);
	}
	printf("%d\n",maxTime);
}