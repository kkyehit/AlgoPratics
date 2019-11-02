
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stdio.h>

#define MAX_N 100
#define MAX_M 100

using namespace std;

char Board[MAX_M + 1][MAX_N + 1];
int m,n;
int abs(int a){
	if( a < 0) return 0 - a;
	return a;
}
int min(int a,int b){
	if( a < b) return a;
	return b;
}

bool isEmpty(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if( Board[i][j] == '.' || Board[i][j] == '*' ) continue;
			else return false;
		}
	}
	return true;
}
int cacheX[MAX_M];
int SameAlphaIndex(int y, int x, char &a){
	memset(cacheX,0,sizeof(int)*MAX_M);
	for(int i = y + 1; i < m; i++){
		if(Board[i][x] == a) return i*n + x;
		else if(Board[i][x] == '.'){
			for(int j = x + 1; j < n; j++){
				if(Board[i][j] == '.') continue;
				else if(Board[i][j] == a) return i*n + j;
				else break;
			}
			for(int j = x - 1; j >= 0; j--){
				if(Board[i][j] == '.') continue;
				else if(Board[i][j] == a) return i*n + j;
				else break;
			}
		}
		else break;
	}
	for(int i = y - 1; i >= 0; i--){
		if(Board[i][x] == a) return i*n + x;
		else if(Board[i][x] == '.'){
			for(int j = x + 1; j < n; j++){
				if(Board[i][j] == '.') continue;
				else if(Board[i][j] == a) return i*n + j;
				else break;
			}
			for(int j = x + 1; j >= 0; j--){
				if(Board[i][j] == '.') continue;
				else if(Board[i][j] == a) return i*n + j;
				else break;
			}
		}
		else break;
	}
	for(int i = x + 1; i < n; i++){
		if(Board[y][i] == a) return y*n + i;
		else if(Board[y][i] == '.'){
			for(int j = y + 1; j < m; j++){
				if(Board[j][i] == '.') continue;
				else if(Board[j][i] == a) return j*n + i;
				else break;
			}
			for(int j = y - 1; j >= 0; j--){
				if(Board[j][i] == '.') continue;
				else if(Board[j][i] == a) return j*n + i;
				else break;
			}
		}
		else break;
	}
	for(int i = x - 1; i >= 0; i--){
		if(Board[y][i] == a) return y*n + i;
		else if(Board[y][i] == '.'){
			for(int j = y + 1; j < m; j++){
				if(Board[j][i] == '.') continue;
				else if(Board[j][i] == a) return j*n + i;
				else break;
			}
			for(int j = y + 1; j >= 0; j--){
				if(Board[j][i] == '.') continue;
				else if(Board[j][i] == a) return j*n + i;
				else break;
			}
		}
		else break;
	}
	return -1;
}

char res[25];
void test(){
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout<<Board[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

string cache[25][1<<25];
string search(int index,int select){
	if(isEmpty()){ 
		return "";
	}
	string &ret = cache[index][select];
	if(ret.length() > 0 ) return ret;
	
	int sel = 0;
	
	char a = 'Z' + 1;
	char temp = 'a';
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if( (Board[i][j] != '.')  &&  (Board[i][j] != '*' ) && ( ( sel & (1<< ( Board[i][j] -65 ) ) ) == 0 ) ){
				sel += 1<<(Board[i][j] - 65);
				
				temp = Board[i][j];
				Board[i][j] = '.';
				int next = SameAlphaIndex(i,j,temp);
				if(next != -1){
					Board[next/n][next%n] = '.';
				
					if(a > temp){
						if(search(index+1,select + (1<< ( Board[i][j] -65 ) ) ) != ""){
							a = temp;
							ret = string(0,a);
						}
					}
					Board[next/n][next%n] = temp;
				}
				Board[i][j] = temp;
			}
		}
	}
	
	
	if(a == ('Z' + 1) ) return "";
	else return ret;
}

int main(void){
	scanf("%d %d",&m,&n);
	memset(res,0,sizeof(char)*25);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++){
			scanf("%c",&Board[i][j]);
			if(Board[i][j] == '\n') j--;
		}
	
	
	 cout<<search(0,0)<<endl;
	cout<<endl;
}