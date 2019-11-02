#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<math.h>
#define MAX_N 1100000000000
#define MAX_M 1100000

unsigned char era[MAX_M + 1];
unsigned char range[MAX_M + 1];
long long int n, m;

using namespace std; 

void getRange(){
	for(long long int i = 2; (i * i)<= m; i++){
		long long int k = n / (i * i);
		if((i * i * k) < n ) k++;
		for(; (i * i * k) <= m; k++)
			range[(i * i * k )- n + 1] = false;
	}
}

int getCnt(){
	int res = 0;
	for(long long int i = 1; i <= m - n + 1; i++)
		if(range[i]) res++;
	return res;
}

int main(void){
	
	memset(era,true,sizeof(era));
	memset(range,true,sizeof(range));
	scanf("%lld %lld",&n,&m);
	getRange();
	//printf("1\n");
	printf("%d",getCnt());
}