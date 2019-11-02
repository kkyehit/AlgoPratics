#include "stdConvert.h"
#define MAX_N 50
#include <sstream>
#include <algorithm>

int max(int a, int b){
	if( a > b) return a;
	return b;
}
void setStd(){
	char in[] = "NumberGameInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int c,n, Board[MAX_N];
int cache[MAX_N][MAX_N];
int search(int left, int right){
	if(right < left) return 0;
	
	int &ret = cache[left][right];
	if(ret != -1) return ret;
	
	// 다른 사람이 고른것과 내가 고르것 차이의 합이 MAX 가 되게.
	//왼쪽에서 하나 고르기
	ret = Board[left] - search(left + 1, right);
	ret = max(ret , Board[right] - search(left, right - 1) );
	if(right != left){	
		ret = max(ret , -search(left + 2, right) );
		ret = max(ret , -search(left, right - 2) );
	}
	return ret;
}
int main(void){
	setStd();
	
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		memset(cache,-1,sizeof(int)*MAX_N*MAX_N);
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%d",&Board[j]);
		}
		cout<<search(0,n-1)<<endl;
	}
}