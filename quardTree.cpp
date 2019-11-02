#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

string search(string *str, int *i){
	cout<<str->at(*i)<<" "<< str->size()<<" "<<*i<<endl;
	 char now = str->at(*i);
	string s;
	s+=now;
	if(now =='b' || now == 'w') return s;
	*i += 1;
	string one = search(str,i);
	*i += 1;
	string two = search(str,i);
	*i += 1;
	string three = search(str,i);
	*i += 1;
	string four = search(str,i);
	string zero = "x";
	return zero + three + four + one + two;
}

int main(void){	
	int C;
	scanf("%d",&C);
	string str;
	for(int i = 0, param = 0; i < C; i++){
		cin>>str;
		cout<<search(&str,&param)<<endl;
	}
}
