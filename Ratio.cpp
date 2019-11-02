#include "stdConvert.h"
#include <algorithm>
#define MAX 2000000000

void setStd(){
	char in[] = "RatioInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int N,M;
int search(){
	int add = 0, P = ((float)M/N)*100;
	while(add++<=MAX){
		int nextP = ((float)(M+add)/(N+add))*100;
		if(nextP > P) break;
	}
	return (add <= MAX) ? add : -1;
}
bool isRise(long win){
	long P = ((double)M*100/N), addedP = ((double)(M+win)*100/(N+win));
	if(addedP > P) return true;
	return false;
}
int search2(){
	long lo = 0, hi = MAX + 1;
	for(int i = 0; i < 100; i++){
		long mid = (lo + hi) / 2;
		if(isRise(mid)) hi = mid;
		else lo = mid;
	}
	return (hi <= MAX)? hi : -1;
}

int main(void){
	setStd();
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&N,&M);
		cout<<search2()<<endl;
	}
}