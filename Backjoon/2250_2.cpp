#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

//포인터 사용하지 않고 만들기
//hightUpdate(int _num, int _hight) -> _num번째 노드 높이는 _hight + 1
//int adjust(int _num, int _location) -> _num 번째 위치 _location, 부모는 +1

struct treeNode{ // 번호로 자식 구분
	int left, right;
	int hight, location;
}typedef treeNode;

vector<treeNode> nodes;
int n;

void confirm(){
	for(int i = 1; i <= n; i++)
		cout<<"h "<<nodes[i].hight<<" L "<<nodes[i].location<<endl;
	cout<<endl;
}

void hightUpdate(int _num, int _hight){
	if(_num == -1) return;
	nodes.at(_num).hight = _hight;
	hightUpdate(nodes.at(_num).left, _hight + 1);
	hightUpdate(nodes.at(_num).right, _hight + 1);
}

int adjust(int _num, int _location){
	if(_num == -1) return _location;
	nodes.at(_num).location = adjust(nodes.at(_num).left, _location) + 1;
	return adjust(nodes.at(_num).right, nodes.at(_num).location);
}
/*int getMin(int _num, int _cnt){
	if(_num == -1) return _cnt;
	return getMin(nodes[_num].left, _cnt + 1);
}
int getMax(int _num, int _cnt){
	if(_num == -1) return _cnt;
	return getMax(nodes[_num].right, _cnt + 1);
}*/
bool cmp(const treeNode &a,const treeNode &b){
	if(a.hight != b.hight)
		return a.hight < b.hight;
	return a.location < b.location;
}
void printRes(){
/*	int leftLevel, leftDiff = -1;
	int rightLevel, rightDiff = -1;
	
	leftLevel = getMin(1,0);
	for(int i = 1; i <= n; i++){
		if(nodes[i].hight == leftLevel)
			leftDiff = max(leftDiff, nodes[i].location);
	}
	
	rightLevel = getMax(1,0);
	for(int i = 1; i <= n; i++){
		if(nodes[i].hight == rightLevel)
			rightDiff = max(rightDiff,n - nodes[i].location + 1);
	}
//	cout<<" "<<leftLevel<<" "<<leftDiff<<" "<<rightLevel<<" "<<rightDiff<<endl;
	if(leftDiff == rightDiff) (leftLevel < rightLevel) ? printf("%d %d\n",leftLevel,leftDiff) : printf("%d %d\n",rightLevel,rightDiff);
	else if(leftLevel > rightLevel) printf("%d %d\n",leftLevel,leftDiff);
	else printf("%d %d\n",rightLevel,rightDiff);*/
	
	sort(nodes.begin() + 1, nodes.end(), cmp);
	confirm();
	
	for(int i = 0; i <= n; i++){
		
	}
}

int main(void){
	freopen("2250in.txt","r",stdin);
	scanf("%d",&n);
	int t = n;
	nodes.resize(n + 1);
	int a,b,c;
	while(t--){
		scanf("%d %d %d",&a,&b,&c);
		nodes[a].left = b;
		nodes[a].right = c;
		nodes[a].hight = nodes[a].location = 1;
	}
	hightUpdate(1,1);
	adjust(1,0);
	printRes();
}