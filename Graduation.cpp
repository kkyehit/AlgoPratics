#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX_N 12
#define MAX_M 10
#define INFI 98765432

using namespace std;

int subject[MAX_N],semester[MAX_M];
int c;
int N,K,M,L;

int bitCount(int a){
	int res = 0;
	for(int i = 0; i < 31;i++)
		if(a & (1<<i) ) res++;
	return res;
}

void test(){
	for(int i = 0; i < c; i++){
		printf("%d %d %d %d\n",N,K,M,L);
		for(int j = 0; j < N; j++){
			printf("%d %d %d\n",j,bitCount(subject[j]),subject[j]);
		}
		for(int j = 0; j < M; j++){
			printf("%d %d %d\n",j,bitCount(semester[j]),semester[j]);
		}
	}
}
int cache[1<<MAX_N][MAX_M];

int search(int learned, int now){
	//cout<<"learned : "<<learned<<" cnt : "<<bitCount(learned)<<" now : "<<now<<endl;
	if(bitCount(learned) >= K) return 0;
	if(now == M) return INFI;
	
	int &ret = cache[learned][now];
	if(ret != -1 ) return ret;
	
	int canLearn = 0;
	/*for(int i = 0; i < N; i++){
		if( learned & (1<<i) ) continue; // 이미 배운 겨우
		if( !(semester[now] & (1<<i)) ) continue; //이번 학기에 개설이 안되는 경우
		if( subject[i] - ( subject[i] & learned) ) continue;// 선수과목 안배운 경우
		canLearn |= (1<<i);
	}*/
	
	canLearn = ( semester[now] & ~learned);
	for(int i = 0; i < N; i++)
		if((canLearn & (1<<i) ) && (learned & subject[i]) != subject[i] )
			canLearn &= ~(1<<i);
	/*
	canLearn = ( semester[now] & ~learned);
	for(int i = 0; i < N; i++){
		if( subject[i] - ( subject[i] & learned) ) continue;// 선수과목 안배운 경우
		canLearn |= (1<<i);
	}*/
	
	ret = INFI;
	for(int learn = canLearn; learn > 0; learn = ((learn - 1)&canLearn ) ){
		if(bitCount(learn) > L) continue;
 		ret = min(ret, search(learned | learn, now +1) + 1);
	}
	ret = min(ret, search(learned , now +1));
	
	return ret;
	
}

int main(void){
	freopen("GraduationInput.txt","r",stdin);
	
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d %d %d",&N,&K,&M,&L);
		memset(subject,0,sizeof(subject));
		memset(semester,0,sizeof(semester));
		memset(cache,-1,sizeof(cache));
		int input;
		for(int j = 0; j < N; j++){
			int preSub;
			scanf("%d",&preSub);
			for(int k = 0; k < preSub; k++){
				scanf("%d",&input);
				subject[j] |= (1<<input);
			}
		}
		for(int j = 0; j < M; j++){
			int semSub;
			scanf("%d",&semSub);
			for(int k = 0; k < semSub; k++){
				scanf("%d",&input);
				semester[j] |= (1<<input);
			}
		}
		if(search(0,0) == INFI) cout<<"IMPOSSIBLE"<<endl;
		else cout<<search(0,0)<<endl;
	}
}