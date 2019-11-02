#include<stdio.h>
#include<iostream>
#include<cstring>

#define MAX_CNT 300
#define MAX_JUMP 2

using namespace std; 

int cache[MAX_JUMP][MAX_CNT + 1];
int stair[MAX_CNT + 1];
int maxStair;

int search(int locate, int canSel){
	if(locate == maxStair) return stair[locate];
	if(locate > maxStair) return -987654321;
	
	int &ret = cache[canSel][locate];
	if(ret != -1) return ret; 
	
	ret = stair[locate] + search(locate + 2, 1);
	if(canSel != 0) ret = max(ret, stair[locate] + search(locate + 1, 0));
	
	return ret;
}

int main(void){
	memset(cache,-1,sizeof(cache));
	scanf("%d",&maxStair);
	for(int i = 1; i <= maxStair; i++)
		scanf("%d",stair + i);
	int res = max(search(1,1),search(2,1));
	printf("%d\n",res);
}
