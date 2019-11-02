#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

const int lineCnt[10] = {6,2,5,5,4,5,6,3,7,5};

int N;
int cache[16][110][2];
string str;
	
int getLineCnt(string &str){
	int res = 0;
	for(int i = 0; i < str.size(); i++){
		res += lineCnt[str[i] - '0'];
	}
	return res;
}

int search(int pos, int left, int bigger){
	if(pos == N){
		if(bigger && (left == 0)) return 0;
		else return -1;
	}
	if(left < 0 ) return -1;
	
	int &ret = cache[pos][left][bigger];
	if(ret != -1) return ret;
	
	ret = -2;
	for(int i = (bigger)? 0 : (str[pos] - '0') ; i <= 9; i++){
		int res = search(pos + 1, left - lineCnt[i], bigger || (i > ((str[pos] - '0'))));
		if(res < 0) continue;
		return ret = i;
	}
	return ret;
}

long long int stringToInt(string &str){
	long long int  res = 0;
	for(int i = 0; i < str.size(); i++){
		res *= 10;
		res += (str[i] - '0');
	}
	return res;
}

long long int  getNextTime(int left){
	long long int  res = 0;
	int bigger = 0;
	int next;
	for(int i = 0; i < N; i++){
		res *= 10;
		next = cache[i][left][bigger];
		if(next < 0){
			if(bigger) break;
			bigger = 1;
			next = cache[i][left][bigger];
		}
		left -= lineCnt[next];
		if(left < 0 ) break;
		res += (long long int)next;
	}
	
	return res;
}

int main(void){
	memset(cache,-1,sizeof(cache));
	int left;
	long long int strInt;
	cin>>str;
	N = str.size();
	strInt = stringToInt(str);
	left = getLineCnt(str);
	if(search(0,left,0) >= 0){
		printf("%lld\n",getNextTime(left) - strInt);
	}else{
		memset(cache,-1,sizeof(cache));
		for(int i = 0 ; i < N; i++)
			str[i] = '0';
		str[0] = '1';
		strInt = stringToInt(str)*10 - strInt;
		str[0] = '0';
		
		search(0,left,1);
		
		printf("%lld\n",strInt + getNextTime(left));
	}
}