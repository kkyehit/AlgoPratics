#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

const int Switch[10][5] = {
		{0,1,2,-1,-1},
		{3,7,9,11,-1},
		{4,10,14,15,-1},
		{0,4,5,6,7},
		{6,7,8,10,12},
		{0,2,14,15,-1},
		{3,14,15,-1,-1},
		{4,5,7,14,15,},
		{1,2,3,4,5},
		{3,4,5,9,13}
};
int count = 0;
void test(int *clock,int index){
	for(int i=0; i< index; i++)
		cout<<clock[i]<<" ";
	cout<<endl;
}

bool checkSwitch(int *path,int num){
	int check = 0;
	for(int i = 0 ; i < 30; i++)
		if(path[i] == num) check++;
	if(check == 3) return false;
	else return true;
}
void change(int i,int *clock){
	for(int j =0; j < 5; j++){
		if(Switch[i][j] != -1){
			clock[Switch[i][j]] += 3;
		}
	}				
}
void rechange(int i,int *clock){
	for(int j =0; j < 5; j++){
		if(Switch[i][j] != -1){
			clock[Switch[i][j]] -= 3;
		}
	}
}
bool isClock12(int *clock){
	for(int i = 0; i<16; i++){
		if(clock[i] %4 !=0) return false;
	}
	return true;
}
int search(int *clock,int *path,int index,int switchNum){
	count++;
	if(isClock12(clock)) {
		test(clock,16);
		test(path,30);
		return index;
	}
	if(index >= 30) return 31;
	int res = 31, temp = 31;
	for(int i = switchNum ; i < 10; i++){
		if(checkSwitch(path,i)){
			path[index] = i;
			change(i,clock);
			temp = search(clock,path,index+1,i);
			if(temp<res)res=temp;
			rechange(i,clock);
			path[index] = -1;
		}
	}
	return res;
}

int main(void){
	int clock[16];
	int C,input;
	int res[30] = {31};
	int path[30] = {-1};
	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){	
		fill_n(path,30,-1);
		for(int j = 0 ; j<16; j++){
			scanf("%d",clock+j);
		}
		res[i] = search(clock,path,0,0);
		cout<<count<<endl;
	}	
	for(int i = 0; i < C; i++)
		cout<<res[i]<<endl;

}
