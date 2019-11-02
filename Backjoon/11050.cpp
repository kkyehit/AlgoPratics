#include <stdio.h>
#include <cstring>

using namespace std;

int C[11][11];

int init_C(){
	memset(C,0,sizeof(C));
	for(int i  = 0; i < 11; i++){
		if(i == 0) {
			C[i][i] = 1;
			continue;
		}
		for(int j = 0; j < 11; j++){
			if(i == j){ 
				C[i][j] = 1;
				break;
			}else if(j == 0){ 
				C[i][j] = 1;
				continue;
			}
			C[i][j] = C[i -1][j -1] + C[i -1][j];
		}
	}
}

int main(void){
	int N, K;
	init_C();
	scanf("%d %d",&N,&K);
	printf("%d\n",C[N][K]);
}