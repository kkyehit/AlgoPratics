#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n,m;
string slist[3000];

void search(){
	for(int i = 1; i <= m; i++){
		vector<pair<int,string> > tempList(2,make_pair(0,""));
		for(int j = 0; j < n; j++){
			if(slist[j].length() < i) continue;
			string prefixNow = slist[j].substr(0,i);
			if(prefixNow.compare(tempList[1].second) != 0){
				if(tempList[0].first < tempList[1].first){
					tempList[0].second = tempList[1].second;
					tempList[0].first = tempList[1].first;
				}
				tempList[1].second = prefixNow;
				tempList[1].first = 1;
			}else{
				tempList[1].first++;
			}
			/*int k = 0;
			for(k = 0 ; k < tempList.size(); k++)
				if(tempList[k].second.compare(prefixNow) == 0) {
					tempList[k].first--;
					break;
				}
			if(k == tempList.size()) tempList.push_back(make_pair(-1,prefixNow));*/
		}
		if(tempList[0].first < tempList[1].first){
			cout<<tempList[1].second<<endl;;
		}else{
			cout<<tempList[0].second<<endl;;
		}
		//sort(tempList.begin(),tempList.end());
	}
}

void test(){
		for(int j = 0 ; j < n; j++)
			cout<<slist[j]<<endl;
	
}

int main(void){
	freopen("PrefixInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	for(int i = 0 ; i < c;  i++){
		scanf("%d %d",&n,&m);
		for(int j = 0 ; j < n; j++)
			cin>>slist[j];
		search();
	}
}
