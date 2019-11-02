#include "stdConvert.h"
#define MAX_N 5
#include <sstream>
#include <algorithm>

int max(int a, int b){
	if( a > b) return a;
	return b;
}
int min( int a, int b){
	if(a < b) return a;
	return b;
}
void setStd(){
	char in[] = "BlockGameInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int C;
int Board;
char input,cache[1<<25];
vector<int> block;


const char *byte_to_binary(int x)
{
    static char b[31];
    b[0] = '\0';

    int z;
	int i;
    for (z = (1<<24), i = 0 ;  z > 0;  z >>= 1, i++)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
		if(i %5 == 4) strcat(b, "\n");
    }
    return b;
}
void makeBlock(){
	int addBlock[4];
	for(int i = 0; i < MAX_N-1 ; i++){
		for(int j = 0; j < MAX_N-1 ; j++){
			addBlock[0] = 1<<( i * 5 + j );
			addBlock[1] = 1<<( i * 5 + j + 1 );
			addBlock[2] = 1<<( (i + 1) * 5 + j );
			addBlock[3] = 1<<( (i + 1) * 5 + j + 1 );
			for(int k = 0; k < 4; k++)
				block.push_back(addBlock[0]+addBlock[1]+addBlock[2]+addBlock[3]-addBlock[k]);
		}
	}
	for(int i = 0; i < MAX_N ; i++){
		for(int j = 0; j < MAX_N-1 ; j++){
			addBlock[0] = 1<<(i * 5 + j);
			addBlock[1] = 1<<(i * 5 + j + 1);
			block.push_back(addBlock[0]+addBlock[1]);
		}
	}
	for(int i = 0; i < MAX_N-1 ; i++){
		for(int j = 0; j < MAX_N ; j++){
			addBlock[0] = 1<<(i * 5 + j);
			addBlock[1] = 1<<((i + 1) * 5 + j);
			block.push_back(addBlock[0]+addBlock[1]);
		}
	}
}
bool isContinue(){
	for(int i = 0; i < MAX_N ; i++){
		for(int j = 0; j < MAX_N ; j++){
			if((Board & ( 1<<(24 - i*5 + j) ) ) == ( 1<<(24 - i*5 + j) ) )
				if((j < 4)  && (Board & ( 1<<(24 - i*5 + j + 1) ) ) == ( 1<<(24 - i*5 + j + 1) ) )
					return true;
				if((i < 4)  && (Board & ( 1<<(24 - (i+1)*5 + j) ) ) == ( 1<<(24 - (i+1)*5 + j) ) )
					return true;
		}
	}
	return false;
}
/*책의 내용
int blockGame(int b){

	char &ret = cache[b];
	if(ret != 0 ) return ret;
	
	
	int res = 2;
	for(int i = 0; i < block.size(); i++ ){
		if( (Board & block[i]) ) continue;
		Board += block[i];
		res = min( res, blockGame() );
		Board -= block[i];
		if(res == -1) return ret = 1;
	}
	if(res == 2) return ret = -1;
	return ret = 0 - res;
	
	ret = -1;
	for(int i = 0; i < block.size(); i++ ){
		if( (b & block[i])  == 0){
			if(blockGame(b | block[i] ) == -1)
				return ret = 1;
		} 
	}
	return ret;
}*/
int blockGame(){

	char &ret = cache[Board];
	if(ret != 0 ) return ret;
	
	int res = 2;
	for(int i = 0; i < block.size(); i++ ){
		if( (Board & block[i]) ) continue;
		Board += block[i];
		res = min( res, blockGame() );
		Board -= block[i];
		if(res == -1) return ret = 1;
	}
	if(res == 2) return ret = -1;
	return ret = 0 - res;
	
}
int main(void){
	setStd();
	scanf("%d",&C);
	makeBlock();
	memset(cache,0,sizeof(char) * (1<<25) );
	for(int i = 0; i < C; i++){
		Board = 0;
		for(int k = 0; k < MAX_N; k++){
			for(int j = 0; j < MAX_N; j++){
				scanf("%c",&input);
				if(input == '#') Board = Board | (1 << ((k * 5 + j)) );
				else if(input == '.') Board += 0; 
				else j--;
			}
		}
		int canWin = blockGame();
		if(canWin == 1) cout<<"WINNING"<<endl;
		if(canWin == -1) cout<<"LOSING"<<endl;
	}
}