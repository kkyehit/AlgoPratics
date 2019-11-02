#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>

#define MAX_N 300000
#define INF 30000000

using namespace std;

int cache[MAX_N + 2];
bool door[MAX_N + 2];
int n, d;

int search(){
	stack<pair<int, int > > s;
	int res = INF;
	int index = 0, level = 0;
	
	s.push(make_pair(index, level));
	memset(cache,-1,sizeof(cache));
	
	while(!s.empty()){
		if(level <= res){
			if(index>= n) res = min(res,level);
			else{
				for(int i = 1; i <= d; i++){
					s.push(make_pair(index + i, (door[i]? 0: 1) + level));
				}
			}
		}
		
		
		index = s.top().first;
		level = s.top().second;
		s.pop();
	}
	return res;
}

int main(void){
	int T, tmp;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++){
		scanf("%d %d",&n,&d);
		for(int j = 1; j <= n; j++){
			scanf("%d",&tmp);
			if(tmp) door[j] = true;
			else door[j] = false;
		}
		door[0] = door[n + 1] =true;	
		printf("#%d %d\n",i,search());
	}
}