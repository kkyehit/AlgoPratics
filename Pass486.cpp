#include "stdConvert.h"
#include<math.h>
#define MAX 10000000

void setStd(){
	char in[] = "PassInput.txt";
	char out[] = "Output2.txt";
	convertStd c(in,out);
}

/*부동 소수점 예외 : 연산자 or 피연산자가 0 인지 확인*/

int minFactor[MAX + 1];
int amountFactor[MAX + 1];
int FactorPow[MAX + 1];
int n, lo, hi;

void eratostenes(){
	minFactor[0] = minFactor[1] = -1;
	for(int i = 2 ; i <= MAX; i++){
		minFactor[i] = i;
	}
	for(int i = 2 ; i <= sqrt(MAX); i++){
		if(minFactor[i] == i){
			for(int k = i*i; k <= MAX; k += i){
				if(minFactor[k] == k)
					minFactor[k] = i;
			}
		}
	}
}
void makeFactor(){
	amountFactor[0] = amountFactor[1] = 1;
	for(int i = 2 ; i <= MAX; i++){
		if(minFactor[i] == i){
			FactorPow[i] = 1;
			amountFactor[i] = 2;
		}
		else{
			int p = i / minFactor[i];
			if(minFactor[i] == minFactor[p])
				FactorPow[i] = FactorPow[p] + 1;
			else
				FactorPow[i] = 1;
			amountFactor[i] = ( amountFactor[p] / FactorPow[i] ) * (FactorPow[i] + 1 );
		}
	}	
}
int search(){
	int res = 0;
	for(int i = lo; i <= hi; i++)
		if(amountFactor[i] == n)
			res++;
	return res;
}

int main(void){
	setStd();
	int c;
	scanf("%d",&c);
	eratostenes();
	makeFactor();
	for(int i = 0 ; i < c; i++){
		scanf("%d %d %d",&n, &lo, &hi);
		cout<<search()<<endl;
	}
}