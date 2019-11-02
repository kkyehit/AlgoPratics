#include<stdio.h>
#include<iostream>
#define MAX_N 10

using namespace std;

int coin[MAX_N], n, k;

int main(void){
	scanf("%d %d",&n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d",coin + i);
	
	int choice = n -1, cnt = 0;
	while(k != 0 && choice >= 0){
		if(coin[choice] > k) choice--;
		else{
			k -= coin[choice];
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
}