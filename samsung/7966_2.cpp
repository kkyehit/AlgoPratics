#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 32
#define INF 1000000000

using namespace std;

pair<int, int> p[MAX_N]; // first : cost, second : value;
vector< pair<pair<int, int>,int> > v[MAX_N]; // first : cost, second : value, return cost;
int n, x, k;
int maxCost;

int search(int _cost, int _value, int index){
	if(_value >= x) {
		maxCost = min(maxCost,_value);
		return 0;
	}
	if(maxCost < _cost) return INF;
	if(index >= n) return INF;
	
	for(int i = 0; i < v[index].size(); i++){
		if(v[index][i].first.first == _cost &&v[index][i].first.second == _value) return v[index][i].second;
	}
	
	int res = min(p[index].first + search(_cost + p[index].first,_value + p[index].second,index + 1),search(_cost,_value,index + 1) );
	v[index].push_back(make_pair(make_pair(_cost,_value), res));
	return res;
}

int main(void){
	setbuf(stdout, NULL);
	int T;
	int value, cost, tmp;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		memset(p,0,sizeof(p));
		value = cost = 0;
		maxCost = INF;
		
		scanf("%d",&n);
		for(int j = 0 ; j < n; j++)
			scanf("%d",&p[j].first);
		for(int j = 0 ; j < n; j++){
			scanf("%d",&p[j].second);
			v[j].resize(0);
		}
		scanf("%d",&x);
		scanf("%d",&k);
		for(int j = 0 ; j < k; j++){
			scanf("%d",&tmp);
			cost -= p[tmp -1].first;
		}
		//printf("cost %d, value %d\n",cost, value);
		int res = search(0,value,0);
		if(res == INF) printf("#%d -1\n",i);
		else {
			res += cost;
			if(res < 0) res = 0;
			printf("#%d %d\n",i,res);
		}
	}
	return 0;
}