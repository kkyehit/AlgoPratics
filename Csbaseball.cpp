#include<stdio.h>
#include<iostream>

using namespace std;

int cal(int &a, int &b){
	int dif = b -a;
	if( dif < 0) return 0;
	return dif + 4;
}

int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0 ; i < c; i++){
		int A, B;
		scanf("%d %d",&A,&B);
		printf("%d\n",cal(A,B));
	}
}