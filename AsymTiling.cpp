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
int AsymSearch(int index,int &m, int *cache2){	
	if(index > m) return 0;
	if(index == m) return 1;
	if(index == m - 1) return 2;
	int &ret = cache2[index];
	if(ret != -1) return ret;
	return ret = (AsymSearch(index + 1, m, cache2) + AsymSearch(index + 2, m, cache2) )%1000000007;
}

int search(int index,int &n, int *cache){
	if(index > n) return 0;
	if(index == n) return 1;
	int &ret = cache[index];
	if(ret != -1) return ret;
	return ret = (search(index + 1, n, cache) + search(index + 2, n, cache) )%1000000007;
}

int main(void){
	int C,n,m,res;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d",&n);
		int *cache = new int[n];
		memset(cache,-1,sizeof(int)*n);
		m = n/2;
		int *cache2 = new int[m];
		memset(cache2,-1,sizeof(int)*m);
		res = search(0,n,cache) - AsymSearch(0,m,cache2);
		while(res < 0)res += 1000000007;
		cout<<res<<endl;
	}
}