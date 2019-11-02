#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using namespace std; 

int N;
int cnt[10000];


void hanoiSearch(int n, int from, int by, int to){
    if (n == 1){
		printf("%d %d\n",from,to);
	}
    else{
        hanoiSearch(n - 1, from, to, by);     // 1번  N-1개의 원반을 기둥3을 거쳐 2로 옮긴다
		printf("%d %d\n",from,to); // 2번  기둥 1에서 1개의 원반을 기둥 3으로 옮긴다
        hanoiSearch(n - 1, by, from, to);  // 3번  기둥 2에서 n - 1개 기둥을 기둥1을 거쳐 3로 옮긴다
    }
}

void addCnt(int index, int add){
	int tmp = cnt[index] + add;
	int exp = tmp /10;
	cnt[index] = tmp % 10; 
	if(exp) addCnt(index-1,add);
}void disCnt(int index, int dis){
	cnt[index] -= dis;
	if(cnt[index] < 0){
		cnt[index] += 10;
		disCnt(index-1,-1);
	}
}void printCnt(){
	for(int i = 0; i< 10000; i++)
		if(cnt[i] != 0)printf("%d",cnt[i]);
	printf("\n");
}

int main(void){
	memset(cnt,0,sizeof(cnt));
	cnt[9999] = 1;
	
	for(int i = 0 ; i < N; i++){
		
	}
		
	
	scanf("%d",&N);
	
	hanoiSearch(N,1,2,3);
}