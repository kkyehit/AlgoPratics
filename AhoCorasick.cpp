//Aho-Corasick search algorithmn, (KMP using trie),
// 긴 문서에서 많은 문자열을 동시에 찾아야 할때 사용
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

#define MAX_N 10000
#define MAX_LENGTH 1000
#define ALPHABET 26

using namespace std;
char numToString[MAX_N][MAX_LENGTH];//문자열과 번호 매칭하기,

struct TrieNode{
	int terminal; //현 위치에서 끝나는 문자번호
	TrieNode * fail; //실패 연결 노드 ( 이 노드에서 매칭이 실패햇을때 이동할 노드, 점미사면서 trie에 포함된 최대 문자열 )
	vector<int> output; //출력 문자열 목록,
	vector< TrieNode* > children; 
};

//trie의 각 노드에 대해 fail과 output 계산하기
void computeFailFunc(TrieNode* root){
	queue< TrieNode* > q; // 너비 우선 탐색을 위한 큐,
	root -> fail = root; // 루트의 실패함수는 루트.
	q.push(root);
	while(!q.empty()){
		TrieNode* here = q.front();
		q.pop();
		for(int edge = 0; edge < ALPHABET; edge++){
			TrieNode* child = here->children[edge];
			if(!child) continue; // 자식이 없으면 스킵,
			if(here == root) child->fail = root;// root의 실패함수는 자기자신
			else{//실패함수 찾기
				TrieNode* t = here->fail;// 부모의 실패 연결을 따라가면서 실패 연결 찾기
				while( t != root && t->children[edge] == NULL) // root에 도달하거나, children[edge] 가 존재할떄까지 반복
					t = t->fail;
				if(t->children[edge]) t = t->children[edge];
				child -> fail = t;
			}
			//출력 문자열 목록,
			child->output = child->fail->output;
			if(child->terminal != -1) child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

vector<pair<int,int> > ahoCorasick(const string &s, TrieNode* root){
	vector<pair<int,int> > ret;
	TrieNode* state = root;
	for(int i = 0; i < s.size(); i++){
		int chr = s[i];
		while(state != root && state->children[chr] == NULL)
			state = state->fail;
		if(state->children[chr])
			state = state->children[chr];
		for(int j = 0; j <state->output.size();j++)
			ret.push_back(make_pair(i,state->output[j]));
	}
	return ret;
}