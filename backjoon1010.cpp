#include<stdio.h>

using namespace std;

int C[31][31];
int makeC(){
	for(int i = 0; i < 31; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
}

int main(void){
	int T,N,M;
	makeC();
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&N,&M);
		printf("%d\n",C[M][N]);
	}
}