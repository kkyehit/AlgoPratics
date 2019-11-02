#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 100
#define MAX_K 10000

using namespace std;

int main(void){
	int n, k;
	int coin[MAX_N];
	scanf("%d %d",&n, &k);
	for(int i = 0; i < n; i++) scanf("%d",&coin[i]);
	
	int cache[MAX_N][MAX_K + 1] = {0};
	int res = 2123456789;
	for(int i = 0; i < n; i++){
		for(int j = coin[i]; j <= k; j++){
			//cache[i][j] = min(cache[i][j - coin[i]] + 1, cache[i - 1][j]);
			if(j == coin[i]) cache[i][j] = 1;
			else if(cache[i][j - coin[i]] == 0){
				if(i == 0) continue;
				cache[i][j] = cache[i - 1][j];
			}
			else if(i == 0) cache[i][j] = cache[i][j - coin[i]] + 1;
			else cache[i][j] = min(cache[i][j - coin[i]] + 1, cache[i - 1][j]);
			
			if(j == k) res = min(res, cache[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			printf("%d ",cache[i][j]);
		}
		printf("\n");
	}
	
	printf("%d\n",(res == 2123456789 || res == 0) ? -1 : res);
}