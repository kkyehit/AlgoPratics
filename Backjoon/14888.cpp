#include <stdio.h>
#include <iostream>
#define MAX_N 100
using namespace std;

int oper[4];
int operList[MAX_N];	
int n, minValue, maxValue;

void search(int index, int sum){
	if(index == n){
		minValue = min(minValue, sum);
		maxValue = max(maxValue, sum);
	}
	
	for(int i = 0; i < 4; i++){
		if(oper[i] == 0)continue;
		oper[i]--;
		if(i == 0) search(index + 1, sum + operList[index]);
		else if(i == 1) search(index + 1, sum - operList[index]);
		else if(i == 2) search(index + 1, sum * operList[index]);
		else if(i == 3) search(index + 1, sum / operList[index]);
		oper[i]++;
	}
}

int main(void){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)scanf("%d",&operList[i]);
	for(int i = 0; i < 4; i++)scanf("%d",&oper[i]);
	minValue = 2123456789; maxValue = -2123456789;
	search(1, operList[0]);
	printf("%d\n%d\n",maxValue,minValue);
}