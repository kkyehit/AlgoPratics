#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 1000
using namespace std;

int search(vector<int> *v, vector<int> &b, int now, int step){
	int vSize = v[now].size();
	int res = 0;
	for(int i = 0; i < vSize; i++){
		if(b[v[now][i]] != -1){
			res = max(res, step - b[v[now][i]]);
		}else{
			b[v[now][i]] = step;
			res = max(res, search(v, b, v[now][i], step + 1));
			b[v[now][i]] = -1;	
		}
	}
	return res;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		int n;
		scanf("%d",&n);
		vector<int> v[n + 1];
		vector<int> b(n + 1, -1);
		int x, y;
		for(int i = 0 ; i < n; i++){
			scanf("%d %d",&x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		printf("#%d %d\n",t, search(v, b, 1, 0));
	}
}