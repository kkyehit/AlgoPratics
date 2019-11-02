#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits>
#define MAX_K 10000

using namespace std; 
typedef long long int int64;

int64 k, n;
int64 *lan;

int64 search2(){
	int64 a = 0, b = numeric_limits<int>::max();
	int64 mid;
	int64 res = 0;
	for(int i = 0 ; i < 100; i++){
	//cout<<" n "<<n<<" a "<<a<<" b "<<b<<" res "<<res<<endl;
		mid = (a + b) / 2;
		res = 0;
		for(int j = 0; j < k; j++)
			res += lan[j]/mid;
		if(res >= n) a = mid;
		else b = mid;
	}
	res = 0;
	for(int j = 0; j < k; j++)
		res += lan[j]/b;
	return (res >= n)? b : a;
}

int main(void){
	freopen("1654in.txt","r",stdin);
	scanf("%lld %lld",&k,&n);
	lan = (int64 *) malloc(sizeof(int64)*k);
	for(int i = 0; i < k; i++)
		scanf("%lld",lan + i);
	printf("%lld",search2());
}