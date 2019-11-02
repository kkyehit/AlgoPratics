#include "stdConvert.h"
#include<math.h>
#define MAX 200

void setStd(){
	char in[] = "PotionInput.txt";
	char out[] = "Output2.txt";
	convertStd c(in,out);
}

int r[MAX],p[MAX],n;

int gcd(int a, int b){
	if(b == 0 ) return a;
	return gcd(b, a%b);
}

void search(){
	vector<int> res(n);
	for(int i = 0; i <n; i++)
		if(p[i] < r[i]){
			res[i] = r[i] - p[i];
			p[i] = r[i];
		}
	
	int minGcd = r[0];
	for(int i = 1; i <n; i++){
		minGcd = gcd(minGcd,r[i]) ;
	}
	for(int i = 0; i <n; i++)
		r[i] /= minGcd;
	int minBottle = 1;
	for(int i = 0; i <n; i++){
		if(p[i] / r[i] > 0){
			int add = (p[i] % r[i] == 0)? 0 : 1;
			minBottle = max(minBottle,p[i] / r[i] + add);
		}
	}
	for(int i = 0; i <n; i++)
		cout<<r[i]*minBottle - p[i] + res[i]<<" ";
	cout<<endl;
	
}

int main(void){
	setStd();
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		for(int j = 0; j < n; j++)
			scanf("%d",&r[j]);
		for(int j = 0; j < n; j++)
			scanf("%d",&p[j]);
		search();
	}
}
