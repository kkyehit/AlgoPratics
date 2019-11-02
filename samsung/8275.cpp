#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std; 

int maxSum;
int n, x, m;
int l[11],r[11],s[11];

bool search(vector<int> &res, vector<int> &list, int index, int sum){
	for(int i = 0; i < m; i++){
		if(index == r[i]){
			int sum = 0;
			for(int j = l[i] - 1; j < index; j++)sum += list[j];
			if(s[i] != sum) return false;
		}
	}
	
	if(index == n){
		if(maxSum <= sum){
			res = list;
			maxSum = sum;
		} return true;
	}
	
	bool funcRes = false;
	for(int i = x; i >= 0; i--){
		list[index] = i;
		if(search(res, list, index + 1, sum + i)) funcRes = true;
	}
	return funcRes;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		scanf("%d %d %d", &n, &x, &m);
		for(int i = 0; i < m; i++) scanf("%d %d %d", &l[i], &r[i], &s[i]);
		vector<int> res(11, 0);
		vector<int> list(11, 0);
		printf("#%d ",t);
		maxSum = -1;
		if(!search(res, list, 0, 0)) printf("-1\n");
		else{
			for(int i = 0; i < n; i++) printf("%d ",res[i]);
			printf("\n");
		}
	}
}