#include <stdio.h>
#include <iostream>
#include <cstring>
#define MAX_N 2500

using namespace std;

int cache[MAX_N];
bool p[MAX_N][MAX_N];
int n;

int search(int index){
	if(index >= n) return 0;
	
	int &ret = cache[index];
	if(ret != -1) return ret;
	
	ret = (1 + search(index + 1));
	
	for(int i = index + 1; i < n; i++)
		if(p[index][i]) 
			ret = min(ret, 1 + search(i + 1));
	return ret;
}

int main(void){
	freopen("./1509_in","r",stdin);
	char str[MAX_N + 1];
	scanf("%s",str);
	
	memset(cache, -1, sizeof(cache));
	memset(p, 0, sizeof(p));
	n = strlen(str);
	
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == 0) p[j][j] = true;
			else if(i == 1) p[j][j+i] = (str[j] == str[j + i]);
			else if(j + i < n) p[j][j+i] = (p[j + 1][j + i -1]) ? (str[j] == str[j + i]) : false; 
		}
	}
	printf("%d\n",search(0));
}
