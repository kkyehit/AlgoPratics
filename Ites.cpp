#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

typedef unsigned int uint32;

class signal{
	private:
	uint32 seed;
	
	public:
	signal(){
		seed = 1983;
	}
	uint32 next(){
		uint32 res = seed % 10000 + 1;
		seed = (seed * 214013 + 2531011) % (1l<<32);
		return res;
	}
};

int k,n;

int search(){
	signal newSignal;
	queue<uint32> signalList;
	uint32 sum = 0;
	int res = 0;
	for(int i = 0; i < n ; i++){
		uint32 nextNum = newSignal.next();
		signalList.push(nextNum);
		sum+= nextNum;
		while(sum > k ){
			sum -= signalList.front();
			signalList.pop();
		}
		if(sum == k) res++;
	}
	return res;
}
int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&k,&n);
		cout<<search()<<endl;
	}
}