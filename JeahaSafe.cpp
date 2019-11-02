#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

string str[101];
int N;

vector<int> makeTable(string &s){
	int n = s.length();
	vector<int> res(n,0);
	int begin = 1, matched = 0;
	while(begin + matched < n){
		if(s.at(begin + matched)==s.at(matched)){
			matched++;
			res[begin + matched -1] = matched;
		}else{
			if(matched == 0) begin++;
			else{
				begin += matched - res[matched -1];
				matched = res[matched - 1];
			}
		}
	}
	return res;
}
int search(string &a, string &b,int flag){
	int n = a.size(), m = b.size();
	vector<int> pi = makeTable(b);
	int res = 0;
	int begin = 0, matched = 0;
//cout<<" a : "<<a<<" b : "<<b<<" flag : "<<flag<<" aLast : "<<a.at(n-1)<<endl;
	while(begin < n){
		if(matched < m && a.at(begin + matched) == b.at(matched)){
			matched++;
			if(matched == m) return res;
		}
		else{
			if(matched == 0){
				if(!flag) a = a.substr(1,n -1) + a.at(0);
				else a = a.at(n-1) + a.substr(0,n -1);
				res++;
			}else{
				int skip = matched - pi[matched - 1];
				if(!flag) a = a.substr(skip,n -skip) + a.substr(0,skip);
				else a = a.substr(n-skip, skip) + a.substr(0,n -skip);
				res+= skip;
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}

int cal(){
	int res = 0;
	for(int i = 1 ; i <= N; i++){
		int next = search(str[0],str[i],i%2);
//		cout<<" res += "<< next<<endl;
		res += next;
	}
	return res;
}

vector<int> search2(string a,string b){
	int n = a.size(), m = b.size();
	vector<int>res;
	vector<int> pi = makeTable(b);
	int matched = 0;
	for(int i = 0; i < n; i++){
		while(matched >0 && a.at(i) != b.at(matched))
			matched = pi[matched - 1];
		if(a.at(i) == b.at(matched)){
			++matched;
			if(matched == m){
				res.push_back(i - m + 1);
				matched = pi[matched - 1];
				
			}
		}
	}
	return res;
}

int shift(string original, string target){
	return search2(original + original, target)[0];
}

int cal2(){
	int res = 0;
	for(int i = 1; i <=N; i++){
		string a = str[i - 1], b = str[i];
		if(i) res += shift(a,b);
		else res += shift(b,a);
	}
	return res;
}

int main(void){
	freopen("JeahaSafeInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&N);
		for(int j = 0 ; j <= N; j++){
			cin>>str[j];
		}
		cout<<cal2()<<endl;
	}
}