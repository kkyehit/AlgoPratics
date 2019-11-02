#include "stdConvert.h"
#include <algorithm>
#define MAX_N 20

void setStd(){
	char in[] = "DuathlonInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int t,n;
double r[MAX_N],c[MAX_N];

double time(int i, double d){
	return d/r[i] + (t-d)/c[i];
}
double diff(double d){
	double other = time(0,d);
	for(int i = 0; i < n - 1; i++)
		other = min(other,time(i,d));
	return other - time(n-1,d);
}
double maxDiff(){
	double lo = 0, hi = t;
	for(int i = 0; i < 100; i++){
		double aad = (2*lo+hi)/3;
		double add = (lo+2*hi)/3;
		if(diff(aad) > diff(add))
			hi = add;
		else
			lo = aad;
	}
	return (lo+hi)/2;
}

int main(void){
	setStd();
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%lf %lf",&r[i],&c[i]);
	cout<<maxDiff()<<endl;
	
}