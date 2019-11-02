#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	int pivot = (n % 8)? n % 8 : 8;
	if(pivot <= 5) printf("%d\n",pivot);
	else printf("%d\n",0 - (pivot - 10) );
}