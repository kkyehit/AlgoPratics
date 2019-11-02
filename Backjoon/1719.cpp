#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

#define INF 212345678
#define MAX_N 10000

using namespace std;

int main(void){
	int n, m;
	vector<pair<int, int> > v[MAX_N + 1];
	scanf("%d %d",&n,&m);
	
	int a, b, c;
	for(int i = 0;  i < m; i++){
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	
	priority_queue<pair<pair<int,int>, int> , vector< pair<pair<int,int>, int>  >, greater<pair<pair<int,int>, int> > > pq;
	for(int i = 1; i <= n; i++){
		int res[n + 1][2];
		fill_n(&res[0][0], (n + 1)*2, INF);
		res[i][0] = res[i][1] = 0;
		pq.push(make_pair(make_pair(0, i), -1));
		while(!pq.empty()){
			int x = pq.top().first.second, cost = pq.top().first.first, pivot = pq.top().second;
			int vsize = v[x].size();
			pq.pop();
			
			int newX, newCost, newPivot;
			for(int j = 0 ; j < vsize; j++){
				newX = v[x][j].first; newCost = cost + v[x][j].second;
				if(newCost < res[newX][0]){
					res[newX][0] = newCost;
					if(pivot == -1) newPivot = newX;
					else newPivot = pivot;
					res[newX][1] = newPivot;
					pq.push(make_pair(make_pair(newCost, newX), newPivot) );
				}
			}
		}
		for(int j = 1; j <= n; j++){
			if(res[j][1] == 0) printf("- ");
			else printf("%d ",res[j][1]);
		}
		printf("\n");
	
	}
}