#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

void _1149(){
	freopen("input.txt","w",stdout);
	srand( (unsigned) time(NULL) );
	int n = rand()%1000 + 1;
	printf("%d\n",n);
	while(n--){
		printf("%d %d %d\n",rand()%1000 + 1,rand()%1000 + 1,rand()%1000 + 1);
	}
}
void _1014(){
	freopen("1014.txt","w",stdout);
	srand((unsigned) time(NULL));
	int c = 10;
	printf("%d\n",c);
	int n, m;
	int pivot;
	while(c--){
		n = 3;
		m = 3;
		printf("%d %d\n",n,m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				pivot = rand()%2;
				if(pivot == 1) printf(".");
				else if(pivot == 0) printf("x");
			}
			printf("\n");
		}
	}
}
int main(void){
	_1014();
}