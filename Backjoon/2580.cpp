#include <stdio.h>
#define LINE 9
using namespace std;

int board[LINE][LINE];

int print_board(){
	for(int i = 0; i < LINE; i++){
		for(int j = 0; j < LINE; j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	return 1;
}

int search(int y, int x){
	if(x >= LINE) return search(y + 1, 0);
	if(y >= LINE) return print_board();
	if(board[y][x] != 0) return search(y,x + 1);
	
	bool list[LINE + 1] = {false};
	
	for(int i = 0; i < LINE; i++)
		list[board[y][i]] = true;
	
	for(int i = 0; i < LINE; i++)
		list[board[i][x]] = true;
	
	for(int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++)
		for(int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++)
			list[board[i][j]] = true;
	
			
	//printf("y ; %d x : %d \n",y,x);
	//print_board();
	//for(int i = 1; i <= LINE; i++){
	//	if(!list[i]) printf("%d ",i);
	//}
	//printf("\n");
	
	for(int i = 1; i <= LINE; i++)
		if(!list[i]){
			board[y][x] = i;
			
			if(search(y, x + 1) == 1) return 1;
			board[y][x] = 0;
		}
	return 0;
}

int main(void){
	freopen("./2580_in","r",stdin);
	for(int i = 0; i < LINE; i++)
		for(int j = 0; j < LINE; j++)
			scanf("%d",&board[i][j]);
	search(0,0);
}