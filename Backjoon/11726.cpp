#include <stdio.h>
#include <cstring>

#define MAX_N 1000
#define MOD 10007

using namespace std;

int cache[MAX_N];
int n;

int search(int index){
	if(index == n) return 1;
	if(index > n) return 0;
	
	int &ret = cache[index];
	if(ret != -1) return ret;
	
	return ret = (search(index + 1) + search(index + 2)) %MOD;
}

int main(void){
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	printf("%d\n",search(0));
}