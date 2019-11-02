#include<stdio.h>
#include<stdlib.h>
#define MAX_L 200

using namespace std;

char input[MAX_L + 10];
char pattern[4][10] ={"10","0","1","01"};

bool search(int index, int patternIndex){
	if(!input[index]) return (patternIndex == 0 ||patternIndex == 3)?true: false;
	int i = 0;
	while(pattern[patternIndex][i]){
		if(!(input[index] == pattern[patternIndex][i]))
			return false;
		index++; i++;
	}
	bool res = false;
	if(patternIndex == 0){
		if(!res)
			res = search(index,1);
		
	}else if(patternIndex == 1){
		if(!res)
			res = search(index,1);
		if(!res)
			res = search(index,2);
		
	}else if(patternIndex == 2){
		if(!res)
			res = search(index,2);
		if(!res)
			res = search(index,3);
		if(!res)
			res = search(index,0);
		
	}else if(patternIndex == 3){
		if(!res)
			res = search(index,3);
		if(!res)
			res = search(index,0);
		
	}
	return res;
}

int main(void){
	freopen("1013.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",input);
		if(search(0,0)) printf("YES\n");
		else{
			if(search(0,3)) printf("YES\n");
			else printf("NO\n");
		}
	}
}