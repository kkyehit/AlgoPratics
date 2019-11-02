#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int ceil(float &a){
	int res = a;
	float b = a -res;
	if(b < 0.5) return res;
	return res+1;
}

int test(vector<int> &a){
for(int i = 0; i < a.size(); i++)
	cout<<a[i]<<" ";
cout<<endl;
	float a4 = (float)(a[0] + a[1] + a[2]) / 3;
	float a5 = (float)(a[3] + a[4] + a[5]) / 3;
	float a6 = (float)(a[6] + a[7] + a[8]) / 3;
	int a1 = ceil(a4);
	int a2 = ceil(a5);
	int a3 = ceil(a6);
cout<<"	a1:"<<a1<<"	a2:"<<a2<<"	a3:"<<a3<<endl;
	int b1 = (a1-a[0])*(a1-a[0])+(a1-a[1])*(a1-a[1])+(a1-a[2])*(a1-a[2]);
	int b2 = (a2-a[3])*(a2-a[3])+(a2-a[4])*(a2-a[4])+(a2-a[5])*(a2-a[5]);
	int b3 = (a3-a[6])*(a3-a[6])+(a3-a[7])*(a3-a[7])+(a3-a[8])*(a3-a[8]);

cout<<"	b1:"<<b1<<"	b2:"<<b2<<"	b3:"<<b3<<endl;
cout<<(b1+b2+b3)<<endl;
}
int second(vector<int> &a, int **cache, int x, int y){
	int &ret = cache[x][y-1];
	if(ret != -1) return ret;
	int sum = 0;
	for(int i = x; i < y; i++)
		sum += a[i];
	float tmpeve = (float)sum / (y-x);
	int eve = ceil(tmpeve);
	int square = 0;
	for(int i = x; i < y; i++)
		square += (eve - a[i])*(eve - a[i]);
//cout<<"	x:"<<x<<" y:"<<y<<" eve:"<<eve<<" square:"<<square<<endl;
	return ret = square;
}

int thrid(vector<int> &a, int **cache,int **cache2,int start, int s){
	if(s == 1) return second(a,cache,start,a.size());
	if(s > a.size()) return thrid(a,cache,cache,start,a.size());
//cout<<" 	start:"<<start<<" s:"<<s;
	int &ret = cache2[start][s - 1];
//cout<<"	ret:"<<ret<<endl;
	if(ret != -1 )return ret;
	
	int res = 9999999, temp = 0;
	for(int i = start; i < a.size() - 1; i++){
		temp = second(a,cache,start,i + 1) + thrid(a,cache,cache2,i + 1, s - 1);
//int a1 = second(a,cache,start,i + 1);
//int a2 = thrid(a,cache,i + 1, s - 1);
//cout<<"	"<<start<<" --> "<<(i+1)<<" second:"<<a1;
//cout<<"	//	"<< (i + 1) <<" -> // "<< (s - 1) <<" third:"<<a2<<" temp: "<<temp<<endl;	
		if(res > temp) res = temp;
	}
	return ret = res;
}
int first(vector<int> &a, int S){
	
	sort(a.begin(),a.end());
	int **cache;
	cache = new int*[a.size()];
	for(int i =0; i < a.size(); i++){
		cache[i] = new int[a.size()];
		memset(cache[i],-1,a.size()*sizeof(int));
	}
	int **cache2;
	cache2 = new int*[a.size()];
	for(int i =0; i < a.size(); i++){
		cache2[i] = new int[S];
		memset(cache2[i],-1,S*sizeof(int));
	}
	
	int res = 99999999, temp = 0;
	for(int i =S; i > 0; i--){
		temp = thrid(a,cache,cache2,0,i);
		if(res > temp) res = temp;
	}
	//test(a);
	return res;
	
}
int thrid2(vector<int> &a, int *cache,int start, int s){
	
}
int first2(vector<int> &a, int S){
	
	sort(a.begin(),a.end());
	int *cache;
	cache = new int[a.size()];
	
	int res = 99999999, temp = 0;
	for(int i =S; i > 0; i--){
		if(res > temp) res = temp;
	}
	//test(a);
	return res;
	
}

int main (void){
	int C,N,S,inp;
	vector<int> res;
	scanf("%d",&C);
	for(int i =0; i < C; i++){
		scanf("%d %d",&N,&S);
		vector<int> input;
		for(int j =0; j < N; j++){
			scanf("%d",&inp);
			input.push_back(inp);
		}
		cout<<first(input,S)<<endl;
	}
}