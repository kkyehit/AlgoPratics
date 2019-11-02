#include <iostream>

using namespace std;

typedef long long int int64;

const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int yoon = 29;

int64 getTime(string &str){
	int strSize = str.size();
	int64 res = 0, tmp = 1;
	for(int i = 0; i <strSize; i++){
		res += tmp;
		tmp *= 2;
	}
	return res;
}
int stringToInt(string &str){
	int res = 0;
	for(int i = 0; i <str.size(); i++){
		res *= 10;
		res += str[i] -'0';
	}
	return res;
}
int64 dayToSec(string &str){
	int cal[6];
	string tmp = "";
	for(int i = 0, j=0; i <str.size(); i++){
		if(str[i] == ' ') continue;
		if(str[i] == '/' || str[i] == ':'){ 
			cal[j++] = stringToInt(tmp);
			tmp = "";
		}else tmp += day[i];
	}
	
}
int main(void){
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		string day, time, after;
		cin>>day;
		cin>>time;
		cin>>after;
		day = day + " " + time;
	}
}