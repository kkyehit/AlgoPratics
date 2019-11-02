#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define MOD 20090711
#define parent(i) (i - 1)/2
#define childrenL(i) i*2 + 1
#define childrenR(i) i*2 + 2
using namespace std;

struct RNG{
	int seed,a,b;
	explicit RNG(int _a,int _b):seed(1983),a(_a),b(_b){};
	int next(){
		int res = seed;
		seed = ((seed * (long long )a )+ b) % MOD;
		return res;
	}
}typedef RNG;

int runningMedian(int n, RNG rng){
	priority_queue< int,vector<int>,less<int> > maxHeap;
	priority_queue< int,vector<int>,greater<int> > minHeap;
	int ret = 0;
	
	for(int i = 1; i <= n; i++){
		if(maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top() ){
			int a= maxHeap.top(), b= minHeap.top();
			maxHeap.pop();minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top())% MOD;
	}
	return ret;
}

int main(void){
	int c;
	scanf("%d",&c);
	while(c--){
		int N,a,b;
		scanf("%d %d %d",&N,&a,&b);
		RNG rng(a,b);
		cout<<runningMedian(N,rng)<<endl;
	}
}