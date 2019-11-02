#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_L 100000

using namespace std;

struct my_deque{
	int v[100000];
	int front;
	int back;
	int size;
	my_deque(){
		front = back=size = 0;
	}
	int get_front(){
		return v[front];
	}
	int get_back(){
		return v[back];
	}
	bool isEmpty(){
		return (size==0) ? true : false;
	}
	void push(int a){
		v[back++] = a;
		size++;
	}
	void pop_front(){
		front++;
		size--;
	}
	void pop_back(){
		back--;
		size--;
	}
	void front_print(){
		printf("[");
		if(size > 0){
			for(int i = front; i < back -1; i++){
				printf("%d,",v[i]);	
			};
			printf("%d",v[back-1]);
		}
		printf("]\n");
	}
	void back_print(){
		printf("[");
		if(size > 0){
			for(int i = back-1; i > front; i--){
				printf("%d,",v[i]);	
			};
			printf("%d",v[front]);
		}
		printf("]\n");
	}
};

int my_stoi(char *tmp){
	int res =0 ;
	for(int i=0; i < strlen(tmp); i++){
		res *= 10;
		res += tmp[i] - '0';
	}
	return res;
}

int main(void){
	freopen("./5430_in","r+",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		char p[MAX_L + 1] = {0};
		char list[MAX_L*10 + 1] = {0};
		bool rev = false, error = false;
		
		struct my_deque *dq = new struct my_deque();
		
		scanf("%s",p);
		scanf("%d",&n);
		scanf("%s",list);
		
		char *tmp = strtok(list,"[,]");
		while(tmp){
			dq->push(my_stoi(tmp));
			tmp = strtok(NULL,"[,]");
		}
		
		for(int i = 0 ; p[i]; i++){
			if(p[i] == 'R') rev = !rev;
			else{
				if(dq->isEmpty()){
					error = true;
					break;
				}
				if(rev) dq->pop_back();
				else dq->pop_front();
			}
		}
		
		if(error){
			printf("error\n");
		}else{
			if(rev) dq->back_print();
			else dq->front_print();
		}
	}
}