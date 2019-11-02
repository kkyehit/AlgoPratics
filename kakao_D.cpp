#include<iostream>
#include<string>

using namespace std;

int sel;
string brian(string str){
	if(str.compare("") == 0 ) return str;
	string one = "";
	string two = "";
	for(int i = 0; i < str.size(); i++){
		if(str.at(i) == ' ') return "invalid";
	}
	if(str.at(0) > 'Z'){
		if(sel & (1<<(str.at(0) - 'a' ))) return "invalid";
		sel += (1<<(str.at(0) - 'a' ));
		int i;
		for(i = 1; i < str.size(); i++){
			if(str.at(i) == str.at(0)) break;
			if(str.at(i) > 'Z') return "invalid";
		}
		
		if(i == str.size()) return "invalid";
			
		one = str.substr(1,i - 1);
		two = str.substr(i + 1);
		
		string res = brian(two);
//cout<<"res "<<res<<" "<<res.compare("invalid")<<endl;
		if(res.compare("") == 0) return one;
		if(res.compare("invalid") == 0) return "invalid";
		return one + " " + res;
	}
	if(str.at(1) > 'Z'){
		if(sel & (1<<(str.at(1) - 'a' ))) return "invalid";
		sel += (1<<(str.at(1) - 'a' ) );
		int i;
		for(i = 1; i < str.size(); i += 2){
			if(str.at(i) == str.at(1)) one += str.at(i - 1);
			else break;
		}
		if(i <= str.size() ) one += str.at(i - 1);
		two = str.substr(i);
		
		string res = brian(two);
//cout<<"res "<<res<<endl;
		if(res.compare("") == 0) return one;
		if(res.compare("invalid") == 0) return "invalid";
		return one + " " + res;
	}
	int i;
	for(i = 0; i < str.size(); i++){
		if(str.at(i) >= 'A') {
			one += str.at(i);
			one += " ";
		}
		else break;
	}
	one = one.substr(0,one.size() - 1);
	if(i == str.size()) return one;
	two = str.substr(i);
	if(brian(two).compare("invalid") == 0 ){
		two = str.substr(i - 1);
		if(brian(two).compare("invalid") == 0 ) return "invalid";
		return one+" "+two;
	}
	return "invalid";
}

int main(void){
	sel = 0;
	string str;
	cin>>str;
	cout<<brian(str);
}