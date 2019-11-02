#include <stdio.h>
#include <algorithm>

#define MAX_N 100000
using namespace std;

int list[MAX_N];
int n, m;

bool search(int a){
	int left = 0, right = n;
	int mid = (left + right) / 2;
	
	for(int i = 0; i < 100; i++){
		//printf("%d %d\n",left,right);
		mid = (left + right) / 2;
		if(list[mid] == a) return true;
		if(left == right) break;
		else if(list[mid] < a) left = mid + 1;
		else if(list[mid] > a) right = mid;
	}
	return false;
}

int main(void){
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",&list[i]);
	sort(list, list + n);
	
	int a;
	scanf("%d",&m);
	for(int i = 0 ; i < m; i++){
		scanf("%d",&a);
		printf("%d\n",search(a));
	}
}