#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int price[20];
int preper[20];
int expensive = 0;

int max(int &a, int &b){
	if(a > b) return a;
	return b;
}

int search(int restW, int now, int &n){
	if(now == n ) return 0;
	int ret = search(restW, now + 1, n);
	if(restW - price[now] >=  0){
		ret = max(ret, preper[now] + search(restW - price[now], now + 1, n));
		ret = max(ret, preper[now] + search(restW - price[now], now, n));
	}
//cout<<"	restW : "<<restW<<" now : "<<now<<" n : "<<n<<endl;
	return ret;
}

int calcul(int &m, int &n){
	int restW = 0, temp, tempIndex = 0, totalP = 0;
	for(int i = 0; i < n; i++){
		temp = (m/price[i]) * preper[i];
		if(temp > totalP){
			totalP = temp;
			tempIndex = i;
		}
	}
	for(int i = 1; i < (m/price[tempIndex]); i++){
		restW = (m % price[tempIndex]) + price[tempIndex] * i;
		if(expensive >= restW) break;
	}
	totalP -= preper[tempIndex];
	totalP += search(restW,0,n);
//cout<<"	tempIndex : "<<tempIndex<<" select : "<<m/price[tempIndex]<<" restW : "<<restW<<" totalP : "<<totalP<<endl;
	return totalP;
}

int main(void){
	int c,m,n;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		expensive = 0;
		scanf("%d %d",&n,&m);
		for(int j = 0; j < n; j++){
			scanf("%d %d",&price[j], &preper[j]);
			if(price[j] > expensive) expensive = price[j]; 
		}
		printf("%d\n",calcul(m,n));
	}
	return 0;
}