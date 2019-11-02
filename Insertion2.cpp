#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>

using namespace std;


struct treapNode{
	int num,priority,size;
	treapNode *left, *right;
	treapNode(int _num):num(_num),priority(rand()),left(NULL),right(NULL),size(1){};
	void calSize(){
		size = 1;
		if(left != NULL) size += left->size;
		if(right != NULL) size += right->size;
	}
	void setRight(treapNode * _right){ right = _right; calSize(); }
	void setleft(treapNode * _left){ left = _left; calSize(); }
}typedef treapNode;


void test(treapNode *root,int height){
	if(root == NULL) return;
	cout<<" level : "<<height<<" value : "<<root->num<<endl;
	test(root->left,height + 1);
	test(root->right,height + 1);
}

typedef pair<treapNode *,treapNode *> treapPair;
treapPair split(treapNode* root, int key){
	if(root == NULL) return treapPair(NULL,NULL);
	if(root->num < key){
		treapPair rs = split(root->right, key);
		root->setRight(rs.first);
		//cout<<root -> num<<" < "<<key<<endl; 
		//cout<<rs.first->num<<" : "<<key<<" : "<<rs.second<<endl;
		//int l = (rs.second == NULL) ? -1 : rs.second->num ;
		//cout<<" root : "<<root->num<<" rs.second : "<< l<<endl;
		return treapPair(root,rs.second);
	}
	treapPair ls = split(root->left, key);
	root->setleft(ls.second);
	return treapPair(ls.first,root);
}
treapNode *insertTreap(treapNode *root, treapNode *node){
	
	if(root == NULL) return node;
	//cout<<"insert "<<node->num<<" at "<<root->num<<endl;
	
	if(root->priority < node-> priority){
	//	cout<<" root ("<<root->num<<") 에 node ("<<node->num<<") 추가"<<endl;
		treapPair splited= split(root,node -> num);
		/*int l = (pairOfChildren.second == NULL) ? -1 : pairOfChildren.second->num ;
		int a = (pairOfChildren.first == NULL) ? -1 : pairOfChildren.first->num ;
		cout<<" left Children : "<<a<<" right children : "<<l<<endl;*/
		
		node->setleft(splited.first);
		node->setRight(splited.second);
		//test(node,0);
		//cout<<endl;
		return node;
	}
	if(root->num < node->num)
		root->setRight(insertTreap(root->right,node));
	else
		root->setleft(insertTreap(root->left,node));
	return root;
} 
treapNode *mergeTreap(treapNode* left, treapNode* right){
	if(left == NULL) return right;
	if(right == NULL) return left;
	if(left -> priority < right->priority){
		right->setleft(mergeTreap(left,right->left));
		return right;
	}
	left->setRight(mergeTreap(left->right,right));
	return left;
}
treapNode *deleteTreap(treapNode *root,int key){
	if(root == NULL) return root;
	if(root -> num == key){
		treapNode* res = mergeTreap(root->left, root->right);
		delete root;
		return res;
	}
	if(root -> num < key)
		root->setRight(deleteTreap(root->right, key));
	else
		root->setleft(deleteTreap(root->left, key));
	return root;
}
treapNode *kthNode(treapNode *root, int k){
	//cout<<endl<<" num : "<<root->num<<" k: "<<k<<endl;
	if(root == NULL) return NULL;
	int leftSize = 0;
	if(root->left != NULL)
		leftSize = root->left->size;
	if(k == leftSize )
		return root;
	else if(k <= leftSize )
		return kthNode(root->left,k);
	else
		return kthNode(root->right, k - leftSize - 1);
}
treapNode *kthNodeReverse(treapNode *root, int k){
	//cout<<endl<<" num : "<<root->num<<" k: "<<k<<endl;
	if(root == NULL) return NULL;
	int rightSize = (root->right == NULL )?0:root->right->size;
	if(k == rightSize )
		return root;
	else if(k > rightSize )
		return kthNodeReverse(root->left,k - rightSize - 1);
	else
		return kthNodeReverse(root->right, k);
}

int countLessThan(treapNode *root, int key){
	if(root == NULL) return 0;
	int leftSize = (root->left == NULL)? 0: root->left->size;
	if(root -> num >= key) 
		return countLessThan(root->left,key);
	return leftSize + 1 + countLessThan(root->right,key);
}

#define MAX_N 50000
int value[MAX_N],n;

int main(void){
	srand( (unsigned)time(NULL));
	freopen("InsertionInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		treapNode *root = NULL;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",value + i);
			//cout<<i+1<<" 추가 "<<endl;
			root = insertTreap(root,new treapNode(i + 1));
			//test(root,0);
			//printf("%d ",value[i]);
		}
		//printf("\n");
		//test(root,0);
		for(int i = n - 1; i >= 0 ; i--){
			treapNode* temp = kthNodeReverse(root,value[i]);
			//cout<<endl<<"tree"<<endl;
			//test(root,0);
			value[i] = temp->num;
			//cout<<value[i]<<endl;
			root = deleteTreap(root,temp->num );
		}
		for(int i = 0; i < n; i++)
			printf("%d ",value[i]);
		printf("\n");
	}
}
