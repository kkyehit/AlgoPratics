#include "stdConvert.h"
#define MAX_N 100

void setStd(){
	char in[] = "MeetingRoomInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int N,a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
int cache[MAX_N];



int main(void){
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		memset(cache,-1,sizeof(int)*MAX_N);
		scanf("%d",&N);
		memset(cache,1,sizeof(int)*N);
		for(int j = 0; j < N; j++)
			scanf("%d %d %d %d",&a[j],&b[j],&c[j],&d[j]);
		
	}
}