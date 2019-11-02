#include "stdConvert.h"
#define MAX_N 100
#include<math.h>
#include<algorithm>
#include<queue>

using namespace std;

void setStd(){
	char in[] = "ArcticInput.txt";
	char out[] = "Output3.txt";
	convertStd c(in,out);
}

int N;
vector<pair<float,float> > base;
double dis[MAX_N][MAX_N];

void printDis(){
	for(int j = 0; j < N; j++){
		for(int k= 0; k < N; k++)
			printf("%.2f\t",dis[j][k]);
		cout<<endl;
	}
	cout<<endl;
}
double getDistance(int i, int j){
	return sqrt((base[i].first - base[j].first)*(base[i].first - base[j].first)
				+ (base[i].second - base[j].second )* (base[i].second - base[j].second));
}
void makeDis(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dis[i][j] = getDistance(i,j);
}
//짧은선 우선 선텍
int selected[MAX_N];
double search(){
	double least = 9999990;	
	int pre = -1, next = -1;
	for(int i = 0; i < N - 1; i++){
		least = 999999;
		for(int j = 0; j < N; j++)
			for(int k= 0; k < N; k++)
				if(dis[j][k] != 0 && (selected[j] < 2 && selected[k] < 2 ) ){
					if(least > dis[j][k]){
						least = dis[j][k];
						pre = j;
						next = k;
					}
				}
		dis[pre][next] = 999999;
		dis[next][pre] = 999999;
		selected[pre]++;
		selected[next]++;
	}
	return least;
}

//이분법
bool isOk(double maxdis){
	int line = 0;
	for(int j = 0; j < N; j++)
		for(int k= 0; k < N; k++)
			if(dis[j][k] <= maxdis && dis[j][k] != 0) line++;
	return (line/2 >= N - 1) ? true:false;
}// 묹ㅔ점 => 삼각형 같은 도형모양 생기면 정확하게 x
bool decision(double d){
	vector<bool> visi(N,false);
	visi[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		seen++;
		for(int there = 0; there < N; ++there){
			if(!visi[there] && dis[here][there] <= d){
				visi[there] = true;
				q.push(there);
			}
		}
	}
	return seen == N;
}
double binary(){
	double lo = 0, hi = 1000;
	for(int i = 0; i < 1000; i++){
		double mid = (lo + hi) /2;
		if(decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int main(void){
	setStd();
	int C;
	float x,y;
	scanf("%d",&C);
	for(int i = 0 ; i < C; i++){
		base.clear();
		scanf("%d",&N);
		for(int j = 0; j < N; j++){
			scanf("%f %f",&x,&y);
			base.push_back(make_pair(x,y));
		}
		makeDis();
		memset(selected,0,sizeof(selected));
		printf("%.2lf\n",search());
		//printf("%.2lf\n",binary());
	}
}