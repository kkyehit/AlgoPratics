#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX_N 100000

using namespace std;
/*
int n,m;
int dolls[MAX_N];

void selectDoll(vector<int> &res, int select, int index){
	dolls[index] -= select;
	m -= select;
	res[index] += select;
}

void search(){
	vector<int> res(n,0);
	for(int i = 0; i < n; i++){
		int select = min(m/n, dolls[i]);
		selectDoll(res,select,i);
	}
	while(m > 0){
		for(int i = 0; i < n; i++){
			if(dolls[i] > 0) selectDoll(res,1,i);
			if(m == 0) break;
		}
	}
	for(int i =0; i < n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
}*/

struct dolls{
	long index,count;
	dolls *next,*prev;
	dolls(long a, long b);
}typedef dolls;
dolls::dolls(long a, long b){
	index = a;
	count = b;
}

struct chainDolls{
	dolls *head, *tail;
	int size;
	chainDolls();
	void addDolls(long index, long count);
	dolls* erase(dolls *node);
}typedef chainDolls;
chainDolls::chainDolls(){
	head = tail = NULL;
	size = 0;
}
void chainDolls::addDolls(long index, long count){
	dolls *newDolls = new dolls(index,count);
	if(head != NULL){
		tail -> next = newDolls;
		newDolls -> prev = tail;
		head -> prev = newDolls;
		newDolls -> next = head;
		tail = newDolls;
	}else{
		head = tail = newDolls;
		newDolls -> next = newDolls;
		newDolls -> prev = newDolls;
	}
	size++;
}
dolls* chainDolls::erase(dolls *node){
	dolls *next = node -> next, *prev = node -> prev;
	prev -> next = next;
	next -> prev = prev;
	if(node == tail) tail == prev;
	else if(node == head) head = next;
	delete node;
	size--;
	return next;
}
long n,m;
void search(chainDolls& chain){
	vector<long> res(n,0);
	dolls *now = chain.head;
	long restDolls = n, restGive = m;
	while(m > 0){
		restDolls = chain.size;
		restGive = m;
		long select = max(restGive/restDolls,1l);
		for(int i = 0; i < restDolls; i++){
			long nowSel = min(now->count, select);
			res[now->index] += nowSel;
			now->count -= nowSel;
			m -= nowSel;
			if(now -> count == 0) now = chain.erase(now);
			else now = now -> next;
			if(m == 0) break;
		}
		if(chain.size == 1){		
			res[now->index] += m;
			break;
		}
	}
	for(long i =0; i < n; i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
int main(void){
	freopen("DollsInput.txt","r",stdin);
	int t;
	long count;
	scanf("%d",&t);
	while(t--){
		chainDolls chain;
		scanf("%ld %ld",&n,&m);
		for(long i = 0;i < n; i++){
			scanf("%ld",&count);
			chain.addDolls(i,count);
		}
		search(chain);
	}
}/*
long n,m;
long dolls[MAX_N];

void selectDoll(vector<long> &res, long select, long index){
	dolls[index] -= select;
	m-= select;
	res[index] += select;
}

void search(){
	vector<long> res(n,0);
	long restDolls = n, restGive = m;
	while(m > 0){
		restGive = m;
		long select = max(restGive/restDolls,1l);
		restDolls = 0;
		for(int i = 0; i < n; i++){
			long nowSelect = min<long>(select,dolls[i]);
			if(dolls[i] != 0) selectDoll(res,nowSelect,i);
			if(dolls[i] != 0) restDolls++;
			if(m == 0) break;
		}
	}
	for(long i =0; i < n; i++)
		printf("%ld ",res[i]);
	printf("\n");
}
int main(void){
	freopen("DollsInput.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%ld %ld",&n,&m);
		for(long i = 0;i < n; i++)
			scanf("%ld",dolls + i);
		search();
	}
}*/