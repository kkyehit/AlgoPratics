#include<stdio.h>
#include<algorithm>
#include<iostream>
#define MAX_K 13

int input[MAX_K];
int N;

int *pt[6];

using namespace std; 

void printPt(){
	for(int i = 0; i < 6; i++)
		printf("%d ",*pt[i]);
	printf("\n");
}
bool movePt(int index){
	if(index == -1) return false;
	if(pt[index] == &input[N - 1] ||
	  (index != 5 && pt[index + 1] == pt[index] + 1)){
		if(movePt(index -1)){
			pt[index] = pt[index - 1] + 1;
			return true;
		}
		else return false;
	}
	pt[index]++;
	return true;
}

int main(void){
	while(true){
		scanf("%d",&N);
		if(N == 0 ) return 0;
		for(int i = 0;i < N; i++)
			scanf("%d",input + i);
	
		sort(input,input + N - 1);
		for(int i = 0; i < 6; i++)
			pt[i] = input + i;
	
		printPt();
		while(movePt(5))
			printPt();
		printf("\n");
	}
}