#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &v, int n, int flag){
	int res = 0;
	for(int i = 0; i < n; i++){
		if(v[i] == 0) continue;
		for(int j = 1; j <= v[i]; j++){
			v[i] -= j;
			search(v, n, flag == 0 ? 1 : 0);
			v[i] += j;
		}
	}
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		int n;
		scanf("%d",&n);
		vector<int> v(n, 0);
		for(int i = 0; i < n; i++) scanf("%d",&v[i]);
	}
}