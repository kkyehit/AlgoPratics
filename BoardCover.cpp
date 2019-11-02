#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}};

void test(vector<vector<int> > &board) {
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			cout<<board[i][j];	
		}
		cout<<endl;
	}
	cout<<endl;
}
bool cover(vector<vector<int> > &board, int index ,int y, int x){
	for(int i =0; i<3; i++){
		if(y+coverType[index][i][0]>=board.size() || x+coverType[index][i][1] >= board[y].size() 
			|| x+coverType[index]<=0) return false;
		if(board[y+coverType[index][i][0]][x+coverType[index][i][1]] == 1 ) return false;
	}
	for(int i =0; i<3; i++){
		board[y+coverType[index][i][0]][x+coverType[index][i][1]]++;
	}
	return true;
}

bool recover(vector<vector<int> > &board, int index ,int y, int x){
	for(int i =0; i<3; i++){
		board[y+coverType[index][i][0]][x+coverType[index][i][1]]--;
	}
	return true;
}
int search(vector< vector<int> > &board ){
	int curY=-1,curX=-1;
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++){
			if(board[i][j] == 0){
				curY = i;
				curX = j;
				break;
			}
		}
		if(curY != -1) break;
	}
	if(curY == -1) return 1;
	
	int res = 0;
	for(int i =0; i<4; i++){
		if(cover(board,i,curY,curX)){
			res += search(board);
			recover(board,i,curY,curX);
		}
	}
	return res;	
}


int main (void) {
	int C,H,W;
	char input;
	int res[10];
	scanf("%d",&C);
	for(int i = 0; i<C; i++){
		scanf("%d %d",&H,&W);
		vector< vector<int> > board(H, vector<int>(W) );
		for(int j = 0; j < H; j ++){
			for(int k = 0; k < W; k++){
				scanf("%c",&input);
				if(input == '#')board[j][k] = 1;
				else if(input == '.')board[j][k] = 0;
				else if(input=='\n') k--;
			}
		}
		res[i] = search(board);
	}
	for(int i = 0; i<C; i++)
		cout<<res[i]<<endl;
}
