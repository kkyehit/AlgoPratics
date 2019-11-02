#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int lineCnt[10] = {6,2,5,5,4,5,6,3,7,5};

int N;

void increaseSec(string &str, int index){
	if(index < 0) return;
	
	if(str[index] == '9'){
		str[index] = '0';
		increaseSec(str,index -1);
	}
	else str[index]++;
}
	
int getLineCnt(string &str){
	int res = 0;
	for(int i = 0; i < str.size(); i++){
		res += lineCnt[str[i] - '0'];
	}
	return res;
}

int search(string &str, int &pivot){
	int res = 1;
	increaseSec(str,str.size() - 1);
	while(getLineCnt(str) != pivot){
		res += 1;
		increaseSec(str,str.size() - 1);
	}
	return res;
}

int main(void){
	string str;
	int pivot;
	cin>>str;
	N = str.size();
	pivot = getLineCnt(str);
	printf("%d\n",search(str,pivot));
}