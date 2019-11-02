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
	
	int cache[MAX_K + 1] = {0};
	cache[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = coin[i]; j <= k; j++){
			if(cache[j - coin[i]] != 0) cache[j] += cache[j - coin[i]];
		}
	}
	
	printf("%d\n",cache[k]);
}