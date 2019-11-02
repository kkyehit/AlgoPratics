#include<iostream>
#include<vector>
#include<string>
#define MAX_N 100

using namespace std;

string condition[MAX_N + 1];
char completeStr[9];
char nominate[8] = {'A','C','F','J','M','N','R','T'};
int n;
int absPicture(int a, int b){
	int res = a - b;
	if(res < 0) return (0 - res) - 1;
	return res - 1;
}

bool checkCondition(int index){
	if(index == n){return true;}
	
	char a = condition[index].at(0);
	char b = condition[index].at(2);
	char con = condition[index].at(3);
	int amount = condition[index].at(4) -48;
	int indexA, indexB;
	for(int i = 0; i < 8; i++){
		if (completeStr[i] == a ){
			indexA = i;
			break;
		}
	}
	for(int i = 0; i < 8; i++){
		if (completeStr[i] == b ){
			indexB = i;
			break;
		}
	}
	
	bool meet;
	if((con == '=') && (absPicture(indexA,indexB) == amount) ) return checkCondition(index+1);
	else if((con == '>') && (absPicture(indexA,indexB) > amount) ){
		return checkCondition(index+1);
	}
	else if((con == '<') && (absPicture(indexA,indexB) < amount) ) {
		return checkCondition(index+1);
	} 
	return false;
}

int picture(int index, int selected){
	if(index == 8) return checkCondition(0) ? 1 : 0;
 	
	int res = 0;
	for(int i = 0; i < 8; i++){
		if( selected & (1<<i) ) continue;
		completeStr[index] = nominate[i];
		res += picture(index + 1, selected | (1<<i) );
	}
	return res;
}

int main(void){
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>condition[i];
	cout<<picture(0,0)<<endl;
}