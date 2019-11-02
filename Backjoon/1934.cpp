#include <stdio.h>
#include <iostream>

using namespace std;

int gcd(int a, int b){
	return ( a == 0 )? b : gcd(b % a, a);
}
int main(void){
	int T, a, b;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a, &b);
		if(b < a) swap(a, b);
		printf("%d\n", (a * b)/gcd(a,b));
	}
}