#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

int N, M;
vector<int> v;
deque<int> dq;
int cache[51][51];

void print_dq(){
	for(int i = 0 ; i < dq.size(); i++)
		printf("%d ",dq[i]);
	printf("\n");
}

int search(int index);
int op2(int index);
int op3(int index);
int main(void){
	int a;
	memset(cache,-1,sizeof(cache));
	scanf("%d %d",&N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d",&a);
		v.push_back(a);
	}
	for(int i = 1; i <= N; i++ )
		dq.push_back(i);
	printf("%d\n",search(0));
}

int search(int index){
	if(index >= M)
		return 0;
	int res = 0;
	int &ret = cache[index][v.front()];
	if(ret != -1) return ret;
	if(dq.front() == v[index]){
		dq.pop_front();
		res = 0 + search(index + 1);
		dq.push_front(v[index]);
	}else{
		int op2_val = op2(index);
		dq.pop_front();
		int op2_res = op2_val + search(index+1);
		dq.push_front(v[index]);
		for(int i = 0 ; i < op2_val; i++){
			dq.push_front(dq.back());
			dq.pop_back();
		}
		int op3_val = op3(index);
		dq.pop_front();
		int op3_res = op3_val + search(index+1);
		dq.push_front(v[index]);
		for(int i = 0 ; i < op3_val; i++){
			dq.push_back(dq.front());
			dq.pop_front();
		}
		res = (op2_res < op3_res)? op2_res : op3_res;
	}
	return ret = res;
}
int op2(int index){
	int res = 0;
	while(dq.front() != v[index]){
		dq.push_back(dq.front());
		dq.pop_front();
		res++;
	}		
	return res;
}
int op3(int index){
	int res = 0;
	while(dq.front() != v[index]){
		dq.push_front(dq.back());
		dq.pop_back();
		res++;
	}
	return res;
}