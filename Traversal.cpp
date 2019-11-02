#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_N 100

using namespace std;

int N;
int preorder[MAX_N], inorder[MAX_N];

struct treenode{
	int num;
	treenode *left, *right;
} typedef treenode;

treenode* getTreeNode(int &n,int left, int right){
	if(n == N) return NULL;
	if(left == right) return NULL;
	
	treenode *res = new treenode;
	res -> num = preorder[n++];
	
	int index = left;
	for( ; index < right; index++)
		if(preorder[n - 1] == inorder[index])
			break;
	
	res -> left = getTreeNode(n,left,index);
	res -> right = getTreeNode(n,index + 1,right);
	
	return res;
}

void searchAndPrint(treenode *root){
	if(root == NULL) return;
	searchAndPrint(root -> left);
	searchAndPrint(root -> right);
	cout<<root->num<<" ";
}

void makeTreeAndSearch(){
	int n = 0;
	treenode *root = getTreeNode(n,0,N);
	searchAndPrint(root);
	cout<<endl;
}


vector<int> slice(const vector<int> & v, int a, int b){
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int> &PreOrder, const vector<int>& InOrder){
	const int N = PreOrder.size();
	if(PreOrder.empty()) return;
	
	const int root = PreOrder[0];
	const int L = find(InOrder.begin(), InOrder.end(),root) - InOrder.begin();
	const int R = N - 1 - L;
	
	printPostOrder(slice(PreOrder, 1, L + 1), slice(InOrder, 0, L));
	printPostOrder(slice(PreOrder, L + 1, N), slice(InOrder, L + 1, N));
	
	cout<< root <<' ';
}
int main(void){
	freopen("TraversalInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	int input;
	while(c--){
		vector<int> PreOrder,InOrder;
		scanf("%d",&N);
		for(int i = 0; i < N; i++){
			scanf("%d",&input);
			PreOrder.push_back(input);
		}for(int i = 0; i < N; i++){
			scanf("%d",&input);
			InOrder.push_back(input);
		}
		printPostOrder(PreOrder,InOrder);
		cout<<endl;
	}
}
/*
int main(void){
	freopen("TraversalInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&N);
		for(int i = 0; i < N; i++)
			scanf("%d",preorder + i);
		for(int i = 0; i < N; i++)
			scanf("%d",inorder + i);
		makeTreeAndSearch();
	}
}*/

