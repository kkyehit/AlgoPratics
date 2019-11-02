#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX_N 200000
#define MAX_A 360000

using namespace std;
int n;

vector<int> getPi(string &str){
	int m = str.size();
	int begin = 1, matched = 0;
	vector<int> res(m, 0);
	while(begin + matched < m){
		if(str[matched] == str[begin + matched]){
			matched++;
			res[begin + matched - 1] = matched;
		}else{
			if(matched == 0) begin++;
			else{
				begin = begin + matched - res[matched - 1];
				matched = res[matched - 1];
			}
		}
	}
	return res;
}
vector<int> kmp(string &str1, string &str2){
	int n = str1.size(), m = str2.size();
	int begin = 0, matched = 0;
	vector<int> pi = getPi(str2);
	vector<int> res;
	
	while(begin + m <= n){
		if(matched < m && str1[begin + matched] == str2[matched]){
			matched++;
			if(matched == m) res.push_back(begin);
		}else{
			if(matched == 0) begin++;
			else{
				begin = begin + matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return res;
}

bool search(string &str1, string &str2){
	string comStr = str1 + str1.substr(0, str1.size() - 1);
	return (kmp(comStr,str2).size() != 0) ? true : false;
}

int main(void){
	string str[2];
	scanf("%d",&n);
	
	for(int i = 0; i < 2;i++){
		str[i] = "";
		for(int j = 0; j < MAX_A; j++){
			str[i] += '0';
		}
	}
	
	int tmp;
	for(int i = 0; i < 2;i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&tmp);
			str[i][tmp] = '1';
		}
	}
	if(search(str[0],str[1])) printf("possible\n");
	else printf("impossible\n");
}