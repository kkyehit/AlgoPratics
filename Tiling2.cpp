#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
void test(int *a,int n){
	for(int i =0; i <n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int search(int index,int &n, int *cache){
	if(index > n) return 0;
	if(index == n) return 1;
	int &ret = cache[index];
	if(ret != -1) return ret;
	return ret = (search(index + 1, n, cache) + search(index + 2, n, cache) )%1000000007;
}

int main(void){
	int C,n;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d",&n);
		int *cache = new int[n];
		memset(cache,-1,sizeof(int)*n);
		cout<<search(0,n,cache)<<endl;
	}
}