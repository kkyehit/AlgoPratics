struct tripNode{
	int num, priority,size;
	tripNode *left,*right;
	explicit tripClass(int _num):num(_num){
		//srand((unsigned int) time(NULL));
		priority = rand();
		size = 1;
		left = right = NULL:
	}
	void calcSize(){
		size = 1;
		if(left != NULL) size += left -> size;
		if(right != NULL) size += left -> size;
	}
}typedef tripNode;
//추가, 삭제, 합치기;
tripNode *replace(tripNode *root, tripNode *node){
	if(root == NULL) return node;
	if(node->num > root->num){
		node->left = root->left;
		node->right = insertNode(root->right,root);
	}else{
		node->left = insertNode(root->left,root);
		node->right = root->right;	
	}
	return node;
}
tripNode *insertNode(tripNode *root, tripNode *node){
	if(root == NULL) return node;
	if(root->priority < node->priority){
		root = replace(root,node);
	}else{
		if(root->num < node->num)
			root->right = insertNode(root->right, node);
		else
			root->left = insertNode(root->left, node);
	}
	return root;
}
tripNode *merge(tripNode *left, tripNode *right){
	if(left == NULL) return right;
	if(right == NULL) return left;
	if(left -> priority < right -> priority){
		right -> left = merge(left, right->left);
		return right;
	}
	right -> left = merge(left, right->left);
	return right;
}
tripNode *deleteNode(tripNode *node){
	tripNode *res = merge(node -> left, node -> right);
	delete node;
	return res;
}