
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};
void test(vector< vector<char> > &metrix){
	for(int i = 0; i < metrix.size(); i++){
		for(int j = 0; j < metrix[i].size(); j++)
			cout<<metrix[i][j];
		cout<<endl;
	}
}
void wordprint(vector<char> &word){
	for(int j = 0; j < word.size(); j++)
		cout<<word[j];
	cout<<" ";
}
bool search(int y, int x, vector<char> &word, int index, vector< vector<char> > &metrix){
	if(word.size() == index) return true;
	if(y<0 || y>=metrix.size() || x<0 || x>=metrix[y].size()) return false;
	bool explore = false;
	if(metrix[y][x] == word[index]){
		for(int i = 0; i < 8; i++){
			explore = search(y+dy[i],x+dx[i],word,index+1,metrix);
			if(explore) break;
		}
	}
	return explore;
}


int main(void){
	vector< vector<char> > metrix(5,vector<char>(5));
    	vector< vector<char> > word(10);
	
	int C,N;
	char input;
	bool result;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				scanf("%c",&input);
				if(input!='\n')
					metrix[j][k] = input;
				else
					k--;
			}
			
		}
		scanf("%d",&N);
		getchar();
		for(int j = 0; j < N; j ++){
			char wordinput;
			while(true){
				scanf("%c",&wordinput);
				if(wordinput == '\n') break;
				word[j].push_back(wordinput);
			}
		}
		for(int l = 0; l < N; l++){
			for(int j = 0; j < 5; j++){
				for(int k = 0; k < 5; k++){
					result = search(j,k,word[l],0,metrix);
					if(result) break;
				}
				if(result) break;
			}
			wordprint(word[l]);
			if(result) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}

