#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;
int max(int &a,int &b){
	if(a > b) return a;
	return b;
}
int min(int &a,int &b){
	if(a < b) return a;
	return b;
}
int abs(int &a){
	if( a < 0) return 0 - a;
	return a;
}
int search(string &a, int *cache,int index, int type){
	if(index == a.size()) return 0;
	if((index + type) > a.size()) return 11;
	int now = 10, next = index + type;
	int i;
	int &ret = cache[index *3 + type - 3];
	if(ret != -1) return ret;
	
	for(i = index; i < next -1; i++){
		if(a[i] != a[i+1]) break; 

	}
	if((now == 10)&&(i == next -1)) now = 1;
	
	for(i = index; i < next - 2; i++){
		 if(a[i] != a[i + 2]) {
			 break;
		 }
	}
	if((now == 10)&&(i == next -2)) now = 4;
	
	for(i = index; i < next -1; i++){
		if(a[i] - a[i+1] != a[index] - a[index+1]) break; 
	}
	if((now == 10)&&(i == next -1)) {
		if(abs(a[index] - a[index+1]) == 1) now = 2;
		else now = 5;
	}
//	int a1 = search(a,cache,next,3);
//	int a2 = search(a,cache,next,4);
//	int a3 = search(a,cache,next,5);
	ret = now + min(search(a,cache,next,3),min(search(a,cache,next,4),search(a,cache,next,5)));
//	cout<<"	index:"<<index<<" type:"<<type<<" now:"<<now;
//	cout<<" ret:"<<ret<<endl;
//	cout<<"		1:"<<a1 <<" 2:"<<a2 <<" 3:"<<a3 <<endl;
	return ret;
}
int first(string &a){
	int *cache = new int[a.size()*3];
	memset(cache,-1,(a.size()*3)*sizeof(int));
	if(a.size() == 1) return 1;
//	for(int i= 0; i < a.size()*3; i++){
//		if(i % 3 == 0) cout<<"//";
//		cout<<cache[i]<<" ";
//	}
	return min(search(a,cache,0,3),min(search(a,cache,0,4),search(a,cache,0,5)));
}
int main(void){
	int C;
	string input;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		cin>>input;
		cout<<first(input)<<endl;
	}
}