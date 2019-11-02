#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#define MAX_N 10000

using namespace std;

vector<pair<int, int> > v[MAX_N + 1];
pair<int, int> p[MAX_N + 1];
int n;

int main(void){
	int a,b,c;
	scanf("%d",&n);
	
	for(int i = 1; i < n; i++){
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
	}
	
	memset(p,-1,sizeof(p));
	
	int max_val = -1;
	int root = 1;
	stack<int> s;
	s.push(root);
	while(true){
		int v_size = v[root].size();
		bool already = false, added = false;
		p[root] = make_pair(0,0);
		if(v_size >= 1){
			int child = v[root][0].first;
			if(p[child].first == -1) {
				if(!already){
					already = true;
					s.push(root);
				} 
				added = true;
				s.push(child);
			}
			else p[root].first = max(p[child].first,p[child].second) + v[root][0].second; 
		}
		if(v_size == 2){
			int child = v[root][1].first;
			if(p[child].first == -1) {
				if(!already){
					s.push(root);
				} 
				added = true;
				s.push(child);
			}else p[root].second = max(p[child].first,p[child].second)+ v[root][1].second; 
		}
		
		if(!added) max_val = max(max_val, p[root].first + p[root].second);
		
		if(s.empty()) break;
		root = s.top();
		s.pop();
	}
	printf("%d\n",max_val);
}