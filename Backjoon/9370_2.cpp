#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX_N 2000
#define INF 99999999

using namespace std;

int n, m, t;
int s, g, h;

void search(vector< vector<pair<int, int> > > &vl, vector<int> &vt){
	priority_queue<pair<int, int>, vector<pair <int,int> >, greater<pair<int,int> > > pq;
	int res[n];
	vector<int> r;
	
	for(int i = 0; i < n; i++) res[i] = INF;
	
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		int x = pq.top().second, cost = pq.top().first;
		pq.pop();
		
		if(res[x] < cost) continue;
		
		for(int i = 0; i < vl[x].size(); i++){
			if(vl[x][i].second + cost <= res[vl[x][i].first]){
				res[vl[x][i].first] = vl[x][i].second + cost;
				pq.push(make_pair(res[vl[x][i].first], vl[x][i].first));
			}
		}
	}
	sort(vt.begin(), vt.end());
	for(int i = 0 ; i < t; i++){
		if( res[vt[i]] != INF && res[vt[i]] % 2 != 0)r.push_back(vt[i]+1);
	}
	int i;
	
	for(i = 0 ; i < r.size(); i++){
		printf("%d ",r[i]);
	}
	printf("\n");
}

int main(void){
	freopen("./9370_in","r",stdin);
	int T;
	int a,b,d,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n, &m, &t);
		scanf("%d %d %d",&s, &g, &h);
		
		vector< vector<pair<int, int> > > vl(n);
		
		for(int i = 0; i < m; i++){
			scanf("%d %d %d",&a,&b,&d);
			if((a == g && b == h)||(a == h && b == g)){
				vl[a - 1].push_back(make_pair(b - 1, d * 2 - 1));
				vl[b - 1].push_back(make_pair(a - 1, d * 2 - 1));
			}
			else{
				vl[a - 1].push_back(make_pair(b - 1, d * 2));
				vl[b - 1].push_back(make_pair(a - 1, d * 2));
			}
		}
		
		vector<int> vt;
		
		for(int i = 0; i < t; i++){
			scanf("%d",&x);
			vt.push_back(x - 1);
		}
		
		s--;g--;h--;
		search(vl,vt);
	}
}