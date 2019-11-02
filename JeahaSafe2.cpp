#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> getPartialMatch(const string& s){
	int n = s.size();
	vector<int> pi(n,0);
	int begin = 1, matched = 0;
	while(begin + matched < n){
		if(s.at(begin + matched) == s.at(matched)){
			matched++;
			pi[begin + matched - 1] = matched;
		}else{
			if(matched == 0) begin++;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
int kmpSearch(const string &H, const string &N){
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	while(begin < n - m){
		if(matched < m && H.at(begin + matched) == N.at(matched)){
			matched++;
			if(matched == m) return begin;
		}else{
			if(matched == 0) begin++;
			else{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}

string str[101];
int n;

int search(){
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0) res += kmpSearch(str[i - 1] + str[i - 1], str[i]);
		else  res += kmpSearch(str[i] + str[i], str[i - 1] ) ;
	}
	return res;
}

int main(void){
	freopen("JeahaSafeInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(int i = 0; i <= n; i++)
			cin>>str[i];
		cout<<search()<<endl;
	}
}