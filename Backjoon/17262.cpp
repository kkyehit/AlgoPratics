#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n; 
	scanf("%d",&n);
	
	int start[n], end[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d",&start[i],&end[i]);
	}
	/*for(int i = 0; i < n; i++){
		printf("%d %d\n",start[i],end[i]);
	}*/
	sort(start, start + n);
	sort(end, end + n);
	
	int res = (start[n - 1] - end[0] < 0)? 0 : start[n - 1] - end[0];
	printf("%d\n",res);
}