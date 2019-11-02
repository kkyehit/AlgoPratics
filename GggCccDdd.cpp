#include<stdio.h>
#include<iostream>
#include<vector>
#define MOD 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b,a%b) : a;
}

int N,M;

void test(vector<int> &t){
	FOR(i,0,N+1)
		cout<<i<<" : "<<t[i]<<" ";
	cout<<endl;
}
int cache[1001][1001];
void makeCache(){
	FOR(j,1,1001){
		FOR(k,1,1001){
			cache[j][k] = gcd(j,k);
		}
	}
	
}
int search(){
	vector<int> count(N+1,1);
	FOR(i,1,M){
		vector<int> temp(N+1,0);
		FOR(j,1,N + 1){
			FOR(k,1,N + 1){
				int r = cache[j][k];
				temp[r] = (temp[r] + count[j]) % MOD;
			}	
		}
		count = temp;
	}
	
	int res = 0;
	FOR(j,1,N + 1)
		FOR(K,0,j)
			res = ( res + count[j] ) % MOD;
	
	return res;
}
	
int search2(){
	vector< vector<int> > table(N + 1, vector<int>(N + 1, 0));
	vector< int> count(N + 1, 0);
	FOR(j,1,N + 1){
		FOR(k,1,N + 1){
			table[j][cache[j][k]]++;
			count[cache[j][k]]++;
		}	
	}
	FOR(i,2,M){
		vector<int> temp(N+1,0);
		FOR(j,1,N + 1){
			FOR(k,1,j + 1){
				temp[k] = (temp[k] + table[j][k] * count[j]) % MOD;
			}
		}
		count = temp;
	}
	int res = 0;
	FOR(j,1,N + 1)
		FOR(K,0,j)
			res = ( res + count[j] ) % MOD;
	
	return res;
}
int main(void){
	int c;
	scanf("%d",&c);
	makeCache();
	while(c--){
		scanf("%d %d",&N,&M);
		cout<<search2()<<endl;
	}
}