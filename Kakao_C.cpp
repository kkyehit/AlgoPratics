#include<iostream>
#include<vector>
#include<string>

using namespace std;

string S;
vector<string> str;

void test(){
	for(int i = 0; i < str.size(); i++)
		cout<<str[i]<<endl;
}

void subString(){
	int pivot = 0;
	for(int i = 0;i < S.size() - 1; i++){
		if(S.substr(i,2).compare("&&") == 0){
			str.push_back(S.substr(pivot,i - pivot) );
			pivot = i + 2;
		}
	}
	str.push_back(S.substr(pivot) );
}
void subString2(string a, string s[3]){
	int pivot = 0;
	for(int i = 0;i < a.size() - 1; i++){
		if(a.substr(i,2).compare("==") == 0,a.substr(i,2).compare("!=") == 0){
			s[0] =a.substr(pivot,i - pivot) ;
			pivot = i + 2;
			s[1] = a.substr(i,2);
		}
	}
	s[2] = S.substr(pivot) ;
}
string makeString(int n){
	string res = "";
	string temp[n][3];
	for(int i = 0;i < str.size() - 1; i++){
		subString2(str[i],temp[i]);
		
	}
}

int main(void){
	cin>>S;
	subString();
	test();
}