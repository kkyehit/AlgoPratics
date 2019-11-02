#include "stdConvert.h"
#define MAX_N 5000
#include<algorithm>

using namespace std;

void setStd(){
	char in[] = "CanadaTripInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int N,K;
int L[MAX_N],M[MAX_N],G[MAX_N];
vector<int> directionLocated;

void makeDirection(){
	directionLocated.clear();
	for(int i = 0; i < N; i++)
		while(M[i] >= 0){
			directionLocated.push_back(L[i] - M[i]);
			M[i] -= G[i];
		}
}
bool isIncludeK(int dis){//잘못 생각했다.
	int countDirection = 0;
	/*for(int i = 0; i < directionLocated.size(); i++)
		if(lo <= directionLocated[i] && directionLocated[i] <= hi)
			countDirection++;*/
	for(int i = 0; i < N; i++)
		if(dis >= L[i] - M[i])
			countDirection += (min(dis,L[i]) - (L[i] - M[i]) ) / G[i] + 1;
	return countDirection >= K;
}



int search(){
	int lo = -1, hi = 8030000;
	while(lo+1 < hi){
		int mid = (lo + hi)/2;
		if(isIncludeK(mid))
			hi = mid;
		else 
			lo = mid;
	}
	return hi;
}

// 정렬 후 k 번쨰 추력 - > 시간 너무 오래 걸린다.
int returnK(){
	sort(directionLocated.begin(), directionLocated.end());
	return directionLocated[K - 1];
}

int main(void){
	setStd();
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&N,&K);
		for(int j = 0; j < N; j++){
			scanf("%d %d %d",&L[j],&M[j],&G[j]);
		}
		//makeDirection();
		cout<<search()<<endl;
	}
}