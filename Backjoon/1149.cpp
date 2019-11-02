#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX_N 1000
#define INFY 1<<30;

using namespace std;

struct RGB{
	int r, g, b;
	RGB():r(0),g(0),b(0){}
};

int cache[MAX_N][1<<3], n;
RGB inputRGB[MAX_N];

int getCost(int select, int index){
	int selected = 0;
	while(!(select & 1)){
		select = select>>1;
		selected++;
	}
	switch(selected){
		case 0:
			return inputRGB[index].r;
		case 1:
			return inputRGB[index].g;
		case 2:
			return inputRGB[index].b;
	}
	return INFY;
}

int search(int index, int canSet){
	if(index == n) return 0;
	
	int &ret = cache[index][canSet];
	if(ret != -1) return ret;
	
	int subSet = (1<<3) -1;
	int res = INFY;
	for(int i = 1; i < subSet + 1; i = i<<1){
		if(!(i & canSet)) continue;
		res = min(res,search(index + 1, subSet - i) + getCost(i,index));
		//cout<<index<<" "<<getCost(i,index)<<" "<<res<<" "<<canSet<<endl;
	}
	return ret = res;
}

int main(void){
	freopen("input.txt","r",stdin);
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d",&inputRGB[i].r,&inputRGB[i].g,&inputRGB[i].b);
	cout<<search(0,(1<<3) -1)<<endl;
}