#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<math.h>

#define MAX_N 501

using namespace std;

int N,K;
int sumCache[MAX_N][MAX_N];

void test(){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout<<sumCache[i][j]<<" ";
		cout<<endl;
	}
	
}

void makeSumeCache(vector<int> &a){
	int k = 1,i,j;
	for(i = 0; i < a.size(); i++){
		sumCache[i][0] = a[i];
		for(j = i + 1,k = 1; j < a.size(); j++,k++)
			sumCache[i][k] = sumCache[i][k - 1] + a[j];
	}
}
double calc(vector<int> &a){
	double res = 999999;
	for(int j = 0; j < N; j++){
		for(int i = K - 1; i < N; i++){
			if(sumCache[j][i] == 0 ) break;
			double avg = sumCache[j][i] / (i + 1) ;
			double sum = 0;
			for(int l = 0; l <= i; l++)
				sum += (a[l] - avg) * (a[l] - avg);
			res = min(res, sqrt(sum / (i+1) ) );
//cout<<j<<" "<<i<<" avg : "<<avg<<" sum : "<<sum<<" res : "<<res<<endl;
		}
	}
	return res;
}


int main(void){
	scanf("%d %d",&N,&K);
	
	int input;
	vector<int> a;
	memset(sumCache,0,sizeof(int)*MAX_N*MAX_N);
	for(int i = 0; i < N; i++){
		scanf("%d",&input);
		a.push_back(input);
	}
	makeSumeCache(a);
	//test();
	cout<<calc(a)<<endl;
}