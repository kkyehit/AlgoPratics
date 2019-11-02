#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>

#define MAX_N 300000
#define INF 30000000

using namespace std;

bool door[MAX_N + 2];
int n, d;

int search(){
	stack<pair<int, int > > s;
	int res = INF;
	int index = 0, level = 0, last;
	
	s.push(make_pair(index, level));
	
	while(!s.empty()){
		
		if(level <= res){
			if(index> n) res = min(res,level);
			else{
				last = index;
			
				for(int i = d; i > 0; i--)
					if(index + i < n && door[index + i]) {
						last = index + i;
						break;
					}
				if(last != index +d) s.push(make_pair(index + d, (door[index]?0: 1) + level));
				if(last != index) s.push(make_pair(last, (door[index]? 0: 1) + level));
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