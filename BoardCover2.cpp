#include "stdConvert.h"
#include <algorithm>
#define MAX_N 10

void setStd(){
	char in[] = "BoardCover2Input.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int H,W,R,C;
vector< vector<pair<int,int> > > rotations;
int blockSize = 0;

int coverd[10][10];
int best;

void test(vector<string> block){
	for(int i = 0; i < block.size(); i++)
		cout<<block[i]<<endl;
	cout<<endl;
}void test(){
	for(int i = 0; i <H; i++){
		for(int j = 0; j < W; j++)
			cout<<coverd[i][j];
		cout<<endl;
	}
}

bool brunch(int placed){
	int rest = 0;
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			if(coverd[i][j] == 0) rest++;
	rest /= blockSize;
	if( best < placed + rest) return true;
	return false;
}

vector<string> rotate(vector<string> block){
	//next에 90만큼 회전한 빈 판 할당 , 가로 세로 크기가 바뀐다
	vector<string> next(block[0].size() , string(block.size(), ' ') );
	for(int i = 0; i < block.size(); i++)
		for(int j = 0; j < block[i].size(); j++){
			next[j][block.size() - 1 - i] = block[i][j];
		}
	return next;
}

void makeRotations(vector<string> block){
	rotations.clear();
	rotations.resize(4);
	for(int rot = 0; rot < 4; ++ rot){
		int originY=-1, originX = -1;
		for(int i = 0; i < block.size(); ++i)
			for(int j = 0; j < block[i].size(); ++j)
				if(block[i][j] == '#'){
					if(originX == -1){
						originX = j;
						originY = i;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
		block = rotate(block);
		//test(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end() ),rotations.end() );
	blockSize = rotations[0].size();
}


bool set(int y, int x, const vector<pair<int,int> > &block, int delta){
	int res = true;
	for(int i = 0; i < block.size(); i++){
		if(0 <= y + block[i].first && y + block[i].first < H &&
		 0 <= x + block[i].second && x + block[i].second < W){
			coverd[y + block[i].first][x + block[i].second ] += delta;
			if(coverd[y + block[i].first][x + block[i].second ] != 1) res = false;
		}else res = false;
	}
	return res;
}
void search(int placed, vector<string> &board){
	int y = -1, x = -1;
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[i].size(); j++)
			if(coverd[i][j] == 0){
				y = i; x = j;
				break;
			}
		if(y != -1) break;
	}
	if(y == -1) {
		best = max(best,placed);
		return;
	}
	if(!brunch(placed))
		return;
	for(int i = 0; i < rotations.size(); i++){
		if( set(y,x,rotations[i],1) )
			search(placed + 1,board);
		set(y,x,rotations[i],-1);
	}	
	coverd[y][x] = 1;
	search(placed,board);
	coverd[y][x] = 0;
}

int initAndStart(vector<string> &board){
	best = 0;
	for(int i = 0; i < board.size(); i++)
		for(int j = 0; j < board[i].size(); j++)
			coverd[i][j] = ( (board[i][j]== '#') ? 1: 0 );
	search(0,board);
	return best;
}
int main(void){
	int T;
	string temp;
	setStd();
	vector<string> Board,Block;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d %d %d",&H,&W,&R,&C);
		Board.clear();
		Block.clear();
		for(int j = 0; j < H; j++){
			cin>>temp;
			Board.push_back(temp);
		}
		for(int j = 0; j < R; j++){
			cin>>temp;
			Block.push_back(temp);
		}
		makeRotations(Block);
		cout<<initAndStart(Board)<<endl;
	}
}