#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;

char deck[1000001];

void init_deck(){
	memset(deck, 1, sizeof(deck));
	deck[1] = 0;
	for(int i = 2; i <= sqrt(1000001) + 1; i++){
		if(deck[i] == 0) continue;
		for(int j = i*i; j < 1000001; j += i){
			deck[j] = 0;
		}
	}
}

int main(void){
	int n, m;
	scanf("%d %d",&n, &m);
	init_deck();
	for(int i = n; i <= m; i++)
		if(deck[i] == 1)
			printf("%d\n",i);
}