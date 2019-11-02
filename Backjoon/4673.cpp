#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000

using namespace std;

bool isHasCon[MAX_N * 2];

int d(int i){
	int r = 0, t = i;
	int res = 0;
	while(t != 0){
		r = t % 10;
		res += r;
		t = t / 10;
	}
	return res + i;
}

int main(void){
	memset(isHasCon, 0, sizeof(isHasCon));
	for(int i = 1; i <= MAX_N; i++){
		isHasCon[d(i)] = 1;
	}
	for(int i = 1; i <= MAX_N; i++)
		if(isHasCon[i] == 0) 
		printf("%d\n",i);
}