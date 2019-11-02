#include "stdConvert.h"
#include <algorithm>

void setStd(){
	char in[] = "LoanInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

double P,N;
int M;

bool isOk(double pay){
	double left = N;
	for(int i = 0; i < M; i++){
		left += left*(P/100)/12;
		left -= pay;
	}
	return left <= 0;
}


double getLeft(double pay){
	double left = N;
	for(int i = 0; i < M; i++){
		left += left*(P/100)/12;
		left -= pay;
	}
	return left;
}

double search(){
	double lo = 0, hi = N + N*(P/12)/100;
	for(int i = 0; i < 1000; i++){
		double mid = (lo + hi) / 2;
		if(isOk(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main(void){
	setStd();
	int T;
	scanf("%d",&T);
	for(int i = 0 ; i < T; i++){
		scanf("%lf %d %lf",&N,&M,&P);
		printf("%.10lf\n",search());
	}
}