#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define INFY 999999

using namespace std;

typedef int number;
typedef int index;

const number W[5][5] = {
	{0,8,13,18,20},
	{3,0,7,8,10},
	{4,11,0,10,7},
	{6,8,7,0,11},
	{10,6,2,1,0},
};

void travel(int n, index **P, number& minLength){
	index i,j,k;
	number D[n][1<<n];
	
	int empty = 0, full = (1<<n) -1;
	for(i = 0; i < n; i++)
		D[i][empty] = W[i][0]; // 공집합은 0으로 돌아오는 길이
	
	for(int k = 1; k < n; k++){
		for(int A = 0; A < (1<<n); A++){
			if( !((A ^ (full-1) == 0) || (A & (1<<k))) ) continue;
			for(int i = 1; i < n; i++){
				if(A & (i<<n)) continue;
				int tempLo = -1;
				number minWD = INFY;
				for(j = 1; j < n; j++){
					if(!(A & (1<<j)))continue; // A에 포함되는 원소 찾기,
					if(W[i][j] + D[j][A - (1<<j)] != 0 && minWD > W[i][j] + D[j][A - (1<<j)]){
						tempLo = j; minWD =  W[i][j] + D[j][A - (1<<j)];
					}
					D[i][A] = minWD;
					P[i][A] = tempLo;
				}
			}
		}
		int tempLo = -1;
		number minWD = INFY;
		int A = full - 1;
		for(j = 1; j < n; j++){
			if(minWD > W[0][j] + D[j][A - (1<<j)]){
				tempLo = j; minWD =  W[0][j] + D[j][A - (1<<j)];
			}
		}
		D[0][A] = minWD;
		P[0][A] = tempLo;
		minLength = D[0][A];
	}
}

void printPath(int **P, int n){
	int subset = (1<<n) - 1, next = 0;
	while(subset != 0){
		cout<<P[next][subset]<<"->";
		next = P[next][subset];
		subset = subset - (1<<next);
	}
	cout<<"0"<<endl;
}
int main(void){
	int n = 5;
	index **P;
	P = (index**)malloc(sizeof(index*)*n);
	for(int i = 0; i <= n; i++){
		P[i] = (index*)malloc(sizeof(index)*(1<<n));
	}
	int res = 0;
	travel(n,P,res);
	cout<<" res : "<<res<<endl;
	cout<<" path : ";
	printPath(P,n);
}