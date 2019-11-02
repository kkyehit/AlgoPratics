#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void _1520(){
	freopen("./1520_in","w",stdout);
	srand((unsigned)time(NULL));
	printf("%d %d ", 500, 500);
	for(int i = 0; i < 500; i++){
	 	for(int j = 0; j < 500; j++)
			printf("%d ",rand()%10000);
		printf("\n");
	}
}
void _9935(){
	freopen("./9935_in","w",stdout);
	srand((unsigned) time(NULL));
	for(int i = 0; i < 5000; i++){
		printf("%c",('c'));
	}for(int i = 0; i < 5000; i++){
		printf("%c",('4'));
	}
	printf("\n");
	for(int i = 0; i < 1; i++){
		printf("%c",('c'));
		printf("%c",('4'));
	}
}
void _1967(){
	int n = 10000;
	printf("%d\n",n);
	for(int i =1; i <=n; i++){
		printf("%d %d %d\n", (i+1)/2, i+1, 100);
	}
}
void _7496(){
	int n = 100000, m = 5000;
	printf("%d %d\n",n, m);
	for(int i = 1; i <= n; i++)printf("%d ",i);
	printf("\n");
	printf("1000 10000 2");
}
int main(void){
	_7496();
}