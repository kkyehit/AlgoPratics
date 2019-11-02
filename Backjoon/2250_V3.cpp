#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_N 10000
using namespace std;

int n;
vector< pair<int, int> > list(MAX_N + 1); //first : left, second : right
vector< int > level[MAX_N + 1]; //locate

int init(int node, int locate, int _level){
	if(node < 0) return locate;

	int mylocate = init(list[node].first, locate, _level + 1) + 1;
	level[_level].push_back(mylocate);
	printf("node : %d locate : %d\n",node, mylocate);
	return init(list[node].second, mylocate, _level + 1);
}

int main(void){
	freopen("./2250in.txt","r",stdin);
	scanf("%d",&n);
	
	int root, left, right;
	int cnt[MAX_N + 1] = {0};
	for(int i = 0; i < n; i++){
		scanf("%d %d %d",&root,&left,&right);
		list[root] = make_pair(left, right);
		cnt[left]++; cnt[right]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 0){
			root = i;
			break;
		} 
	}
	
	init(root, 0, 1);
	
	int res = 0, _level = 0;
	for(int i = 1; i <= n; i++){
		
		int end = level[i].size();
		if(end == 0) break;
		sort(level[i].begin(), level[i].end());
		if((level[i][end - 1] - level[i][0] + 1 )> res ){
			res = level[i][end - 1] - level[i][0] + 1;
			_level = i;
		}
	}
	
	printf("%d %d\n",_level, res);
}