#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#define INF 2123456789
#define MAX_N 10
#define MAX_X 2000000002

using namespace std;
typedef long long int int64;

int64 getSumToN(int64 n){
	return n * (n + 1) / 2;
}

bool isPossible(int64 n, int64 x, int64 sum){
	int64 left = 0, right = n;
	int64 nSum = getSumToN(n);
	while(left < right){
		int64 mid = (left + right) / 2;
		int64 midSum = getSumToN(mid) * 2;
		int64 dif = nSum - midSum;
		if(dif < sum) right = mid - 1;
		else if(dif > sum) left = mid + 1;
		else return true;
	}
	return ((nSum - getSumToN(left)) == sum)? true: false;
}

int64 MIN_N;
int64 getN(vector<int64> &v, int64 left, int64 right){
	int64 vSize = v.size();
	if(right < left) return INF;
	if(right = left) {
		for(int i = 0 ; i < vSize; i++){
			if(!isPossible(left, left, v[i])){
				return INF;
			} 
		}
		return left;
	}
	int64 mid = (left + right) / 2;
	int64 res = INF, midSum = getSumToN(mid);
	
	for(int i = 0 ; i < vSize; i++){
		if(midSum < v[i]) return getN(v, mid + 1, right);
	}
	
	bool isPossibleN = true;
	for(int i = 0 ; i < vSize; i++){
		if(!isPossible(mid, mid, v[i])){
			isPossibleN =false;
		} 
	}
	
	if(isPossibleN){
		res = min(mid , getN(v, left, mid - 1));
	}else{
		res = getN(v, left, mid - 1);
		res = min(getN(v, mid + 1, right), res);
	}
	return res;
}

int main(void){
	int T;
	int n;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		scanf("%d",&n);
	
		vector<int64> v;
		int64 a, b;
		for(int i = 0 ; i < n; i++){
			scanf("%lld %lld",&a ,&b);
			v.push_back(abs(a) + abs(b));
		}
		
		int64 res = getN(v, 0, MAX_X);
		if(res == INF) printf("#%d %d\n",t,-1);
		else printf("#%d %lld\n",t,res);
	}
}