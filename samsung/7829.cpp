#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int int64;

int64 gcd(int64 a, int64 b){
	return (a % b != 0) ? gcd(b, a%b) : b;
}

int main(void){
	int64 T, n, tmp;
	int64 l, g, maxValue;
	scanf("%lld",&T);
	for(int64 i = 1 ; i <= T; i++){
		l = g = 0;
		maxValue = -1;
		vector<int64> v;
		scanf("%lld",&n);
		for(int64 j = 0; j < n; j++){
			scanf("%lld",&tmp);
			v.push_back(tmp);
			maxValue = max(tmp, maxValue);
		}
		
		if(n == 1) l =  v[0] * v[0];
		else{
			l = g = v[0];
			for(int64 j = 1; j < n; j++){
				g = gcd(g,v[j]);
				l = (l * v[j])/gcd(l,v[j]);
				//printf("l : %d v[j] : %d, gcd : %d\n",l,v[j],gcd(l,v[j]));
			}
			l = l * g;
		}
		printf("#%lld %lld\n",i,l);
	}
}