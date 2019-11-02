#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_T 500
#define MAX_X 200000

using namespace std;
 
int C, B;
int N;
int cache[MAX_X+1];

int getConyX(int t)
{
	return C + (t*t + t)/2;
}
void setCache(){
	int time = 0, brounX = B;
	while(brounX >= 0)
	{
		cache[brounX--] = time++;
	}
	time = 0, brounX = B;
	while(++brounX <= MAX_X){
		cache[brounX] = ++time;
	}
	// 현제 위치 x2 +1 -1 에서 +1 한것중 최소값 저장,
	time = 0; brounX = B;
	while(++brounX <= MAX_X){
		if(brounX * 2 <= MAX_X){
			cache[brounX * 2] = min(cache[brounX * 2],cache[brounX] + 1);
			cache[brounX * 2 + 1]  = min(cache[brounX * 2 + 1],cache[brounX * 2]+ 1);
			cache[brounX * 2 - 1]  = min(cache[brounX * 2 - 1],cache[brounX * 2]+1);
		}
	}
}

int search()
{
	int conyX, time = 0;
	int res = MAX_T;
	while((conyX = getConyX(time)) <= MAX_X){
		if(time == cache[conyX]){
			res = min(res,cache[conyX]);
		}
		time++;
	}
	return res;
}

int main(void)
{
	scanf("%d %d",&C,&B);
	memset(cache,-1,sizeof(cache));
	N = MAX_T;
	setCache();
	printf("%d\n",search());
}