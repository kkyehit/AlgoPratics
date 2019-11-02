#include<stdio.h>
#include<cstring>

using namespace std; 

int position[11][11];
int cache[11][1<<11];

int max(int a, int b){
	return (a < b)? b:a;
}

int search(int index, int sel){
	if(sel == (1<<11) -1) return 0;
	
	int &ret = cache[index][sel];
	if(ret != -1) return ret;
	
	int res = -9999999;
	for(int i = 0; i < 11; i++)
		if((position[index][i] != 0) && !(sel & (1<<i)))
			res = max(res,position[index][i] + search(index + 1,sel | (1<<i)));

	return ret = res;
}

int main(void){
	freopen("3980.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cache,-1,sizeof(cache));
		for(int i = 0 ; i < 11 ; i++ )
			for(int j = 0 ; j < 11; j++)
				scanf("%d",&position[i][j]);
		printf("%d\n",search(0,0));
	}
}