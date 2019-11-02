#include "stdConvert.h"
#define MAX_N 500
#include <sstream>
#include <algorithm>



void setStd(){
	char in[] = "KLISInput.txt";
	char out[] = "KLISOutput.txt";
	convertStd c(in,out);
}
/*
int C,N,K;
int input[MAX_N + 1];
int cache[MAX_N + 1];
int maxLength;

void test(){
	
	cout<<"input : ";
	for(int i =0; i<N; i++)
		cout<<input[i]<<" ";
	cout<<endl;
	
	cout<<"cache : ";
	for(int i =0; i<N; i++)
		cout<<cache[i]<<" ";
	cout<<endl;
	
}

int search(int index, vector<vector<int> >& list){
	int &ret = cache[index+1];
	if(ret != -1) return ret;
	
	ret = 0;
	int tempIndex = -1, temp = 0;
	for(int i = index+1; i < N; i++){
		if(index == -1 || (input[index] < input[i]) ){
			temp = search(i,list) + 1;
			if(ret < temp){
				ret = temp;
			}
		}
	}
	for(int i = index+1; i < N; i++){
		if(index == -1 || (input[index] < input[i]) ){
			temp = search(i,list) + 1;
			if(ret == temp){
				list[index+1].push_back(i);
			}
		}
	}
	return ret;
}

string str[MAX_N*MAX_N];
int stringIndex = 0;
string to_string(int a){
	string s;
	stringstream ss;
	ss<<a;
	s = ss.str();
	return s;
}
void printRoot(int index, vector<vector<int> >& list,vector<int> &res,int now){
	if(now == maxLength){
		str[stringIndex] = "";
		for(int i = 0; i < maxLength; i++)
			str[stringIndex] += to_string(res.at(i)) + " ";
//		cout<<str[stringIndex]<<endl;
		stringIndex++;
		return;
	}
	if(list[index].size() == 0) {
		return;
	}
	for(int i = 0; i < list[index].size(); i++){
//		cout<<index<<" / "<<list[index][i]<<" ";
		res[now] = input[list[index][i]];
		printRoot(list[index][i] + 1, list,res, now + 1);
	}
}

int main(void){
	setStd();
	
	scanf("%d",&C);
	for(int i=0; i<C; i++){
		memset(cache,-1,sizeof(int)*(MAX_N +1));
		vector<vector<int> > list(MAX_N);
		vector<int> res(MAX_N);
		stringIndex = 0;
		scanf("%d %d",&N,&K);
		for(int j = 0; j < N; j++){
			scanf("%d",input + j);
		}
		maxLength = search(-1,list);
		cout<<maxLength<<endl;
		printRoot(0,list,res,0);
		sort(str,str+stringIndex);
		//for(int i = 0; i < stringIndex; i++)
		//	cout<<str[i]<<endl;	
		cout<<str[K-1]<<endl;
		
		for(int i =0; i<N; i++)
			cout<<list[i].size()<<" ";
		cout<<endl;
		//test();
	}
}*/
int max(int a, int b){
	if(a > b) return a;
	return b;
}
int min(long long a, long long b){
	if(a < b) return a;
	return b;
}

const int Max = 0xff;
int n,c,k;
int cacheLen[501],cacheCnt[501],S[501];
	
int lis(int start){
	int &ret = cacheLen[start + 1];
	if(ret != -1) return ret;
	
	ret = 1;
	for(int i = start + 1; i < n; ++i){
		if(start == -1 || S[start] < S[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

int countSearch(int start){
	if(lis(start) == 1) return 1;
	
	int &ret = cacheCnt[start + 1];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i = start + 1; i < n; i++){
		if((start == -1 || S[start] < S[i]) && lis(start) == lis(i) + 1)
			ret = min(Max, (long long )(ret + countSearch(i) ));
	}
	return ret;
}
void reconstruct(int start,int skip, vector<int>& list){
	if(start != -1) list.push_back(S[start]);
	vector<pair<int,int> > followers;
	
	for(int i = start + 1; i < n; i++){
		if((start == -1 || S[start] < S[i]) && lis(start) == lis(i) + 1)
			followers.push_back(make_pair(S[i],i));
	}
	sort(followers.begin(), followers.end());
	
	for(int i =0; i< followers.size(); ++i){
		int idx = followers[i].second;
		int cnt = countSearch(idx);
		if(cnt < skip) skip -= cnt;
		else{
			reconstruct(idx,skip,list);
			break;
		}
	}
}

void test(){
	
	cout<<"S[i] : ";
	for(int i =0; i<n; i++)
		cout<<S[i]<<" ";
	cout<<endl;
	
	cout<<"lis(i) : ";
	for(int i =0; i<=n; i++)
		cout<<cacheLen[i]<<" ";
	cout<<endl;
	
	cout<<"count(i) : ";
	for(int i =0; i<=n; i++)
		cout<<cacheCnt[i]<<" ";
	cout<<endl;
	
}

int main(void){
	setStd();
	
	scanf("%d",&c);
	for(int i=0; i<c; i++){
		memset(cacheLen,-1,sizeof(int)*(501));
		memset(cacheCnt,-1,sizeof(int)*(501));
		vector<int> list;
		scanf("%d %d",&n,&k);
		for(int j = 0; j < n; j++){
			scanf("%d",S + j);
		}
		cout<<lis(-1) - 1<<endl;
		countSearch(-1);
		reconstruct(-1,k,list);
		for(int j = 0; j < list.size(); j++){
			cout<<list[j]<<" ";
		}
		cout<<endl;
	}
}