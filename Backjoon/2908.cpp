#include <stdio.h>

using namespace std;

int revers(int a){
	int res = 0;
	while(a != 0){
		res *= 10;
		res += a % 10;
		a /= 10;
	}
	return res;
}

int main(void){
	int a1,a2;
	scanf("%d %d",&a1,&a2);
	a1 = revers(a1);
	a2 = revers(a2);
	printf("%d\n",(a1 < a2) ? a2 : a1);
}