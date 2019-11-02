#include<stdio.h>
#include<iostream>

using namespace std;

struct person{
	int num;
	person *next, * prev;
	person(int _num);
}typedef person;

person::person(int _num){
	num = _num;
	next = prev = NULL;
}

struct circleList{
	int size;
	person *head,*tail;
	circleList();
	void push_back(int _num);	
	person* erase(person *iter);
}typedef circleList;

circleList::circleList(){
	size = 0;
	head = tail = NULL;
}
void circleList::push_back(int _num){
	person *temp = new person(_num);
	if(tail != NULL){
		tail -> next = temp;
		temp -> prev = tail;
		tail = temp;
		tail -> next = head;
		head -> prev = tail;
	}else{
		head = tail =temp;
	}
	size++;
}
person* circleList::erase(person *iter){
	person *tempPrev = iter->prev, *tempNext = iter->next;
	tempPrev -> next = tempNext;
	tempNext -> prev = tempPrev;
	size--;
	if(iter == head) head = tempNext;
	delete iter;
	return tempNext;
}

int N,K;

void makeListAndSearch(circleList &mylist){
	for(int i = 1; i <=N; i++){
		mylist.push_back(i);
	}
	
	person *now = mylist.head;
	while(mylist.size > 2 ){
		now = mylist.erase(now);
		for(int i = 1; i < K; i++)
			now = now -> next;
	}
}

int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&N,&K);
		circleList mylist;
		makeListAndSearch(mylist);
		if(mylist.head != NULL)
			cout<<mylist.head->num<<" "<<mylist.head->next->num<<endl;
		else
			cout<<"error"<<endl;
	}
}