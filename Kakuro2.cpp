#include "stdConvert.h"
#define MAX_N 20

using namespace std;

void setStd(){
	char in[] = "Kakuro2Input.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int n, board[MAX_N][MAX_N];
int value[MAX_N][MAX_N],hint[MAX_N][MAX_N][2];
int q, sum[MAX_N*MAX_N],length[MAX_N*MAX_N], known[MAX_N*MAX_N];
int candidates[10][46][1024];

void put(int y, int x, int val){
	for(int h = 0; h < 2; h++)
		known[hint[y][x][h] ] += (1<<val);
	value[y][x] = val;
}
void remove(int y, int x, int val){
	for(int h = 0; h < 2; h++)
		known[hint[y][x][h] ] -= (1<<val);
	value[y][x] = 0;
}
int getCandHint(int hint){
	return candidates[length[hint]][sum[hint]][known[hint]];
}
int getCandCoord(int y, int x){
	return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}
int getSize(int mask){
	int res = 0;
	while(mask != 0){
		if( (mask & 1) == 1) res++;
		mask = mask>>1;
	}
	return res;
}

int getSum(int mask){
	int res = 0;
	int pw = 1;
	while(mask != 0){
		if( (mask & 1) == 1) res += pw;
		mask = mask>>1;
		pw *= 2;
	}
	return res;
}

int getCandidate(int len, int sum, int known){
	int allSets = 0;
	for(int set = 0; set < 1024; set += 2){
		if( (set & known) == known && getSize(set) == len && getSum(set) == sum)
			allSets |= set;
	}
	return allSets & ~known;
}

void generateCnadidates(){
	memset(candidates,0,sizeof(candidates));
	for(int set = 0; set < 1024; set += 2){
		int l = getSize(set), s = getSum(set);
		int subset = set;
		while(true){
			candidates[l][s][subset] != (set & ~subset);
			if(subset == 0 ) break;
			subset = (subset - 1) & set;
		}
	}
}
void printSolution(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<value[i][j]<<" ";
		cout<<endl;
	}
	
}

bool search(){
	int y = -1, x= -1, minCands = 1023;
	for(int i =0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(board[i][j] == 1 && value[i][j] == 0){
				int cands = getCandCoord(i,j);
				if(getSize(minCands) > getSize(cands)){
					minCands = cands;
					y = i; x = j;
				}
			}
	if(minCands == 0 ) return false;
	if(y == -1){
		printSolution();
		return true;
	}
	for(int val = 0; val <= 9; val++){
		if(minCands & (1<<val)){
			put(y,x,val);
			if(search()) return true;
			remove(y,x,val);
		}
	}
	return false;
}

int main(void){
	setStd();
	
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		memset(hint,0,sizeof(hint));
		scanf("%d",&n);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				scanf("%d",&board[j][k]);
		scanf("%d",&q);
		for(int j = 0; j < q; j++){
			int y,x,dire,sum;
			scanf("%d %d %d %d",&y,&x,&dire,&sum);
			hint[y][x][dire] = sum;
		}
		generateCnadidates();
		if(!search()) cout<<"false"<<endl;
	}
}