#include<stdio.h>
#include<iostream>

using namespace std;

string search(string str,int &i){
	i++;
	if(str.at(i) == 'b' || str.at(i) == 'w')
		return ""+string(1,str.at(i));
	string Lu = search(str,i);
	string Ru = search(str,i);
	string Ld = search(str,i);
	string Rd = search(str,i);
	return "x" + Ld + Rd + Lu + Ru;
}

int main(void){
	freopen("QuardTreeInput.txt","r",stdin);
	int C;
	string str;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		cin>>str;
		int j = -1;
		cout<<search(str,j)<<endl;
	}
}