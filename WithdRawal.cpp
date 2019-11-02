#include "stdConvert.h"
#include <algorithm>
#define MAX_N 1000

void setStd(){
	char in[] = "WithdRawalInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int c[MAX_N],r[MAX_N];
int n, k;

bool isOk(double rank){
	vector<double> value;
	for(int i = 0; i < n;i++)
		value.push_back(rank*c[i] - r[i]);
	sort(value.begin(), value.end());
	double sum = 0;
	for(int i = n - k; i < n; i++)
		sum += value[i];
	return sum >= 0;
}

double search(){
	double lo = 0, hi = 1;
	for(int i = 0; i < 100; i++){
		double mid = (lo + hi) / 2;
		if(isOk(mid))
			hi = mid;
		else 
			lo = mid;
	}
	return lo;
}

int main(void){
	setStd();
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&n,&k);
		for(int j = 0; j < n; j++)
			scanf("%d %d",&r[j],&c[j]);
		printf("%.10lf\n",search());
	}
}