#include<stdio.h>
#include<iostream>

using namespace std;

string str;
long long unsigned int psum[1000001];
void makePsum(){
	psum[0] = 0;
	for(int i = 1; i <= str.size(); i++)
		psum[i] = psum[i - 1] +( str.at( i - 1) - '0');
}
void test(){
	for(int i = 1; i <= str.size(); i++)
		cout<<psum[i]<<" ";
	cout<<endl;
}

int main(void){
	cin>>str;
	int c;
	scanf("%d",&c);
	makePsum();
	while(c--){
		int i, j;
		scanf("%d %d",&i,&j);
		if(j < i) swap(j,i);
		long long unsigned int sum = psum[j+1] - psum[i];
		if(sum == 0 || sum == (j - i + 1)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
