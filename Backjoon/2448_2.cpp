#include <stdio.h>
#include <cstring>
#define MAX_LANGTH 3*1024

using namespace std;

char b[MAX_LANGTH][(MAX_LANGTH + 1) * 2];
int N;

void print_b(){
	for(int i = 0; i < N; i++){
		puts(b[i]);
	}
}

void make_b(){
	int flag = 0;
	memset(b, 0 , sizeof(b));
	for(int i = N -1; i >= 0; i--){
		for(int j = 0; j < N*2; j++){
			if( (i + 1) % 3 == 0){
				if(i == (N - 1)){
					for(int k = 0;  k < 5; k++)
						b[i][j++] = '*';
					b[i][j] = ' ';
				}else{
					if(j > 0){
						if(flag == 1){
							if(b[i + 1][j - 1] == '*'){
								flag = 0;
								b[i][j] = ' ';
								continue;
							}else{
								for(int k = 0;  k < 5; k++)
									b[i][j++] = '*';
								b[i][j] = ' ';
							}
						}else{
							if(b[i + 1][j - 1] == '*'){
								flag = 1;
								for(int k = 0;  k < 5; k++)
									b[i][j++] = '*';
								b[i][j] = ' ';
							}else{
								b[i][j] = ' ';
							}
						}
					}else{
						b[i][j] = ' ';
					}
				}
			}else if( (i + 1) % 3 == 2){
				if(j > 0){
					if((b[i + 1][j - 1] == '*') && (b[i + 1][j] == '*') && (b[i][j-1] != '*')){
						b[i][j] = '*';	
					}else{
						b[i][j] = ' ';	
					}
				}else{
					b[i][j] = ' ';
				}
			}else if( (i + 1) % 3 == 1){
				if((j > 0) && ((j + 1) < N*2)){
					if((b[i + 1][j - 1] == '*') && (b[i + 1][j + 1] == '*') && (b[i + 1][j] == ' ')){
						b[i][j] = '*';	
					}else{
						b[i][j] = ' ';	
					}
				}else{
					b[i][j] = ' ';
				}
			}
		}
	}
}

int main(void){
	scanf("%d",&N);
	make_b();
	print_b();
}