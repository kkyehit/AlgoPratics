#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int count = 0;
void test(vector< vector<int> > &a){
	for(int j =0; j < a.size(); j ++){
		for(int k = 0; k < a.size(); k++){
			cout<<a[j][k]<<"	";
		}
		cout<<endl;
	}
	cout<<endl;
}
int e(int a,int b){
	int n = a-b;
	if(n < 0) return 0-n;
	return n;
}
bool search(vector< vector<int> > &b,vector< vector<int> > &c, int y, int x){

	
	if(y == 0 && x == 0) return true;
	int next;
	for(int i =0; i < x; i++){
		next = e(i,x);
		if(b[y][i] == next && c[y][i] == -1){
			c[y][i] = 0;
			if(search(b,c,y,i)) return true;
		}
	}
	for(int i =0; i < y; i++){
		next = e(y,i);
		if(b[i][x] == next && c[i][x] == -1){
			c[i][x] = 0;
			if(search(b,c,i,x)) return true;
		}
	}
	return false;
}

int main(void){
	int C,n,input;
	scanf("%d",&C);
	bool res[50];
	
	for(int i = 0; i<C; i++){
		scanf("%d",&n);
		vector< vector<int> > board(n,vector<int>(n));
		vector< vector<int> > cache(n,vector<int>(n,-1));
		for(int j =0; j < n; j ++){
			for(int k = 0; k < n; k++){
				scanf("%d",&input);
				board[j][k] = input;
				if(input == '\n') k--;
			}
		}
		res[i] = search(board,cache,n-1,n-1);
	}
	for(int i = 0; i<C; i++){
		if(res[i])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
}