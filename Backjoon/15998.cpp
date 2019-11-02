#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

ull gcd(ull a, ull b){
	return b ? gcd(b,a%b) : a;
}

int main(void){
	freopen("./15998_in","r",stdin);
	ll a, b, prev;
	int N;
	scanf("%d",&N);
	vector<ull> v;
	vector<ll> test;
	prev = 0;
	while(N--){
		scanf("%lld %lld",&a,&b);
		if(a > 0){
			prev += a;
			if(prev != b) v.push_back(0);
		}else{
			ll aa = 0 - a;
			if( aa < prev){
				prev += a;
				if(prev != b) v.push_back(0);
			}
			else{
				ll tmp = aa + b - prev;
				v.push_back(tmp);
				prev = b;
				test.push_back(b);
			}
		}
	}
	
	if(v.size() == 0){
		printf("-1\n");
	}else{
		ull M = v[0];
		if( M == 0){
			printf("-1\n");
		}else{
			for(int i = 1 ; i < v.size(); i++){
				if(v[i] == 0){
					printf("-1\n");
					return 0;
				}
				M = gcd(M, v[i]);
			}
			if( M == 0 )printf("-1\n");
			if( M == 1){
				for(int i = 0; i < test.size(); i++){
					if(test[i] != 0){
						printf("-1\n");
						return 0;
					}
				}
				printf("%llu\n",M);
			}
			else printf("%llu\n",M);
		}
	}
}