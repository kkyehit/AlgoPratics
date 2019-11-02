#include "stdConvert.h"
#define MAX_N 3
#include <sstream>
#include <algorithm>

int min(int a,int b){
	if(a < b) return a;
	return b;
}int max(int a,int b){
	if(a > b) return a;
	return b;
}
void setStd(){
	char in[] = "TicInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int C;
char Board[MAX_N][MAX_N];
int cache[19683];

int state(){
	int res = 0;
	for(int j = 0;j < MAX_N; j++){
		for(int k = 0; k < MAX_N ; k++){
			res *= 3;
			if(Board[j][k] == 'x') res++;
			else if(Board[j][k] == 'o') res += 2;
		}
	}
	return res;
}
bool isFinished(char turn){
	//case1: 가로
	int k,j;
	
	for(j = 0;j < MAX_N; j++){
		for(k = 0; k < MAX_N ; k++){
			if(Board[j][k] != turn){
				break;
			}
		}
		if(k == MAX_N) return true;
	}
	//case2: 세로
	for(j = 0;j < MAX_N; j++){
		for(k = 0; k < MAX_N ; k++){
			if(Board[k][j] != turn){
				break;
			}
		}
		if(k == MAX_N) return true;
	}
	//대각선ㄴ
	for(j = 0;j < MAX_N; j++){
		if(Board[j][j] != turn){
			break;
		}
	}
	if(j== MAX_N) return true;
	
	for(j = 0;j < MAX_N; j++){
		if(Board[j][MAX_N - j - 1] != turn){
			break;
		}
	}
	if(j== MAX_N) return true;
	return false;
}
int tictectoe(char turn){
	if(isFinished('o'+'x'-turn)) {
		return -1;
	}
	
	int &ret = cache[state()];
	if(ret != -2 ) return ret;
	
	
	int maxium = 2;
	for(int j = 0;j < MAX_N; j++){
		for(int k = 0; k < MAX_N ; k++){
			if(Board[j][k] == '.'){
				Board[j][k] = turn;
				maxium = min(maxium,tictectoe('o'+'x'-turn ));
				Board[j][k] = '.';
			}
		}
	}
	if(maxium == 2 || maxium == 0) return ret = 0;
	return ret = 0-maxium;
}

int main(){
	setStd();
	scanf("%d",&C);
	
	for(int i = 0; i < 19683; i++){
		cache[i] = -2;
	}
	
	for(int i = 0; i < C; i ++){
		int countX = 0, countO =0 ;
		char turn;
		for(int j = 0;j < MAX_N; j++){
			for(int k = 0; k < MAX_N ; k++){
				scanf("%c",&Board[j][k]);
				if(Board[j][k] == 'x') countX++;
				else if(Board[j][k] == 'o') countO++;
				else if(Board[j][k] == '\n') k--;
			}
		}
		if(countX == countO) turn = 'x';
		else turn = 'o';
		
		if(isFinished(turn)) cout<<"TIE"<<endl;
		
		else if(tictectoe(turn) == -1) cout<< (char)('x'+'o'-turn) <<endl;
		else if(tictectoe(turn) == 1) cout<<turn<<endl;
		else cout<<"TIE"<<endl;		
	}
}