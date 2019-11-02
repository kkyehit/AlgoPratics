#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;



int N,K;

void search(){
	int start = 0, person = N;
	bool circlyQueue[1000];
	memset(circlyQueue,1,sizeof(circlyQueue));
	while(person > 2){
		circlyQueue[start] = 0;
		person--;
		for(int i = 0 ; i < K; i++){
			start = (start + 1) % N;
			if(!circlyQueue[start]) i--;
		}
	}
	vector<int> res;
	for(int i = 0; i < N; i++)
		if(circlyQueue[i]) res.push_back(i + 1);
	cout<<res[0]<<" "<<res[1]<<endl;
}

int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&N,&K);
		search();
	}
}