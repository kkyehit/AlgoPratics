#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

deque<int> dq;
int N, K;

int main(void){
	scanf("%d %d",&N, &K);
	for(int i = 1 ; i <= N; i++){
		dq.push_back(i);
	}
	vector<int> v;
	while(!dq.empty()){
		for(int i = 0; i < K - 1; i++){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		v.push_back(dq.front());
		dq.pop_front();
	}
	printf("<");
	for(int i = 0; i < v.size(); i++){
		printf("%d",v[i]);
		if(i != v.size()-1)
			printf(", ");
	}
	printf(">\n");
}