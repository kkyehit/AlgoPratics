#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string getheredName;

vector<int> makeTable(){
	int n = getheredName.length();
	vector<int> res( n, 0 );
	int begin = 1, matched = 0;
	while(begin + matched < n){
		if(getheredName.at(begin + matched) == getheredName.at(matched)){
			matched++;
			res[begin + matched - 1] = matched;
		}else{
			if(matched == 0) begin++;
			else{
				begin += matched - res[matched -1];
				matched = res[matched- 1];
			}
		}
		
	}
	return res;
}

void search(){
	vector<int> pi = makeTable(), res;
	int length = getheredName.length();
	while(length > 0){
		res.push_back(length);
		length = pi[length -1];
	}
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<" ";
}

int main(void){
	string mom,dad;
	cin>>mom;
	cin>>dad;
	getheredName = mom + dad;
	search();
}