#include<stdio.h>
#include<iostream>

using namespace std;

struct treeNode{
	char name;
	treeNode *left, *right;
	treeNode(char _name){
		name = _name;
		left = right = NULL;
	}
}typedef treeNode;

struct treeChain{
	treeNode *root;
	void addChildAt(char name, char leftname, char rightname);
	treeNode * getNodeOf(char name,treeNode* node);
	
	void preorder(treeNode *node);
	void inorder(treeNode *node);
	void postorder(treeNode *node);
}typedef treeChain;

void treeChain::addChildAt(char name, char leftname, char rightname){
	treeNode *node = getNodeOf(name, root);
	if(node == NULL) {
		printf("error\n");
		return;
	}
	if(leftname != '.') node -> left = new treeNode(leftname);
	if(rightname != '.') node -> right = new treeNode(rightname);
}
treeNode* treeChain::getNodeOf(char name, treeNode* node){
	if(node == NULL) return NULL;
	if(node -> name == name) return node;
	
	//cout<<" node name "<<node->name<<" name "<<name<<endl;
	
	treeNode *res = getNodeOf(name, node->right);
	if(res != NULL) return res;
	return getNodeOf(name, node->left);
}


void treeChain::preorder(treeNode *node){
	if(node == NULL) return;
	printf("%c",node->name);
	preorder(node->left);
	preorder(node->right);
}
void treeChain::inorder(treeNode *node){
	if(node == NULL) return;
	inorder(node->left);
	printf("%c",node->name);
	inorder(node->right);
}
void treeChain::postorder(treeNode *node){
	if(node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	printf("%c",node->name);
}

int main(void){
	int t;
	scanf("%d",&t);
	treeChain chain;
	chain.root = new treeNode('A');
	char A,B,C,tmp;
	while(t--){
		scanf("%c %c %c %c",&tmp,&A,&B,&C);
		//cout<<" A : "<<A<<" B : "<<B<<" C : "<<C<<endl;
		chain.addChildAt(A,B,C);
	}
	chain.preorder(chain.root);
	printf("\n");
	chain.inorder(chain.root);
	printf("\n");
	chain.postorder(chain.root);
	printf("\n");
}