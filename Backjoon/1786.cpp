#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> getPartialMatch(string &N){
	int n = N.size();
	int begin = 1, matched = 0;
	vector<int> res = vector<int>(n,0);
	while(begin + matched < n){
		if(N[begin + matched] == N[matched]){
			matched++;
			res[begin + matched -1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - res[matched -1];
				matched = res[matched -1];
			}
		}
	}
	return res;
}

vector<int> kmpSearch(string &H, string &N){
	int h = H.size(), n = N.size();
	int begin = 0, matched = 0;
	vector<int> p =  getPartialMatch(N);
	vector<int> res;
	while(begin + matched < h){
		if(matched < n && H[begin + matched] == N[matched]){
			matched++;
			if(matched == n) res.push_back(begin+1);
		}else{
			if(matched == 0) begin++;
			else{
				begin += matched - p[matched -1];
				matched = p[matched -1];
			}
		}
		
	}
	return res;
}

int main(void){
	string H, N;
	getline(cin, H);
	getline(cin, N);
	vector<int> res = kmpSearch(H,N);
	printf("%d\n",(int)res.size());
	for(int i = 0 ; i < res.size(); i++){
		printf("%d\n",res[i]);
	}
}