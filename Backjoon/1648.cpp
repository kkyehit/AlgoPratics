#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX_N 14

using namespace std; 

int n,m;
/*
bool isOk(bool *board){
	for(int i = 0; i < m * n; i++){
		if(board[i] == false) return false;
	}
	return true;
}
int search(bool *board,int index){
	if(isOk(board)) return 1;
	if(index >= n*m) return 0;
	
	if(board[index]) return search(board,index + 1);
	
	int ret = 0;
	board[index] = true;
	//1
	if((((index + 1) % m) != 0) && (!board[index + 1])){
		board[index + 1] = true;
		ret += search(board, index + 1) %9901;
		board[index + 1] = false;
	}
	//2
	if(((index + m) < n*m) &&(!board[index + m])) {
		board[index + m] = true;
		ret += search(board, index + 1) %9901; 
		board[index + m] = false;
	}
	board[index] = false;
	return ret;
}
*/
int cache[1<<14][MAX_N];
vector<int> list;

int cnt(int a){
	int line = a;
	for(int i = 0; i < m - 1 ; i++)
		if(!(line & (1<<i)))
			if(!(line & (1<<(i+1)))){
				line |= (1<<i);
				line |= (1<<++i);
			}
	return 	((((1<<m)-1) - line) == 0)?	1 : 0;
}

int search2( int line, int index){
	if(index == n - 1) return cnt(line);
	
	int &ret = cache[line][index];
	if(ret != -1) return ret;
	
	int res = 0;
	for(int i = 0 ; i < list.size(); i++){
		if(!(line & list[i])) 
			res = (res + search2(((1<<m) -1)^(line | list[i]),index + 1)) % 9901;
	}
	
	return ret = res;
}
void initList(){
	list.push_back(0);
	for(int i = 0; i < m - 1 ; i++){
		int next = (1<<i) | (1<<(i + 1));
		list.push_back(next);
	}
	for(int i = 1; i < list.size() - 1 ; i++){
		for(int j = i + 1; j < list.size() ; j++){
			if(!(list[i] & list[j]))
				list.push_back(list[i] | list[j]);
		}
	}
	
	for(int i = 1; i < list.size() ; i++){
		sort(list.begin(),list.end());
		list.erase(unique(list.begin(),list.end()),list.end());
		//printf("list %d\n",list[i]);
	}
}

int main(void){
	scanf("%d %d",&n,&m);
	memset(cache,-1,sizeof(cache));
	initList();
	printf("%d\n",search2(0,0));
	/*bool board[n*m];
	memset(board,0,sizeof(board));
	printf("답 :%d\n",search(board,0));*/
}