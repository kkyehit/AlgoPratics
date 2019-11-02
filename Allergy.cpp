#include "stdConvert.h"
#include <algorithm>
#define MAX_N 50

void setStd(){
	char in[] = "AllergyInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}
vector<string> strTokenize(string str,char pivot){
	vector<string> res;
	int start = 0,now = 0;
	cout<<"str : "<<str<<" pivot: "<<pivot<<endl;
	while(now < str.size()){
		if(str.at(now) == pivot){
			res.push_back(str.substr(start,now-1));
			start = now + 1;
		}
		now++;
	}
	return res;
}

string fri[MAX_N];
int chart[MAX_N][MAX_N], list[MAX_N];
int n,m, best;

void test(){
	for(int i = 0; i < n; i++)
		cout<<fri[i]<<"\t";
	cout<<endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<chart[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void printList(){
	for(int i = 0; i < n; i++)
		cout<<list[i]<<" ";
	cout<<endl;
}

void makeChart(int index, string name){
	for(int i = 0; i < n; i++){
		if(name.compare(fri[i]) == 0){
			chart[index][i] = 1;
			return;
		}
	}
}

bool isBest(int index){// chart에서 1이고 list 에서 0인 부분 하나라도 있으면 true;
	for(int i = 0; i < n; i++)
		if(chart[index][i] == 1 && list[i] == 0) return true;
	return false;
}
bool checkList(){
	for(int i = 0; i < n; i++)
		if(list[i] == 0) return false;
	return true;
}
void selecting(int index,int delta){
	for(int i = 0; i < n; i++)
		if(chart[index][i] == 1) list[i] += delta;
}
void search(int index,int selected){
	//cout<<"index : "<<index<<" selected : "<<selected<<endl;
	//printList();
	if(checkList()){
		best = min(best, selected);
		return;
	}
	if(index == m) return;
	
	if(best <= selected) return; // best보다 이미 선택된 것이 큰 경우
	
	if(isBest(index)){//선택해도 최선이 나올 수 있는 경우
		//이번 음식을 선택 할 경우
		selecting(index,1);
		search(index + 1, selected + 1);
		selecting(index,-1);
	}
	
	//선택하지 않을 경우
	search(index + 1, selected);
}

void search2(int selected){//친구를 기준으로 생각해보자,
	if(best <= selected) return; 
	
	int firstFriend = 0;
	while(firstFriend < n && list[firstFriend] > 0) firstFriend++;
	if(firstFriend == n ) best = min(best,selected);
	
	for(int i = 0; i < m; i++){//먹을수 있는 음식들 고려해보기
		if(chart[i][firstFriend] == 1){
			selecting(i,1);
			search2(selected + 1);
			selecting(i,-1);
		}
	}
}

int initAndStart(){
	best = 9999999;
//	search(0,0);
	search2(0);
	return best;
}

int main(void){
	setStd();
	int T;
	scanf("%d",&T);

	string temp;
	int spec;
	for(int i = 0; i < T; i++){
		memset(chart,0,sizeof(int)*MAX_N*MAX_N);
		memset(list,0,sizeof(int)*MAX_N);
		scanf("%d %d",&n,&m);
		for(int j = 0; j < n; j++)
			cin>>fri[j];
		for(int j = 0; j < m; j++){
			cin>>spec;
			for(int k = 0; k < spec; k++){
				cin>>temp;
				makeChart(j,temp);
			}
		}
		cout<<initAndStart()<<endl;
	}
}
