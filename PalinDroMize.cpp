#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


string H;

vector<int> makeTable(string s){
	vector<int> pi(s.size(),0);
	int begin = 1, matched = 0;
	while(begin + matched < s.size()){
		if(s.at(begin + matched) == s.at(matched)){
			matched++;
			pi[begin + matched -1] = matched;
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

int search(){
	string N = "";
	for(int i =H.size() -1; i >= 0; i--){
		N += H.at(i);
	}
	int Nsize = N.size();
	
	vector<int> pi = makeTable(N);
	int res = 0;
	int begin =0, matched =0;
	while(begin < H.size() ){
		if(matched < Nsize && H.at(begin + matched) == N.at(matched)){
			matched++;
			if(matched == Nsize) return H.size() - Nsize + N.size();
		}else{
			if(matched == 0){
				begin++;
				Nsize--;
			}else{
				Nsize -= matched - pi[matched - 1];
				begin += matched - pi[matched - 1];
				matched = pi[matched -1];
			}
		}
	}
	return 2*H.size();
}

int maxOverlap2(){	
	string N = "";
	for(int i =H.size() -1; i >= 0; i--){
		N += H.at(i);
	}
	
	vector<int> pi = makeTable(N);
	int n = N.size();
	int begin = 0, matched = 0;
	while(begin < n){
		if(matched < n && H.at(begin + matched) == N.at(matched) ){
			matched++;
			if(begin + matched == n) return matched;
		}else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - pi[matched - 1];
				matched = pi[matched -1];
			}
		}
	}
	return 0;
}

int maxOverlap(){
	string N = "";
	for(int i =H.size() -1; i >= 0; i--){
		N += H.at(i);
	}
	int Nsize = N.size();
	
	vector<int> pi = makeTable(N);
	int res = 0;
	int begin =0, matched =0;
	while(begin < H.size() ){
		if(matched < N.size() && H.at(begin + matched) == N.at(matched)){
			matched++;
			if(matched +begin == H.size()) return matched;
		}else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - pi[matched - 1];
				matched = pi[matched -1];
			}
		}
	}
	return 0;
}

int main(void){
	freopen("PalinDroMizeInput.cpp","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		cin>>H;
		cout<<H.size() + (H.size() - maxOverlap() )<<endl;
	}
}