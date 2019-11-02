#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX_N 1000
using namespace std;

int n,m;
double cache[MAX_N][2*MAX_N + 1];

double Clime(int day,int now){
	if(day == m) return now >= n ? 1 : 0;
	
	double &ret = cache[day][now];
	
 	if(ret > -0.1) return ret;
	return ret = (0.25*Clime(day+1,now+1) + 0.75*Clime(day+1,now+2));
}
double first(){
	for(int i =0; i < MAX_N; i++)
		for(int j = 0; j<2*MAX_N + 1; j++)
			cache[i][j] = -1;
	return Clime(0,0);
}
double abs(double a,int exp){
	double res = a;
	for(int i = 0; i < exp; i++)
		res *= res;
	return res;
}
double test(){
	double res = 0;
	for(int i=0; i<m; i++){
		if(((m - i) + 2 * i) >= n)
			res += (abs(0.75,i) + abs(0.25,m-i));
	}	return res;
}
int main(void){
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d %d",&n,&m);
		printf("%0.10lf\n",first());
	}
}
/*캐시를 매번 만들어서 동적할당한 후 초기화 시키는 것은 시간이 더 많이 든다.*/