#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX_N 100001

using namespace std; 

int n = 0;
char input[MAX_N];

bool cmp(int a, int b){
	return a > b;
}

bool is30Multi(){
	if(input[n-1] != '0') return false;
	long long tmp = 0;
	for(int i = 0; i < n; i++)
		tmp += input[i] - '0';
	if(tmp % 3 != 0) return false;
	return true;
}
int main(void){

	scanf("%s",input);
	while(input[n] !='\0') n++;
	sort(input,input + n,cmp);
	
	if(!is30Multi()) printf("-1");
	else fwrite(input,n,1,stdout);
	
	printf("\n");
}