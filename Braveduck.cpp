#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<cstring>
#define MAX_N 100

using namespace std;

const double EPSILON = 1e-9;

struct point{
	int x, y;
}typedef point;

double dis[MAX_N + 3][MAX_N + 3];
int cache[MAX_N + 2], jump, N;
point rock[MAX_N + 2];
point inputStart,inputEnd;
bool selected[MAX_N + 3];

void initialize(){
	memset(cache,-1,sizeof(cache));
	memset(selected,0,sizeof(selected));
	selected[0] = true;
	for(int i = 0; i < N + 2; i++)
		for(int j = 0; j < N + 2; j++)
			dis[i][j] = sqrt((rock[i].x - rock[j].x)*(rock[i].x - rock[j].x) + (rock[i].y - rock[j].y)*(rock[i].y - rock[j].y));
}
bool search(int index){
	if(dis[index][N+1] - jump <= EPSILON ) return true;
	
	int &ret = cache[index];
	if(ret != -1) return (ret == 0) ? false : true;
	
	for(int i = 1; i <= N; i++){
		if(!selected[i]){
			selected[i] = true;
			if( (dis[index][i] - jump <= EPSILON ) && search(i)) return true;
			selected[i] = false;
		}
	}
	ret = 0;
	return false;
}

int main(void){
	freopen("BraveduckInput.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d",&jump);
		scanf("%d %d",&inputStart.x,&inputStart.y);
		scanf("%d %d",&inputEnd.x,&inputEnd.y);
		scanf("%d",&N);
		for(int j = 1; j < N + 1; j++)
			scanf("%d %d",&rock[j].x,&rock[j].y);
		rock[0] = inputStart;
		rock[N + 1] = inputEnd;
		initialize();
		if(search(0)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}