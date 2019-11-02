#include "stdConvert.h"
#include <algorithm>

int min(int a,int b){
	if(a < b) return a;
	return b;
}int max(int a,int b){
	if(a > b) return a;
	return b;
}
void setStd(){
	char in[] = "LunchInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int n;

int test(vector<pair<int, int> > &a){
	for(int i = 0; i < a.size(); i++)
		cout<<a[i].second<<" ";
	cout<<endl;
	for(int i = 0; i < a.size(); i++)
		cout<<a[i].first<<" ";
	cout<<endl;
}

int search(vector<pair<int, int> > &a){
	//점심 느리게 먹는 사람부터 주기
	int time = 0; // 데우는 시간;
	int res = 0; //총 시간
	
	for(int i = 0; i < a.size(); i++){
		time += a[i].second;
	}
	for(int i = 0; i < a.size(); i++){
		res = max(res, time + a[i].first);
		time -= a[i].second;
	}
	return res;
}

int main(void){
	setStd();
	
	int T,temp;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d",&n);
		vector<pair<int, int> > eatting;
		for(int j = 0; j < n; j++){
			scanf("%d",&temp);
			eatting.push_back(make_pair(0,temp));
		}
		for(int j = 0; j < n; j++){
			scanf("%d",&temp);
			eatting[j].first = temp;
		}
		sort(eatting.begin(), eatting.end() );
		cout<<search(eatting)<<endl;
	}
}