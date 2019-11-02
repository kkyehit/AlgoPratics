#include<stdio.h>
#include<algorithm>
#include<cstring>

using namespace std; 

char input[10];

bool cmp(char a, char b){
	return b < a;
}

int main(void){
	scanf("%s",input);
	sort(input,input + 10,cmp);
	printf("%s",input);
}