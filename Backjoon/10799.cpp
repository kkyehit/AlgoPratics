#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std; 

struct stack{
	int metal;
	int total;
	
	stack():metal(0),total(0) {};
	
	int push(char *a){
		if(*a == 0) return total;
		if(*a == '('){
			if(*(a+1) ==')'){
				total += metal;
				return push(a + 2);
			}
			else{
				metal++;
				total++;
				return push(a + 1);
			}
		}
		metal--;
		return push(a + 1);
	}
};

int main(void){
	freopen("10799in.txt","r",stdin);
	stack *mystack = new stack();
	char input[1000001];
	scanf("%s",input);
	printf("%d",mystack->push(input));
}