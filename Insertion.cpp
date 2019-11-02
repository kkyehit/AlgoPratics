#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<vector>

using namespace std;

struct tripNode{
	int value,priority,size;
	tripNode *left,*right;
	
	tripNode(int _valvue):value(_valvue),priority(rand()),size(1){
		left = right = NULL;
	}
	
	void setLeft(tripNode *_left){
		left = _left;
		calcSize();
	}
	void setRight(tripNode *_right){
		right = _right;
		calcSize();
	}
	
	void calcSize(){
		size = 1;
		if(left != NULL) size += left -> size;
		if(right != NULL) size += right -> size;
	}
	
}typedef tripNode;
tripNode* insertNode(tripNode *root, tripNode *node);
tripNode* splitNode(tripNode *root, tripNode *node);

typedef pair<tripNode *, tripNode*> NodePair;
NodePair splitNode(tripNode *root, int value){
	if(root == NULL) return NodePair(NULL,NULL);
	if(root->value < value){
		NodePair rs = splitNode(root->right,value);
		root->setRight(rs.first);
		return NodePair(root,rs.second);
	}
	NodePair ls = splitNode(root->left,value);
	root->setLeft(ls.first);
	return NodePair(ls.first,root);
}

tripNode* insertNode(tripNode *root, tripNode *node){
	if(root == NULL) return node;
	if(root -> priority < node->priority){
		NodePair splitted = splitNode(root,node->value);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}else{
		if(root->value < node->value) root->setRight(insertNode(root->right, node));
		else root->setLeft(insertNode(root->left, node));
	}
	return root;
}

tripNode* mergeNode(tripNode *left, tripNode *right){
	if(left == NULL) return right;
	if(right == NULL) return left;
	if(left->priority < right->priority){
		right->setLeft(mergeNode(left,right->left));
		return right;
	}
	left->setRight(mergeNode(left->right,right));
	return left;
}
tripNode* deleteNode(tripNode *root){
	delete root;
	root = mergeNode(root->left,root->right);
	return root;
}
tripNode* kthNode(tripNode *root,int index){
	if(root == NULL) return NULL;
	int leftSize = 0;
	if(root -> left != NULL) leftSize += root->left->size;
	if(index<= leftSize) return kthNode(root->left,index);
	if(index == leftSize + 1) return root;
	return kthNode(root->right,index - leftSize - 1);
}

void search(vector<int> &list){
	int n = list.size();
	tripNode *root = NULL;
	for(int i = 1; i <= n; i++){
		root = insertNode(root,new tripNode(i));
	}
	while(n--){
		tripNode *node = kthNode(root,n + 1 - list[n]);
		cout<<"node : "<<node->value<<endl;
		list[n] = node->value;
		deleteNode(node);
		for(int i = 0; i < list.size(); i++)
			printf("%d ",list[i]);
		printf("\n");
	}
}

int main(void){
	freopen("InsertionInput.txt","r",stdin);
	int c,n,inp;
	scanf("%d",&c);
	while(c--){
		vector<int> list;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&inp);
			list.push_back(inp);
		}
		search(list);
		for(int i = 0; i < list.size(); i++)
			printf("%d ",list[i]);
		printf("\n");
	}
}