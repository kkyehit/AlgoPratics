#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

char getOpen(char &a){
	if( a == ')') return '(';
	if( a == ']') return '[';
	if( a == '}') return '{';
	return 0;
}

bool check(string &s){
	stack<char> remaining;
	for(int i = 0; i < s.size(); i++){
		if(remaining.empty()){
			remaining.push(s.at(i));
			continue;
		}
		char stackTop = remaining.top();
		if(stackTop == getOpen(s.at(i)))
			remaining.pop();
		else
			remaining.push(s.at(i));
	}
	if(remaining.size() == 0 ) return true;
	return false;
}

int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		string s;
		cin>>s;
		if(check(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}