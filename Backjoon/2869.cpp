#include<stdio.h>
#include<iostream>
#define MAX_V 1000000000

using namespace std; 

typedef unsigned long long int int64;

int64 A,B,V;

int64 search(int64 begin, int64 end){
	if(begin == end) return begin;
	
	int64 half = (begin + end) / 2;
	int64 hight =( A * half ) - ( B * (half - 1) );
	
	//cout<<" A "<<A * half<<" B "<<B* (half - 1)<<endl;
	//cout<<" begin "<<begin<<" end "<<end<<" hight "<<hight<<endl;
	
	
	if(hight < V) return search(half + 1, end);
	return search(begin, half);
}

int main(void){
	scanf("%llu %llu %llu",&A,&B,&V);
	printf("%llu\n",search(0,MAX_V));
}
