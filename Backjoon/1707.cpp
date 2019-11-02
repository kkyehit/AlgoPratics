#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX_N 20000

using namespace std;

int V, E;
int point[MAX_N + 1];

int main(void){
	int t;
	int a, b;
	bool res;
	scanf("%d",&t);
	V = E = 0;
	while(t--){
		scanf("%d %d",&V, &E);
		vector<int> v[V+1];
		
		for(int i = 0; i < E; i++){
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		memset(point, -1, sizeof(point));
		res = true;
		
		queue<pair<int, int> > q;
		while(true){
			int x;
			for(x = 0; x < V; x++) if(point[x] == -1) break;
			if(x == V) break;
			
			q.push(make_pair(x, 1));
			point[x] = 1;
			while(!q.empty()){
				int p = q.front().first, status = q.front().second;
				q.pop();
			
				int vSize = v[p].size();
				for(int i = 0; i < vSize; i++){
					//printf("p : %d v[p][i] : %d status : %d\n",p, v[p][i], status);
					if(point[v[p][i]] == p) continue;
					if(point[v[p][i]] == -1){
						point[v[p][i]] = (status == 0) ? 1 : 0;
						q.push(make_pair(v[p][i], point[v[p][i]]));
					}else if(point[v[p][i]] == status){
						res = false;
						break;;
					}
				}
				if(res == false) break;
			}
		}
		if(res == false) printf("NO\n");
		else printf("YES\n");
	}
}