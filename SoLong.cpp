#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>

#define MAX_N 10000
#define MAX_M 20000
#define MAX_L 11

using namespace std;

struct trieNode{
	char expectWord[MAX_L + 1];
	int maxCnt;
	vector< trieNode* > child;
	vector< char > childChar;
	trieNode(){
		maxCnt = 0;
		expectWord[0] = '\0';
	}
	trieNode* add(char _str[],int _cnt, int _it){
		if(expectWord[0] == '\0' || maxCnt < _cnt || 
			(maxCnt == _cnt && strcmp(_str,expectWord) < 0) ){
			maxCnt = _cnt;
			strcpy(expectWord,_str);
		}
		
		if(_str[_it] == '\0') return NULL;
		for(int i = 0 ; i < child.size(); i++){
			if(childChar[i] == _str[_it])
				return child[i] -> add(_str,_cnt,_it +1);
		}
		child.push_back(new trieNode());
		childChar.push_back(_str[_it]);
		return child[child.size()-1]->add(_str,_cnt,_it+1);
	}
	int query(char _str[], int _it, int _n){
		if(_it == _n) return 0;//입력 끝
		//cout<<" _str : "<<_str<<" _it "<<_it<<" _n "<<_n<<" expectWord "<<expectWord<<endl;
		if(strcmp(_str,expectWord)==0) return 1; //tab 누르기
		
		for(int i = 0 ; i < child.size(); i++) // 찾아서 누르기
			if(childChar[i] == _str[_it])
				return child[i] -> query(_str,_it +1,_n) + 1;
		return (_n - _it); // 해당 키가 등록되지 않은 경우
	}
	int query(char _str[]){
		int n = 0;
		while(_str[n] != '\0') n++;
		for(int i = 0 ; i < child.size(); i++) // 찾아서 누르기
			if(childChar[i] == _str[0])
				return child[i] -> query(_str,1,n) + 1;
		return n;
	}
	
}typedef trieNode;
void test(trieNode *root){
	cout<<root->expectWord<<endl;
	if(root->child.size() > 0 )test(root->child[0]);
}
int main(){
	freopen("SoLongInput.txt","r",stdin);
	int c,n,m,inCnt;
	char input[MAX_L + 1];
	scanf("%d",&c);
	const int cnt = c;
	for(int i = 0 ; i < cnt; i++){
		scanf("%d %d",&n,&m);
		const int N = n, M = m;
		trieNode root;
		for(int j = 0; j < N; j++){
			scanf("%s %d",input,&inCnt);
			root.add(input, inCnt, 0);
		}
		//test(&root);
		int res = M - 1;
		for(int j = 0; j < M; j++){		
			scanf("%s",input);
			int  temp = root.query(input);
			//cout<<" input : "<<input<<" add : "<<temp<<endl;
			res+= temp;
		}
		printf("%d\n",res);
	}
}