#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#define MAX_N 10000

using namespace std;

vector<pair<int, int> > v[MAX_N + 1];
int p[MAX_N + 1];
int n, max_val = -1;

int search(int root){
	if(v[root].size() == 0) return 0;
	
	int &ret = p[root];
	if(ret != -1) return ret;
	
	int first = 0;
	int second = 0;
	for(int i = 0; i < v[root].size(); i++){
		int tmp = search(v[root][i].first) + v[root][i].second;
		if(first < tmp){
			second = first;
			first = tmp;
		}else if(second < tmp) second = tmp;
	}
	max_val = max(max_val, second + first);
	return (ret = first);
}

int main(void){
	int a,b,c;
	scanf("%d",&n);
	
	for(int i = 1; i < n; i++){
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
	}
	memset(p,-1,sizeof(p));
	search(1);
	printf("%d\n",max_val);
}