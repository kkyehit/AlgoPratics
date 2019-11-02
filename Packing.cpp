#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>


using namespace std;
struct Obj{
	string name;
	int volume;
	int urgent;
}typedef myObj;

myObj *myobj = new myObj[100];
int C,n,w;
int carry[100];
int cache[1001][100];

int max(int a,int b){
	if(a > b){ 
		return a;
	}
	return b;
}
void test(){
	for(int i = 0 ; i < n; i++)
		cout<<carry[i]<<" ";
	cout<<endl;
}
int search(int restW,int now){
	if(now == n) return 0;
	if(restW < 0) return 0;
	
	int &ret = cache[restW][now];
	if(ret != -1) return ret;

	int res = myobj[now].urgent;
	if(restW - myobj[now].volume < 0){
		ret = search(restW, now + 1);
		carry[now] = ret;
		return carry[now];
	}
	return ret = max(res + search(restW - myobj[now].volume, now + 1), search(restW, now + 1));
}
void searchCarry(int capacitiy, int now, vector<string> &a){
	if(now == n) return;
	if(search(capacitiy,now) == search(capacitiy,now + 1))
		searchCarry(capacitiy,now+1,a);
	else{
		a.push_back(myobj[now].name);
		searchCarry(capacitiy - myobj[now].volume, now + 1, a);
	}
}

int main(void){
	scanf("%d",&C);
	
	for(int i = 0; i < C; i++){
		vector<string> res;
		memset(carry,-1,sizeof(int)*100);
		memset(cache,-1,sizeof(int)*1001*100);
		scanf("%d %d",&n,&w);
		
		for(int j = 0; j < n; j++){
			cin>>myobj[j].name;
			cin>>myobj[j].volume;
			cin>>myobj[j].urgent;
		}
		
		cout<<search(w,0)<<" ";
		searchCarry(w,0,res);
		cout<<res.size()<<endl;
		
		for(int j = 0; j < res.size(); j++)
			cout<<res[j]<<endl;
	}
}