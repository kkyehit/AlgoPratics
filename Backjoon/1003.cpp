#include<stdio.h>

using namespace std;

int cache[41][2];

int fibo(){
	cache[0][0] = 1;
	cache[0][1] = 0;
	cache[1][0] = 0;
	cache[1][1] = 1;
	for(int i = 2; i < 41; i++){
		cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
		cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
	}
}

int main(void){
	fibo();
	int T,N;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d",&N);
		printf("%d %d\n",cache[N][0],cache[N][1]);
	}
}