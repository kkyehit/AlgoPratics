#include "stdConvert.h"
#define MAX_N 500
#include <sstream>
#include <algorithm>

int min(int a,int b){
	if(a < b) return a;
	return b;
}int max(int a,int b){
	if(a > b) return a;
	return b;
}
void setStd(){
	char in[] = "MatchOrderInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}
int N;

int test(vector<int> &rus, vector<int> &kor ){
	for(int i = 0; i < N; i++)
		cout<<rus[i]<<" ";
	cout<<endl;
	for(int i = 0; i < N; i++)
		cout<<kor[i]<<" ";
	cout<<endl;
}

int search(vector<int> &rus, vector<int> &kor ){
	int res = 0,i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			if(rus[i] <= kor[j]){
				res++;
				kor[j] = -1;
				break;
			}
		if(j == N) return res;
	}
	return res;
}

int main(void){
	setStd();
	
	int C;
	int temp;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d",&N);
		vector<int> Kor;
		vector<int> Rus;
		for(int j = 0; j < N; j++){
			scanf("%d",&temp);
			Rus.push_back(temp);
		}
		for(int j = 0; j < N; j++){
			scanf("%d",&temp);
			Kor.push_back(temp);
		}
		sort(Rus.begin(), Rus.end() );
		sort(Kor.begin(), Kor.end() );
		cout<<search(Rus,Kor)<<endl;
	}
}