#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void test(vector<int> &a){
	for(int i = 0; i<a.size(); i++)
		cout<<a[i];
	cout<<endl;
}

void addTo(vector<int> &a, vector<int> &b, int k){
	test(a);
	test(b);
	a.resize(max(a.size(),b.size() + k));
	for(int i = 0; i < b.size(); i++) a[i + k] += b[i];
	test(a);
	cout<<"------------"<<endl;

}
void subFrom(vector<int> &a, vector<int> &b){
	a.resize(max(a.size(),b.size() + 1));
	for(int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> karatsuba(vector<int> &a, vector<int> &b){
	if(a.size() == 1) return a;
	if(a.size() < b.size()) karatsuba(b,a);
	if(a.size() == 0 || b.size() == 0) return vector<int> ();

	int half = a.size()/2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(),half));
	vector<int> b1(b.begin() + min<int>(b.size(),half), b.end());
	
	vector<int> z0 = karatsuba(a0,b0);
	vector<int> z2 = karatsuba(a1,b1);

	addTo(a0,a1,0);
	addTo(b0,b1,0);

	vector<int> z1 = karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	vector<int> ret;
	addTo(ret, z2, 0);
	addTo(ret, z1, half);
	addTo(ret, z0, half+half);
	return ret;
}

int hug(vector<int> &a, vector<int> &b){
	int allHug = 0;
	vector<int> C = karatsuba(a,b);
	test(C);
	for(int i = a.size()-1; i < b.size() ; i ++)
		if(C[i] == 0 ) {
			++ allHug;
		}
	return allHug;
}

int main(void){
	int C;
	vector<int> mem,fan;
	char input;
	int res[50];
	
	scanf("%d",&C);
	scanf("%c",&input);
	for(int i = 0; i < C; i++){
		mem.clear();
		fan.clear();
		while(true){
			scanf("%c",&input);
			if(input == '\n') break;
			else if(input == 'M') mem.push_back(1);
			else if(input == 'F') mem.push_back(0);
		}
		while(true){
			scanf("%c",&input);
			if(input == '\n') break;
			if(input == '\n') break;
			else if(input == 'M') fan.push_back(1);
			else if(input == 'F') fan.push_back(0);
		}
		res[i] = hug(mem,fan);
	}
	for(int i = 0; i < C; i++)
		printf("%d\n",res[i]);
}