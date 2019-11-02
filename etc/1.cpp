#include <iostream>

using namespace std;

typedef long long int int64;

int n;

int64 pow(int _n){
	int res = 1;
	for(int i = 0; i <_n; i++)
		res *= 2;
	return res;
}

int64 search(int _n){
	if(_n == 0) return 0;
	return (((_n)%3 == 0) ? pow(_n)*3 : pow(_n)) + search(_n-1);
}

int main(void){
	cin>>n;
	cout<<search(n)<<endl;
}