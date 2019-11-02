#include<stdio.h>
#include<iostream>
#define MAX_N 12

using namespace std;

int main(){
	freopen("FixInput.txt","r",stdin);
	int t,n,list[MAX_N];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 0 ; i < n; i++)
			scanf("%d",list + i);
		
		int res = 0;
		for(int i = 0 ; i < n; i++)
			if(list[i] == i + 1) res++;
		printf("%d\n",res);
	}
}