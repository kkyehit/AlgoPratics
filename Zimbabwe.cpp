#include "stdConvert.h"
#define MAX_N 500
#include <sstream>
#include <algorithm>

int min(int a,int b){
	if(a < b) return a;
	return b;
}
void setStd(){
	char in[] = "ZimInput.txt";
	char out[] = "ZimOutput.txt";
	convertStd c(in,out);
}

int MOD = 1000000007;
int c,m,n;
long long e;

string stringE;

int cache[20][1<<14][2];

int log_E(int a){
	int res = 0;
	while(a/10  != 0){
		res++;
		a /= 10;
	}
	return res;
}
string myToString(long long a){
	string res;
	stringstream s;
	s << a;
	res = s.str();
	return res;
}
int myCharToInt(char a){
	int res = a-48;
	return res;
}
int search(int index, int select, int less, int flag){
	if(index ==stringE.size()){ 
		return ((less == 0) && (flag == 0)) ? 1:0; 
	}
	
	int ret = cache[less][select][flag];
	if(ret != -1) return ret;
	
	ret = 0;
	int nowUseCache = 0;
	for(int i = 0; i < stringE.size(); i++){
		if( ( (select & (1<<i)) == 0) ){
			int num = stringE.at(i)- 48;
			if( (nowUseCache & (1<<num )) == 0) {
				nowUseCache += (1<<num );
				
				int nextSel = select | (1<<i);
				int nextLess = (less*10 + num) % m;
				int nextFlag = 0;

				if(flag == 1){
					if( stringE.at(i) >  stringE.at(index)) continue;
					else if(stringE.at(i) ==  stringE.at(index)) nextFlag = 1;
				}
				ret += search(index + 1, nextSel, nextLess, nextFlag ) % MOD;
			}
		}
	}
	return ret;
}

int search2(int index, int select, int less, int flag){
	if(index ==stringE.size()){ 
		return ((less == 0) && (flag == 0)) ? 1:0; 
	}
	
	int ret = cache[less][select][flag];
	if(ret != -1) return ret;
	
	ret = 0;
	int nowUseCache = 0;
	for(int i = 0; i < stringE.size(); i++){
		if( ( (select & (1<<i)) == 0) ){
			int num = stringE.at(i)- 48;
			if( (nowUseCache & (1<<num )) ) continue;
			
			nowUseCache += (1<<num );
			
			int nextFlag = 0;
			if(flag == 1){
				if( stringE.at(i) >  stringE.at(index)) continue;
				else if(stringE.at(i) ==  stringE.at(index)) nextFlag = 1;
			}
			
			int nextSel = select | (1<<i);
			int nextLess = (less*10 + num) % m;

			
			ret += search(index + 1, nextSel, nextLess, nextFlag ) % MOD;
		}
	}
	return ret;
}
string digits;
int search3(int index, int select, int less, int flag){
	if(index ==stringE.size()){ 
		return ((less == 0) && (flag == 0)) ? 1:0; 
	}
	
	int ret = cache[less][select][flag];
	if(ret != -1) return ret;
	
	ret = 0;
	int nowUseCache = 0;
	for(int i = 0; i < stringE.size(); i++){
		if( ( (select & (1<<i)) == 0) ){
			if(i > 0 && digits[i-1] == digits[i] && ((select & (1<<i -1)) == 0)) continue;
			int num = digits.at(i)- 48;
			
			int nextFlag = 0;
			if(flag == 1){
				if( stringE.at(i) >  digits.at(index)) continue;
				else if(stringE.at(i) ==  digits.at(index)) nextFlag = 1;
			}
			
			int nextSel = select | (1<<i);
			int nextLess = (less*10 + num) % m;

			
			ret += search(index + 1, nextSel, nextLess, nextFlag ) % MOD;
		}
	}
	return ret;
}
int main(void){
	setStd();
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		memset(cache,-1,sizeof(int)*20*(1<<14)*2);
		scanf("%lld %d",&e,&m);
		n = log_E(e);
		stringE = myToString(e);
		digits = stringE;
		sort(digits.begin(), digits.end());
		printf("%d\n",search2(0,0,0,1));
	}
}