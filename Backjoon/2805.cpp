#include<stdio.h>
#include<iostream>
#define MAX_N 1000000
typedef unsigned long long int int64;

int64 list[MAX_N], maxHight = 0;
int n, m;

using namespace std; 

int64 max(int64 a, int64 b){
	if(a < b) return b;
	return a;
}

int64 search(int64 begin, int64 end){
	if(begin == end) return begin;
	
	int64 sum = 0, cutHight = (begin + end) / 2; 
	for(int i = 0; i < n; i++)
		if(cutHight < list[i]) sum += (list[i] - cutHight);
	
	
	if(sum < m) return search(begin, cutHight);
	return search(cutHight,end);
}

int64 search2(){
	int64 sum;
	int64 begin = 0, end = maxHight, cutHight;
	for(int i = 0; i < 100; i++){
		cutHight = ( begin + end ) / 2; 
		sum = 0;	
		for(int i = 0; i < n; i++)
			if(cutHight < list[i]) sum += (list[i] - cutHight);
		if(sum < m) end = cutHight;
		else begin = cutHight;
	}
	return begin;
}

int main(void){
	scanf("%d %d",&n, &m);
	for(int i = 0; i < n; i++){
		scanf("%llu",list + i);
		maxHight = max(maxHight,list[i]);
	}
	int64 res = search2();
	printf("%llu\n",res);
}