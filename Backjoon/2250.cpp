#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<vector>
#include<time.h>

using namespace std; 

//search()
// 제일 왼족 노드와 같은 level의 오른쪽 노드, 없으면 1.
// 제일 오른쪽 노드와 같은 level의 왼쪽 노드, 없으면 1.
// max값 return 

//add()
// treenode* nodes[N + 1] 배열에 num에 해당되는 node 저장
// node의 자식에 추가.

//adjust()
// 가장 왼쪽 노드 location은 1
// 왼쪽 노드 개수 + 1 == root의 location
// 오른쪽의 가장 왼쪽 노드 == root + 1
// 맨 오른쪽 노드의 location == 부모 + 1;

struct treeNode{
	int location;
	treeNode *left, *right;
	treeNode(){
		location = 1;
		left = right = NULL;
	}
}typedef treeNode;

struct inputTable{
	int b, c;
}typedef inputTable;

struct nodeChain{
	int n;
	treeNode *root;
	inputTable *nodes;
	nodeChain(int _n);
	void makeTable(int _a,int _b, int _c);
	//void add(int name, int _left, int _right);
	void add(treeNode *node, int _a);
	int adjust(treeNode *node, int rootLo);
	void search();
	int maxRight(int _level, treeNode *node, int now);
	int maxLeft(int _level, treeNode *node, int now);
}typedef nodeChain;

nodeChain::nodeChain(int _n){
	n = _n;
	root = new treeNode();
	nodes = (inputTable *) malloc(sizeof(inputTable)*(n+1));
}
void nodeChain::makeTable(int _a,int _b, int _c){
	nodes[_a].b = _b;
	nodes[_a].c = _c;
}
/*void nodeChain::add(int name, int _left, int _right){
	//cout<<"name "<<name<<" left "<<_left<<" right "<<_right<<endl;
	
	//cout<<" got "<<name<<endl;
	if(parent == NULL){
		printf("error add()\n");
		return;
	}
	if(_left != -1){
	}
	if(_right != -1){
	}
}*/
void nodeChain::add(treeNode *node, int _a){
	if(node == NULL) return;
	if(nodes[_a].b != -1){
		node -> left = new treeNode();
		add(node -> left, nodes[_a].b);
	}
	if(nodes[_a].c != -1){
		node -> right = new treeNode();
		add(node -> right, nodes[_a].c);
	}
}

int nodeChain::adjust(treeNode *node, int rootLo){
	if(node == NULL) return rootLo;
	node->location = adjust(node->left, rootLo ) + 1;
	return adjust(node->right, node->location);
}
void nodeChain::search(){
	int leftLevel, leftDiff, level;
	
	treeNode *tmp = root;
	level = 1;
	while(tmp -> left != NULL){
		tmp = tmp -> left;
		level++;
	}
	leftLevel = level;
	//cout<<" level "<<level<<endl;
	leftDiff = maxRight(leftLevel,root,1) - tmp -> location + 1; 
	//cout<<" leftLevel "<<leftLevel<<" leftDiff "<<leftDiff<<endl;
	
	int rightLevel, rightDiff;
	
	tmp = root;
	level = 1;
	while(tmp -> right != NULL){
		tmp = tmp -> right;
		level++;
	}
	rightLevel = level;
	rightDiff = tmp -> location - maxLeft(rightLevel,root,1) + 1; 
	
	if (leftDiff == rightDiff) (leftLevel < rightLevel)? printf("%d %d\n",leftLevel, leftDiff) : printf("%d %d\n",rightLevel, rightDiff);
	else if(leftDiff < rightDiff) printf("%d %d\n",rightLevel, rightDiff);
	else printf("%d %d\n",leftLevel, leftDiff);
}
int nodeChain::maxRight(int _level, treeNode *node, int now){
	if(node == NULL) return -1;
	//if(node -> level == _level) return node -> location;
	if(now == _level) return node -> location;
	
	int res = maxRight(_level, node->right, now + 1);
	if(res != -1) return res;
	return maxRight(_level, node -> left, now + 1);
}

int nodeChain::maxLeft(int _level, treeNode *node, int now){
	if(node == NULL) return -1;
	//if(node -> level == _level) return node -> location;
	if(now == _level) return node -> location;
	
	int res = maxLeft(_level, node->left,now + 1);
	if(res != -1) return res;
	return maxLeft(_level, node -> right, now + 1);
}

int main(void){
	freopen("2250in.txt","r",stdin);
	srand( (unsigned) time(NULL));
	
	int n, A,B,C;
	scanf("%d",&n);
	
	nodeChain *chain = new nodeChain(n);
	while(n--){
		scanf("%d %d %d",&A,&B,&C);
		chain -> makeTable(A,B,C);
	}
	chain -> add(chain -> root, 1);
	chain -> adjust(chain -> root, 0);
	//cout<<"adjust() successed "<<endl;
	//chain -> inorder(chain->root);
	//printf("\n");
	chain -> search();
}
