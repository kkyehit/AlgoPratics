#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX_N 20

using namespace std;

int A,B;
int r0,c0,r,c;
int N,M;

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d %d %d %d %d %d %d",&N,&M,&r0,&c0,&r,&c,&A,&B);
		int difR = abs(r0 - r);
		int difC = abs(c0 - c);
		unsigned int res = 0;
		res += difR/A;
		res += difC/B;
		if(difR%A != 0 ) res++;
		if(difC%B != 0 ) res++;
		cout<<res<<endl;
	}
}