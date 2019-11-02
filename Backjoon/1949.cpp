#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cstring>
#include<iostream>
#define MAX_N 10000

using namespace std; 

// 자신이나 인접해 있는 마을 중 하나는 우수마을,
// 주변에 우수마을이 있으면 우수마을 불가


struct vilige{
	int person;
	bool isRoot;
	vector< int >list;
	vilige(){
		person = 0;
		isRoot = false;
	}
}typedef vilige;

vilige v[MAX_N];
int cache[MAX_N][2];
int N;

int search(int pre,int index, bool canGreat){
	//cout<<"pre "<<pre<<" index "<<index<<" canGreat "<<canGreat<<endl;
	if(pre !=-1 && v[index].list.size() == 1) return (canGreat) ? v[index].person : 0;
	//cout<<" ok "<<endl;
	
	int &ret = cache[index][canGreat];
	if(ret != -1) return ret;
	
	//상위 마을을 제외한 나머지 마을중 최댓값 구하기,
	// 현제 마을 선택하는 경우와 선택하지 않는 경우 나누어서 구하기,
	
	int res = 0;
	for(int i = 0; i < v[index].list.size(); i++)
		if(v[index].list[i] != pre) res += search(index, v[index].list[i],true);
	
	if(!canGreat) return ret = res;
	
	int res2 = v[index].person;
	for(int i = 0; i < v[index].list.size(); i++)
		if(v[index].list[i] != pre) res2 += search(index, v[index].list[i],false);
	
	return ret = max(res,res2);
}

void inputRoot(){
	int a, b;
	scanf("%d %d",&a,&b);
	a--; b--;
	v[a].list.push_back(b);
	v[b].list.push_back(a);
	//cout<<" a "<<a<<" b "<<b<<endl; 
}

int main(void){
	freopen("1949in.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		scanf("%d",&v[i].person);
	for(int i = 0; i < N - 1; i++)
		inputRoot();
	cout<<search(-1,0,true)<<endl;
}