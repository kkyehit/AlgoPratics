#include<stdio.h>
#include<algorithm>
#define MAX_N 5000000

using namespace std; 

int list[MAX_N], n;

int search(int begin, int end, int value){
	if(begin == end) return (list[begin] == value)? 1 : 0;
	
	int mid = (begin + end ) / 2;
	if(value <= list[mid]) return search(begin, mid, value);
	return search(mid + 1, end, value);
}

int main(void){
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++) scanf("%d",list + i);
	sort(list,list + n);
	
	int m, tmp;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&tmp);
		int res = search(0,n - 1, tmp);
		printf("%d ",res);
	}
}