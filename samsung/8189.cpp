#include <stdio.h>
#include <iostream>
#define MAX_N 1000

using namespace std;
 
int N, A, B;
int latter[MAX_N + 1];
int main(){
	int T;
	for(int t = 1; t <= T; t++){
		scanf("%d %d %d",&N, &A, &B);
		for(int i = 0; i < N; i++) scanf("%d",&latter[i]);
	}
}