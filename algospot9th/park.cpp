#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX_N 20

using namespace std;

const int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,s;
int board[MAX_N][MAX_N];

void search(vector<int> &res){
	int oY = 0, oX = 0, count = 1, dif;
	int sY, sX;
	
	/*
	while(count != board[n-1][m-1]){
		if(oY == sY){
			dif = sX - oY;
			while(abs(dif) != 1){
				if(dif < 0){
					if(board[oY][oX + dif++] != 0) break;
				}else{
					if(board[oY][oX + dif--] != 0) break;
				}
			}
			if(abs(dif) == 1)
				res.push_back(count);
		}else if(oX == sX){
			dif = sY - oY;
			while(abs(dif) != 1){
				if(dif < 0){
					if(board[oY + dif++][oX] != 0) break;
				}else{
					if(board[oY + dif--][oX] != 0) break;
				}
			}
			if(abs(dif) == 1)
				res.push_back(count);
		}else if(abs(sY - oY) == abs(sX - oX) ){
			difY = sY - oY;
			difX = sY - oY;
			while(abs(dif) != 1){
			}
			if(abs(dif) == 1)
				res.push_back(count);
		}
		}else{
			
		}
	}*/
	int difY, difX;
	bool isOk;
	while(count != board[n-1][m-1]){
//cout<<" "<<s<<" "<<n<<" "<<m<<" "<< board[n-1][m-1]<<endl;
		if(s > board[n-1][m-1]) break;
		int i,j;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				if(board[i][j] == count) break;
			if(j != m) break;
		}
		oY = i; 
		oX = j;
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				if(board[i][j] == s) break;
			if(j != m) break;
		}
		sY = i; 
		sX = j;
//cout<<" "<<oY<<" "<<oX<<" "<<sY<<" "<<sX<<endl;
		difY = sY - oY;
		difX = sX - oX;
		isOk = true;
		if(difY == 0){
			while(abs(difX) != 1){
//cout<<" oX: "<<oX<<" difX : "<<difX<<" oX + difX : "<<oX + difX<<endl;
				if(difX < 0 && board[oY][oX + ++difX] != 0) isOk = false;
				else if(difX > 0 && board[oY][oX + --difX] != 0) isOk = false; 
			}
			if(isOk){
				res.push_back(count);
			}
		}else if(difX == 0){
			while(abs(difY) != 1){
//cout<<" oY: "<<oX<<" difY : "<<difY<<" oX + difY : "<<oX + difX<<endl;
				if(difY < 0 && board[oY + ++difY][oX] != 0) isOk = false;
				else if(difY > 0 && board[oY + --difY][oX] != 0) isOk = false; 
			}
			if(isOk){
				res.push_back(count);
			}
		}else if(abs(difY) == abs(difX)){
			while(abs(difY) != 1){
//cout<<" oX: "<<oX<<" difX : "<<difX<<" oX + difX : "<<oX + difX<<endl;
//cout<<" oY: "<<oX<<" difY : "<<difY<<" oX + difY : "<<oX + difX<<endl;
				if ( (difY < 0 && difX < 0)&&(board[oY + ++difY][oX + ++difX] != 0) ) isOk = false;
				else if( (difY < 0 && difX > 0)&&(board[oY + ++difY][oX + --difX] != 0) ) isOk = false;	
				else if( (difY > 0 && difX < 0)&&(board[oY + --difY][oX + ++difX] != 0) ) isOk = false;
				else if( (difY > 0 && difX > 0)&&(board[oY + --difY][oX + --difX] != 0) ) isOk = false;
			}
			if(isOk){
				res.push_back(count);
			}
		}
		else res.push_back(count);
		s++;
		count++;
	}
}

int main(void){
	scanf("%d %d %d",&n,&m,&s);
	memset(board,0,sizeof(int)*MAX_N*MAX_N);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&board[i][j]);
	vector<int> res;
	search(res);
	cout<<res.size()<<endl;
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<endl;
}