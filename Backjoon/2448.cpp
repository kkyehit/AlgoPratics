#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

char *tri[3];
int N;

void printStar();


int main(void){
	tri[0] = "*";
	tri[1] = "* *";
	tri[2] = "*****";
	scanf("%d",&N);
	printStar();
}
void printStar(){
	int pivot = 5;
	int blank = 5;
	int printstr;
	for(int i = 0; i < N; i++){
		printstr = 0;
		for(int j = i; j < N; j ++){
			printf(" ");
			printstr++;
		}
		printf("%s",tri[i % 3]);
		printstr += strlen(tri[i % 3]);
		if(printstr >= N + i){
			printf("\n");
			continue;
		}
		while(1){
			if(printstr > N + i)
				break;
			for(int j = 0; j < blank; j++){	
				printf(" ");
				printstr++;
			}
			if(printstr > N + i)
				break;
			printf("%s",tri[i % 3]);
			printstr += strlen(tri[i % 3]);
		}
		blank -= 2;
		printf("\n");
		if(blank < 1){
			pivot = pivot * 2 + 1;
			blank = pivot;
		}
	}
}

/*
void printStar(){
	pair<int, int> p;
	pair<int, int> nextp;
	if(q.empty())
		return;
	p = q.front();
	q.pop();
	while(1){
		if(p.second >= N)
			break;
		for(int i = 0; i < p.first; i++)
			printf(" ");
		printf("*");
		if(q.empty()){
			q.push(make_pair(p.first - 1, p.second + 1));
			q.push(make_pair(1, p.second + 1));
		}else{
			nextp = q.front();
			if(nextp.second != p.second){
				q.push(make_pair(p.first + 2, p.second + 1));
			}else if(nextp.first - p.first != 1){
				q.push(make_pair(p.first - 1, p.second + 1));
			}
		}
		nextp = q.front();
		q.pop();
		if(nextp.second != p.second)
			printf("\n");
		p = nextp;
	}
}
*/