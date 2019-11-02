#include <stdio.h>
#include <cstring>

#define M 1000000003
#define MAX_N 1000

using namespace std;

int cache [MAX_N][MAX_N];
int n, k;

int search(int index, int left, int flag){
	if(left == 0) return 1;
	if(index >= (n + flag)) return 0;
	
	int &ret = cache[index][left];
	if(ret != -1) return ret;
	
	return ret = (search(index + 1, left, flag) + search(index + 2, left -1, flag)) % M;
}

int main(void){
	scanf("%d",&n);
	scanf("%d",&k);

	memset(cache, -1, sizeof(cache));
	int a = search(2, k - 1, -1);
	memset(cache, -1, sizeof(cache));
	int res = (a + search(1, k, 0)) % M;
	
	printf("%d\n",res);
}