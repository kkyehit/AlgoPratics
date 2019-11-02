#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int isGroup[26];

int main(void){
	int n, cnt = 0, minuscnt = 0;
	int i;
	char c;
	string str;
	scanf("%d",&n);
	while(n--){
		c = 0;
		memset(isGroup, 0, sizeof(isGroup));
		cin >> str;
		for(i = 0; i < str.length(); i++){
			if(c == str[i]) continue;
			if(isGroup[str[i] -'a'] == 1){
				break;
			}else{
				isGroup[str[i] -'a'] = 1;
				c = str[i];
			}
		}
		if( i == str.length()) cnt++;
	}
	printf("%d\n",cnt);
}