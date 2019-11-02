#include<iostream>
#include<stdio.h>

using namespace std;

const int switchs[10][16] = {
	{3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,3,0,0,0,3,0,3,0,3,0,0,0,0},
	{0,0,0,0,3,0,0,0,0,0,3,0,0,0,3,3},
	{3,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,3,3,3,0,3,0,3,0,0,0},
	{3,0,3,0,0,0,0,0,0,0,0,0,0,0,3,3},
	{0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,3},
	{0,0,0,0,3,3,0,3,0,0,0,0,0,0,3,3},
	{0,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,3,3,3,0,0,0,3,0,0,0,3,0,0}
};
int nowClock[16];

bool checkClock(){
	for(int j = 0; j < 16; j++)
		if(nowClock[j] != 0) return false;
	return true;
}
void add(int index){
	for(int i = 0; i < 16; i++){
		nowClock[i] += switchs[index][i];
		nowClock[i] %= 12;
	}
}
int search(int index){
	if(index == 10) return checkClock() ? 0: 99999;
	int ret = 99999;
	for(int i = 0; i < 4; i++){
		ret = min(ret,i + search(index + 1) );
		add(index);
	}
	return ret;
}

int main(void){
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		for(int j = 0; j < 16; j++){
			scanf("%d",&nowClock[j]);
			nowClock[j] %= 12;
		}
		int res = search(0);
		res = (res == 99999)? -1 : res;
		cout<<res<<endl;
	}
}