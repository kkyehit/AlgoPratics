#include <stdio.h>

using namespace std;
typedef long long int int64;

int64 list[5] = {1,2,5,25,125};

int main(void){
	int T;
	scanf("%d",&T);
	
	for(int64 i = 1; i <= T; i++){
		int64 input, res = 0, pivot = 1;
		scanf("%lld",&input);
		for(int64 j = 0; j <= 9; j++ ){
			for(int64 k = 0; k < 5; k++){
				if(list[k] * pivot <= input) {
					res++;
				}
			}
			pivot *= 10;
		}
		printf("#%lld %lld\n",i,res);
	}
}