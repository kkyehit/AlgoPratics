#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_INT 21234567890
#define MAX_V 20000

using namespace std;
int v,e,k;
int visit[MAX_V];
vector<pair<int, int> > p[MAX_V];

int main(void){
	scanf("%d %d %d",&v,&e,&k);
	fill_n(visit, v, MAX_INT);
	
	for(int i = 0; i < e;i++)
}