#include<stdio.h>
#include<iostream>

using namespace std; 

int firstNum[2];
int cycleNum[2];

int cycle(){
	if(firstNum[0] == cycleNum[0] && firstNum[1] == cycleNum[1]) return 0;
	if(cycleNum[0] == -1){
		cycleNum[0] = firstNum[0];
		cycleNum[1] = firstNum[1];
	}
	int add = cycleNum[0] + cycleNum[1];
	cycleNum[0] = cycleNum[1];
	cycleNum[1] = add % 10;
	return 1 + cycle();
}

int main(void){
	int input;
	scanf("%d",&input);
	firstNum[0] = input / 10;
	firstNum[1] = input % 10;
	cycleNum[0] = cycleNum[1] = -1;
	cout<<cycle()<<endl;
}