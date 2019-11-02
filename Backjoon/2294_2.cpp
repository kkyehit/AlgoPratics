#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX_N 100
#define MAX_K 10000
#define INF 21234567

using namespace std;

int main(void){
	int n, k;
	int coin[MAX_N];
	scanf("%d %d",&n, &k);
	for(int i = 0; i < n; i++) scanf("%d",&coin[i]);
	
	
	int cache[MAX_K+1];
	cache[0] = 0;
	for (int i = 1; i <= k; i++){
		cache[i] = INF;
		for(int j = 0; j < n; j++){
			if((i - coin[j])<0) continue;
			cache[i] = min(cache[i - coin[j]] + 1, cache[i]);
		}
	}
   /* 
	for(int j = 0; j <= k; j++){
			printf("%d ",cache[j]);
		}
		printf("\n");
	*/

	int res = (cache[k] == INF || cache[k] == 0) ? -1 : cache[k];
	printf("%d\n",res);
}