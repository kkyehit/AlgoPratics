#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#define MAX_N 2000

using namespace std; 

char pic[MAX_N][MAX_N];
char nice[MAX_N][MAX_N];
int hp, wp, hm, wm;

vector<int> searchKMP(int h, int w){
	vector<int> res(w,0);
	int matched = 0, begin = 1;
	while(begin + matched < w){
		if(pic[h][begin + matched] == pic[h][matched]){
			matched++;
			res[begin + matched - 1] = matched;
		}else{
			if(matched == 0) begin++;
			else{
				begin = begin + matched - res[matched - 1];
				matched = res[matched - 1];
			}
		}
	}
	return res;
}
vector<int> searchPoint(int h){
	vector<int>res;
	int begin = 0, matched = 0;
	vector<int>pi = searchKMP(0,wp);
	while(begin + wp <= wm){
		if(matched < wp && nice[h][begin + matched] == pic[0][matched]){
			matched++;
			if(matched == wp) {
				//printf("same : %d %d ... [%c %c]\n",h,begin,nice[h][begin],pic[0][0]);
				res.push_back(begin);
			}
		}
		else{
			if(matched == 0) begin++;
			else{
				begin = begin + matched - pi[matched -1];
				matched = pi[matched - 1];
			}
		}
	}
	return res;
}
bool searchCnt(int y, int x){
	for(int i = 1; i < hp; i++){
		if( y + i >= hm) return false;
		for(int j = 0; j < wp; j++){
			if( x + j >= wm) return false;
			if(nice[y + i][x + j] != pic[i][j]) return false;
		}
	}
	return true;
}

int search(){
	vector< vector<int> > list;
	for(int i = 0; i < hm; i++) list.push_back(searchPoint(i));
	int res = 0;
	for(int i = 0; i < list.size(); i++){
		for(int j = 0; j < list[i].size(); j++){
			if(searchCnt(i, list[i][j])) res++;
			//printf("%d %d ... %d\n",i,list[i][j],res);
		}
	}
	return res;
}

int main(void){
	scanf("%d %d %d %d",&hp,&wp,&hm,&wm);
	for(int i = 0; i < hp; i++)
		for(int j = 0; j < wp; j++){
			scanf("%c",&pic[i][j]);
			if(pic[i][j]=='\n')j--;
		}
	
	for(int i = 0; i < hm; i++)
		for(int j = 0; j < wm; j++){
			scanf("%c",&nice[i][j]);
			if(nice[i][j]=='\n')j--;
		}
	printf("%d\n",search());
}