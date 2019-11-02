#include "stdConvert.h"
#define MAX_N 500
#include <sstream>
#include <algorithm>


int c,n,p,l;
string str ="FX", str1 = "X+YF", str2 = "FX-Y";
int MAX = 1000000000 + 1;

int min(int a,int b){
	if(a < b) return a;
	return b;
}
void setStd(){
	char in[] = "DragonInput.txt";
	char out[] = "DragonOutput.txt";
	convertStd c(in,out);
}
int length[51];
void precalc(){
	length[0] = 1;
	for(int i = 1; i<= 50; i ++)
		length[i] = min(MAX, 2*length[i-1] + 2);
}
char seed;
char expand(string &dragonCurve, int gen, int skip){
	if(gen == 0){
		if(skip < dragonCurve.size()) return dragonCurve.at(skip);
		else return '1';
	}
	
	for(int i = 0; i < dragonCurve.size(); i++){
//cout<<"gen : "<<gen<<"	skip: "<<skip<<" len : "<<length[gen]<<endl;
		if(dragonCurve.at(i) == 'X'||dragonCurve.at(i) == 'Y'){
			if(skip >= length[gen]) skip -= length[gen];
			else if(dragonCurve.at(i) == 'X') return expand(str1,gen - 1, skip);
			else if(dragonCurve.at(i) == 'Y') return expand(str2,gen - 1, skip);
		}else if(skip > 0)
			skip--;
		else 
			return dragonCurve.at(i);
	}
	return '2';
}
int printLen;
void deeper(string input, int index){
	if(index == n){
		int i = 0;
		while((printLen++ <= l) && (i < input.size()))
			cout<<input.at(i++);
		return;
	}
	for(int i =0; i < input.size(); i++){
		if(printLen++ < l) return;
		if(input.at(i) == 'X') deeper(str1,index+1);
		else if(input.at(i) == 'Y') deeper(str2,index+1);
		else cout<<input.at(i);
	}
}

int main(void){
	setStd();
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d %d",&n,&p,&l);
		precalc();
		for(int j = 0; j < l ; j ++)
			cout<<expand(str,n,p-1+j);
		cout<<endl;
	}
}