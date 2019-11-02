#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX_N 300000

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ll gcd(ll a, ll b){
	return b ? gcd(b,a%b) : a;
}

ll ch(ll a){
	return 0 - a;
}

int main(void){
	freopen("./15998_in","r",stdin);
	ll a[MAX_N + 1], b[MAX_N + 1], m = 0;
	int N;
	scanf("%d",&N);
	a[0] = b[0] = 0;
	for(int i = 1; i <= N; i++){
		scanf("%lld %lld",&a[i],&b[i]);
		if(a[i] < 0 ) m = gcd(m,b[i] + (0 - a[i]) - b[i -1]);
		
	}
	printf("m[%lld]\n",m);
	if(m == 0) m = 1;
	if(m < 0){
		m = -1;
	}else{
		for(int i = 1; i <= N; i++){
			if(a[i]+ b[i -1] != b[i]){
				if((a[i] > 0) || (m <= b[i]) || (a[i] < 0 && ch(a[i]) < b[i - 1])){
					m = -1;
					break;
				}
			}
		}
	}
	
	printf("%lld\n",m);
}