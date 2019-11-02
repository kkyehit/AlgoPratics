#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX_N 50000
#define MAX_A 1000000

using namespace std;

struct fenwickTree{
	vector<int> fenwick;
	fenwickTree(int n){
		fenwick.resize(n+1);
		for(int i = 0; i < fenwick.size(); i++)
			fenwick[i] = 0;
	}
	long long query(int index){
		index++;
		long long res = 0;
		while(index != 0){
			res += fenwick[index];
			index = index & (index - 1);
		}
		return res;
	}
	void add(int index, int value){
		index++;
		while(index < fenwick.size()){
			fenwick[index] += value;
			index += (index & -index);
		}
	}
};
int main(void){
	freopen("MeasureTimeInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		int n,input;
		long long res = 0;
		scanf("%d",&n);
		fenwickTree fenwick(MAX_A);
		while(n--){
			scanf("%d",&input);
			res += fenwick.query(MAX_A - 1) - fenwick.query(input);
			fenwick.add(input,1);
		//	cout<<"fenwick.query(MAX_A - 1) : "<<fenwick.query(MAX_A - 1)<< " fenwick.query("<<input<<") "<<fenwick.query(input)<<" res "<< res<<endl;
		}
		printf("%lld\n",res);
	}
}