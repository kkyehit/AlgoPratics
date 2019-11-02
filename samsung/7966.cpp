#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 32
#define INF 1000000000

using namespace std;
typedef long long int int64;

pair<int64, int64> p[MAX_N]; // first : cost, second : value;
int n, x, k;
int64 value, cost, tmp;

void search(int64 _cost, int64 _value, int64 index){
	if(_cost > cost) return ;
	if(_value < x) return ;
	if(index == n){
		if(_value < x ) return ;
		cost = min(cost, _cost);
		return;
	}
	
	search(_cost - p[index].first, _value - p[index].second, index + 1);
	search(_cost,_value,index + 1);
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		memset(p,0,sizeof(p));
		value = cost = 0;
		
		scanf("%d",&n);
		for(int j = 0 ; j < n; j++)
			scanf("%lld",&p[j].first);
		for(int j = 0 ; j < n; j++)
			scanf("%lld",&p[j].second);
		scanf("%d",&x);
		scanf("%d",&k);
		int64 tmpCost = 0;
		for(int j = 0 ; j < k; j++){
			scanf("%lld",&tmp);
			tmpCost -= p[tmp -1].first;
		}
		for(int j = 0; j < n; j++){
			cost += p[j].first;	
			value += p[j].second;	
		}
		for(int j = 0; j < n; j++)
			p[j].first = 0 - p[j].first;
		sort(p, p + n);
		for(int j = 0; j < n; j++)
			p[j].first = 0 - p[j].first;
		printf("cost %lld, value %lld tmpCost : %lld\n",cost, value,tmpCost);
		if(value < x) printf("#%d -1\n",i);
		else {
			search(cost,value,0);
			cost += tmpCost;
			if(cost < 0) cost = 0;
			printf("#%d %lld\n",i,cost);
		}
	}
	return 0;
}