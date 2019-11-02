#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long int int64;

int64 distance;

int64 getMinimum(){
	int64 n = 1;
	int64 n_2 = 1;// sum 1~n = (n^2 + n) / 2  sum 1~ n -1 = (n^2 - n) / 2
	while(( distance - n_2 )>=0){
		n++;
		n_2 = n*n;
	}
	n--;
	distance = distance - n*n;
	int cnt = n*2 - 1;
	while(n){
		if((distance > 0) &&(distance - n >= 0)) {
			distance -= n;
			cnt++;
		}
		else n--;
	}
	return cnt;
}

int main(void){
	int t;
	int64 x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&x,&y);
		distance = y - x;
		printf("%lld\n",getMinimum());
	}
}