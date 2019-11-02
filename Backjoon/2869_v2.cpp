#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	int A, B, V;
	scanf("%d %d %d",&A, &B, &V);
	
	int left = 0, right = V, mid;
	while(left < right){
		mid = (left + right) / 2;
		if(( ((A - B) * (mid - 1) )+ A) >= V) right = mid;
		else left = mid + 1;
	}
	printf("%d\n",left);
}