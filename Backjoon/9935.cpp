#include <cstring>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> getVector(string &s){
	int n = s.size();
	int begin = 1, matched = 0;
	vector<int> res(n, 0);
	while(begin + matched < n){
		if(s[begin + matched] == s[matched]){
			++matched;
			res[begin + matched -1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin = begin + matched - res[matched - 1];
				matched = res[matched - 1];
			}
		}
	} 
	return res;
}
vector<int> getMachted(string &s1, string &s2){
	int n = s1.size(), m = s2.size();
	int begin = 0, matched = 0;
	vector<int> res;
	vector<int> p = getVector(s2);
	while(begin <= n - m){
		if(matched < m && s1[begin+matched] == s2[matched]){
			++matched;
			if(matched == m) res.push_back(begin);
		}
		else{
			if(matched == 0)
				begin++;
			else{
				begin = begin + matched - p[matched - 1];
				matched = p[matched - 1];
			}
		}
	}
	return res;
}
string getString(string &s1, string &s2){
	string res = s1;
	vector<int> list;
	string tmp = "";
	int start, end;
	
	int cnt = 0;
	
	while(true){
		list = getMachted(res,s2);
		cout<<"getMachted ... ok ("<<list.size()<<") ... ["<<(cnt++)<<"]"<<endl;
		if(list.size() == 0) break;
		
		list.push_back(res.size());
		tmp = res.substr(0, list[0]);
		start = list[0] + s2.size();
		
		vector<int> point;
		
		for(int i = 1; i < list.size(); i++){
				//cout<<"start : "<<start<<" end : "<<end<<" tmpsize ... "<<tmp.size()<<" i "<<i<<" list[i] "<<list[i]<<endl;
			if(start < list[i]){
				end = list[i];
				tmp += res.substr(start, end - start);
				point.push_back(tmp.size());
				start = end + s2.size();
			}
		}
		cout<<tmp.size()<<endl;
		res = tmp;
	}
	return (res.size())? res : "FRULA";
}
int main(void){
	freopen("./9935_in","r",stdin);
	string s1, s2;
	cin>>s1;
	cin>>s2;
	cout<<getString(s1,s2)<<endl;
}