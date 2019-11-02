#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void initCache(int **cache,int n, int m){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cache[i][j] = -1;
}
int search(int* seq1,int* seq2, int** cache, int n, int m, int index1,int index2){
	if(n == 0) return 0;
	int &ret = cache[index1+1][index2+1];
	if(ret != -1) return ret;
	ret = 1;
	int temp = 1;
	for(int i = index1+1; i < n; i++){
		if((index1 == -1 || seq1[index1] < seq1[i])
		   &&(index2 == -1 || seq2[index2] < seq1[i])){
			temp += search(seq1,seq2,cache,n,m,i,index2);
		}
		
		if(temp > ret) ret = temp;
		temp = 1;
	}
	temp = 1;
	for(int j = index2+1; j < m; j++){
		if((index2 == -1 || seq2[index2] < seq2[j])
		   &&(index1 == -1 || seq1[index1] < seq2[j])){
			temp += search(seq1,seq2,cache,n,m,index1,j);
		}
		if(temp > ret) ret = temp;
		temp = 1;
	}
	return ret;
}

int main(void){
	int C,N,M;
	int *seq1,*seq2;
	int **cache;
	int *res;
	scanf("%d",&C);
	res = new int[C];
	for(int i = 0; i < C; i++){
		scanf("%d %d",&N,&M);
		seq1 = new int[N];	
		seq2 = new int[M];	
		cache = new int*[N+1];
		for(int j = 0; j < N + 1; j++)
			cache[j] = new int[M+1];
		initCache(cache,N+1,M+1);
		for(int j = 0; j < N; j++)
			scanf("%d",seq1+j);
		for(int j = 0; j < M; j++)
			scanf("%d",seq2+j);
		
		res[i] = search(seq1,seq2,cache,N,M,-1,-1) -1 ;
		delete seq1;
		delete seq2;
		delete cache;
	}
	for(int i = 0; i < C; i++)
		printf("%d\n",res[i]);
}