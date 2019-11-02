#include<iostream>

using namespace std;

string resultString(string str){
	string front = "", back = "";
	for(int i = 0; i < str.length(); i++){
		if(i%2 == 0) front += str.at(i);
		else back += str.at(i);
	}
	return front + back;
}

int main(void){
	string str;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>str;
		cout<<resultString(str)<<endl;
	}
}