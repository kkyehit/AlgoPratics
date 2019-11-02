#include "stdConvert.h"
#define MAX_N 20

void setStd(){
	char in[] = "sushiInput.txt";
	char out[] = "sushiOutput.txt";
	convertStd c(in,out);
}


int n,m;
int price[MAX_N+1],preper[MAX_N+1];
int cachePreper[201];
int cachePrice;

int madeCache(int budge){
	if(budge == 0){ 
		cachePrice = 0;
		return (cachePreper[0] = 0);
	}
	
	int &ret = cachePreper[budge];
	if(ret != -1) return ret;
	
	for(int i = 0; i < n; i++){
		if(budge >= price[i]){
			ret = max(ret,preper[i] + madeCache(budge - price[i]));
		}
	}
	if(ret == -1) {
		cachePrice = budge;
		ret = 0;
	}
	return ret;
}

int calc(int budge){
	int res = 0;
cout<<" budge : "<<budge<<" suspect : "<<cachePrice<<" preper[200] : "<<cachePreper[200]<<endl;
	while(budge > 200){
		res += cachePreper[200];
		budge = budge - 200 + cachePrice;
	}
cout<<" res : "<<res<<" madeCache("<<budge<<") "<<madeCache(budge)<<endl;
	return res + madeCache(budge);
}

int sushi3(){
	int ret = 0;
	cachePreper[0] = 0;
	for(int budget = 1; budget <= m; ++budget){
		int cand = 0;
		for(int dish = 0; dish < n; ++dish)
			if(budget >= price[dish] )
				cand = max(cand, cachePreper[(budget - price[dish]) % 201] +preper[dish] );
		cachePreper[budget % 201] = cand;
		ret = max(ret,cand);
	}
	return ret;
	
}

int main(void){
	setStd();
	
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		memset(cachePreper,0,sizeof(int)*201);
		scanf("%d %d",&n,&m);
		m /= 100;
		for(int j = 0; j < n; j++){
			scanf("%d %d",price+j,preper+j);
			price[j] /= 100;
		}
		
		cout<<sushi3()<<endl;
	}
}