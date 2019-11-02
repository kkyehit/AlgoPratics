#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX_N 100000
#define MAX_M 1000000000
using namespace std;
typedef unsigned long long int int64;

int n, m;
int64 list[MAX_N];

int main(void){
	freopen("3079_in","r",stdin);
	
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n; i++){
		scanf("%llu",&list[i]);
	}
	
	sort(list, list + n);
	
	int64 left, right, mid;
	left = 0; right = 1000000000000000000;
	
	while(left < right){
		mid = (left + right) / 2;
		int64 cnt = 0;
		for(int i = 0; i < n; i++){
			cnt += mid / list[i];
		}
		if(cnt >= m) right = mid;
		else if(cnt < m) left = mid + 1;
	}
	
	printf("%llu\n",right);
}