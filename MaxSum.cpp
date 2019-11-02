#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#define MAX 100000
#define INFY -20000001

using namespace std;

int cache[MAX];
int psum[MAX + 1];
int A[MAX], N;
void test(){
	for(int i = 0; i < N; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	for(int i = 0; i <= N; i++)
		cout<<psum[i]<<" ";
	cout<<endl;
	
}

void init(){
	memset(psum,0,sizeof(psum));
	psum[0] = 0;
	
	for(int i = 0; i < N; i++){
		psum[i + 1] += psum[i] + A[i];
	//	cout<<"psum["<<i + 1<<"] ("<< psum[i + 1]<<") += psum["<<i<<"] ("<< psum[i]<<") +A["<<i<<"] ("<<A[i]<<") --->> "<<psum[i]<<endl;
	}
}

int search2(){
	int maxLocation = -1;
	int maxValue = INFY;
	vector<int> locationList;
	/*for(int i = 1; i <= N; i++){
		if(maxValue < psum[i]){
			locationList.clear();
			maxValue = psum[i];
			locationList.push_back(i);
		}
		else if(maxValue == psum[i])
			locationList.push_back(i);
		else if(psum[i - 1] < 0 && psum[i] > 0)
			locationList.push_back(i);
	}
	int minValue = 0, res = INFY;
	locationList.insert(locationList.begin(),0);
	locationList.insert(locationList.end(),N);
	
	
	while(locationList.size() > 0){
		int start = locationList[0], end = locationList[1];
		for(int i = start; i < end; i++){
			minValue = min(minValue,psum[i]);
		}
		res = max(res,psum[end] - minValue);
		//cout<<" start : "<<start<<" end : "<<end<<" minValue : "<<minValue<<" psum : "<<psum[end]<<endl;
		locationList.erase(locationList.begin());
	}*/
	int minValue = 0, res = INFY;
	for(int i = 1; i <= N; i++){
		minValue = min(minValue,psum[i - 1]);
		res = max(res,psum[i] - minValue);
		//cout<<" start : "<<start<<" end : "<<end<<" minValue : "<<minValue<<" psum : "<<psum[end]<<endl;
		
	}
	//cout<<psum[maxLocation]<<" "<<minValue<<" "<<maxLocation<<endl;
	return res;
}

int main(void){
	freopen("MaxSumInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&N);
		for(int i = 0; i < N; i++)
			scanf("%d",A + i);
		init();
		//test();
		cout<<search2()<<endl;
	}
}