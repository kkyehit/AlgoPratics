#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> h;
int solveStack(){
	stack<int> remaining;
	h.push_back(0);
	int ret = 0;
	for(int i = 0; i < h.size(); i++){
		while(!remaining.empty() && h[remaining.top()] >= h[i]){
			int j = remaining.top();
			remaining.pop();
			int width = -1;
			if(remaining.empty())
				width = i;
			else
				width = ( i - remaining.top() - 1);
			ret = max(ret,h[j]*width);
		}
		remaining.push(i);
	}
	return ret;
}
int main(void){
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		h.clear();
		int N;
		scanf("%d",&N);
		for(int j = 0; j < N; j++){
			int input;
			scanf("%d",&input);
			h.push_back(input);
		}
		cout<<solveStack()<<endl;
	}
}