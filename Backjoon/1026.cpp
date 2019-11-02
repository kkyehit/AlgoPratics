#include<stdio.h>
#include<algorithm>
#define MAX_N 50

using namespace std;

int a[MAX_N], b[MAX_N], n;

bool cmpMax(int A, int B){
	return B < A;
}
bool cmpMin(int A, int B){
	return A < B;
}

int main(void){
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",a + i);
	for(int i = 0 ; i < n; i++)
		scanf("%d",b + i);
	sort(a,a + n,cmpMax);
	sort(b,b + n,cmpMin);
	int s = 0;
	for(int i = 0 ; i < n; i++)
		s += a[i]*b[i];
	printf("%d",s);
	
}