#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#define MAX_N 17

using namespace std;

int cost[MAX_N][MAX_N];
int cache[1<<MAX_N];
int p,n;
char turnOn[MAX_N + 10];

bool check(int sel){
	int res = 0;
	for(int i = 0 ; i <= n; i++)
		if(sel & (1<<i)) res++;
	return res >= p;
}

int calBit(){
	int res = 0;
	for(int i = 0 ; i < n; i++)
		if(turnOn[i] == 'Y') res |= (1<<i);
	return res;
}

int getCost(int sel, int index){
	int res = 999999; 
	for(int i = 0 ; i <= n; i++)
		if(sel & (1<<i) )
			res = min(res, cost[i][index]);
	return res;
}

int initCache(int init){
	int res = 999999; 
	int sel = init - 1;
	cache[init] = 0;
	while( ++sel < (1<<n) ){  
		if((sel & init) != init ) continue;
		if(check(sel)) res = min(res,cache[sel]);
		for(int i = 0 ; i < n; i++)
			if(!(sel & (1 << i))){
				if(cache[sel | (1<<i)] == -1) cache[sel | (1<<i)] = cache[sel] + getCost(sel,i);
				else cache[sel | (1<<i)] = min(cache[sel | (1<<i)] , cache[sel] + getCost(sel,i) );
				//cout<<" sel "<<sel<<" i "<< i<<" getCost "<<getCost(sel,i)<<endl; 
			}
	}
	return (res != 999999)? res : -1;
}

int main(void){
	freopen("1102.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&cost[i][j]);
	scanf("%s",turnOn);
	scanf("%d",&p);
	int sel = calBit();
	//cout<<sel<<endl;
	printf("%d",initCache(sel));
}