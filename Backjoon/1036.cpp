#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

#define MAX_N 50
using namespace std;

int n,k;
string str[MAX_N];
string maxStr;
map<char, int> cToI;
map<char, bool> change;
map<int, char> iToC;

string sum36(string &s1,string &s2){
	string res = "";
	int index1 = s1.size() - 1, index2 = s2.size() -1;
	int next = 0, sum = 0, value1, value2;
	while((index1 >= 0 && index2 >= 0) || next != 0){
		value1 = value2 = 0;
		if(index1 >= 0) value1 = cToI.find( (change.find(s1[index1])->second) ? 'Z' : s1[index1]) -> second;
		if(index2 >= 0) value2 = cToI.find( (change.find(s2[index2])->second) ? 'Z' : s2[index2]) -> second;
		sum = next + value1 + value2;
		next = sum / 36;
		sum =  sum % 36;
		res = iToC.find(sum)->second + res;
		index1--; index2--;
	}
	return res;
}
bool compare36(string &s1,string &s2){
	int index1 = s1.size() - 1, index2 = s2.size() -1;
	if(index1 != index2) return (index1 < index2)? true : false;
	for(int i = index1; i >= 0; i--)
		if(s1[i] != s2[i]) return (s1[i] < s2[i])? true : false;
	return true;
}
void setMax(){
	string ret = str[0];
	for(int i = 1; i < n; i++)
		ret = sum36(ret, str[i]);
	if(compare36(maxStr,ret)) maxStr = ret;
}
void search(){
	int select = 0;
	for(select = 0; select < k; ){
		sort(str, str + n, compare36);
		
	}
}
int main(void){
	char c = '0';
	for(int i = 0; i <= 35; i++){
		if(i == 10) c = 'A';
		cToI.insert(make_pair(c,i));
		change.insert(make_pair(c,false));
		iToC.insert(make_pair(i,c));
		c++;
	}
	cin>>n;
	for(int i =0; i < n; i++)
		cin>>str[i];
	cin>>k;
	cout<<"test "<<sum36(str[0],str[1])<<endl;
	cout<<"test "<<compare36(str[0],str[1])<<endl;
	search();
	cout<<maxStr<<endl;
	cout<<"test "<<sum36(str[0],str[1])<<endl;
	cout<<"test "<<compare36(str[0],str[1])<<endl;
}