#include <stdio.h>
#include <cstring>

using namespace std;

int cache[30][3];
int n;

int search(int index, int flag){
	if(index == n && flag == 0) return 1;
	if(index >= n ) return 0;
	
	int &ret = cache[index][flag];
	if(ret != -1) return ret;
	
	ret = 0;
	if(flag == 0){
		ret = search(index + 2, 0) +  search(index + 1, 1) +  search(index + 1, 1);
	}else if(flag == 1){
		ret = search(index + 1, 0) + search(index + 1, 2);
	}else if(flag == 2){
		ret = search(index + 1, 1);
	}
	return ret;
}

int main(void){
	memset(cache, -1, sizeof(cache));
	scanf("%d",&n);
	printf("%d\n",search(0,0));
}