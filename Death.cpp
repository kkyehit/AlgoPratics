#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#define MAX_N 200
#define MAX_M 10

const double EPSILON = 1e-9;

using namespace std;

int N,X,M,T;
int Ai[MAX_N], Bi[MAX_M];
int An[MAX_N];

double *per;

void test(double *temp){
	for(int i = 0; i < N; i++)
		printf("%0.5lf ",temp[i]);
	printf("\n");
}

void makeAn(){
	memset(An,0,sizeof(An));
	for(int i = 0; i < N; i++)
		for(int k = -T; k <= T; k++)
			if((Ai[i] + k + N ) % N != i) An[i]++;
} 

void search(){
	double *nowPer = new double[MAX_N];
	memset(nowPer,0,sizeof(nowPer));
	per = nowPer;
	per[0] = 1;
	makeAn();
	for(int i = 0; i < X; i++){
		double *temp = new double[MAX_N];
		memset(temp,0,sizeof(double)*MAX_N);
		for(int j = 0; j < N; j++){
			if(per[j] > EPSILON){
				if(j == 0){
					temp[Ai[j]] += per[j];
				}else{
					for(int k = -T; k <= T; k++){
						if((Ai[j] + k + N ) % N != j) temp[ (Ai[j] + k + N ) % N] += per[j]/(double)An[j];
					}
				}
			}
		}
		delete[] per;
		per = temp;
	}
	for(int i = 0; i < M; i++)
		printf("%0.5lf ",per[Bi[i]]);
	printf("\n");
}


int main(void){
	freopen("DeathInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d %d",&N,&X,&M,&T);
		for(int i = 0; i < N; i++){
			scanf("%d",Ai + i);
			Ai[i]--;
		}
		for(int i = 0; i < M; i++){
			scanf("%d",Bi + i);
			Bi[i]--;
		}
		//search();
		makeAn();
	}
}