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
	priority_queue< pair<int, pair<int, bool> >, vector< pair<int, pair<int, bool> > >, greater<pair<int, pair<int, bool> > > > pq;
	vector< pair<int, bool> > res;
	
	for(int i = 0; i < n; i++)
		res.push_back(make_pair(INF, false));
	res[s].first = 0;
	
	pq.push(make_pair(s, make_pair(0, false)));
	while(!pq.empty()){
		int x = pq.top().first, cost = pq.top().second.first;
		bool isInc = pq.top().second.second;
		pq.pop();
		
		for(int i = 0; i < vl[x].size(); i++){
			if(vl[x][i].second + cost <= res[vl[x][i].first].first){
				if(vl[x][i].second + cost == res[vl[x][i].first].first){
					if(res[vl[x][i].first].second){
						pq.push(make_pair(vl[x][i].first, make_pair(res[vl[x][i].first].first, true)));
						continue;
					}
				}
				res[vl[x][i].first].first = vl[x][i].second + cost;
				if(isInc || (x == h && vl[x][i].first == g) || (x == g && vl[x][i].first == h) ){
					pq.push(make_pair(vl[x][i].first, make_pair(res[vl[x][i].first].first, true)));
					res[vl[x][i].first].second = true;
				}else{
					pq.push(make_pair(vl[x][i].first, make_pair(res[vl[x][i].first].first, false)));
					res[vl[x][i].first].second = false;
				}
			}
		}
	}
	sort(vt.begin(), vt.end());
	int i;
	for(i = 0; i < t; i++)
		if(res[vt[i]].second){
			printf("%d",vt[i]+1);
			if(i != t -1) printf(" ");
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
		s--;g--;h--;
		
		vector< vector<pair<int, int> > > vl(n);
		
		for(int i = 0; i < m; i++){
			scanf("%d %d %d",&a,&b,&d);
			vl[a - 1].push_back(make_pair(b - 1, d));
			vl[b - 1].push_back(make_pair(a - 1, d));
		}
		
		vector<int> vt;
		
		for(int i = 0; i < t; i++){
			scanf("%d",&x);
			vt.push_back(x - 1);
		}
		
		search(vl,vt);
	}
}