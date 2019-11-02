#include<stdio.h>
#include<iostream>

using namespace std;

int n, m, k;

int main(void){
	scanf("%d %d %d",&n,&m,&k);
	while(k > 0){
		if(m > n/2) m--;
		else n--;
		k--;
	}
	printf("%d\n",min(n/2,m));
}