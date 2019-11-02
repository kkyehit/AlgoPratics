#include<stdio.h>
#include<iostream>
#include<map>
#define MAX_N 50000

using namespace std;

map<int,int> coord;
int N;
bool isNoNerd(int x,int y){
	map<int,int>::iterator it = coord.lower_bound(x);
	if(it == coord.end()) return false;
	if(y <= it->second) return true;
	return false;
}
void deleteInclude(int x, int y){
	map<int,int>::iterator it = coord.lower_bound(x);
	if(it == coord.begin()){
		return;
	}
	it--;
	while(it -> second <= y){
		if(it == coord.begin()){
			coord.erase(it);
			break;
		}else{
			map<int,int>::iterator jt = it;
			jt--;
			coord.erase(it);
			it = jt;
		}
	}
	coord[x] = y;
}

int registerPerson(int x, int y){
	if(isNoNerd(x,y) ) return coord.size();
	deleteInclude(x,y);
	coord[x] = y;
	return coord.size();
}
int main(void){
	freopen("Nerd2Input.txt","r",stdin);
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d",&N);
		coord.clear();
		int x,y,res = 0;
		for(int i = 0; i < N; i++){
			scanf("%d %d",&x, &y);
			res += registerPerson(x,y);
		}
		cout<<res<<endl;
	}
}