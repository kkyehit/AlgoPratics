#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

#define MAX_N 32
#define INF 1000000000

using namespace std;

pair<int, int> p[MAX_N]; // first : cost, second : value;
vector< pair<int, int> > v[MAX_N];//[index] , first : value, second : cost;
int n, x, k;
int value, cost, tmp;

int search(){
	int res = 0, _index = 0, _value = 0;
	stack<pair<int,int > > s;// first : index. second : value
	s.push(make_pair(0,0));
	
	/*if(_value >= x) return 0;
	
	if(index >= n) return INF;
	
	for(int i = 0; i < v[index].size(); i++){
		if(v[index][i].first == _value) return v[index][i].second;
	}
	
	int res = min(p[index].first + search(_value + p[index].second,index + 1),search(_value,index + 1) );
	v[index].push_back(make_pair(_value, res));
	return res;*/
}

int main(void){
	setbuf(stdout, NULL);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		memset(p,0,sizeof(p));
		value = cost = 0;
		
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
		int res = search();
		if(res == INF) printf("#%d -1\n",i);
		else {
			res += cost;
			if(res < 0) res = 0;
			printf("#%d %d\n",i,res);
		}
	}
	return 0;
}