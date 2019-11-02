#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#define MAX_N 100
using namespace std;

struct circleInfo{
	int x, y, r;
	explicit circleInfo(int _x,int _y,int _r):x(_x),y(_y),r(_r){};
}typedef circleInfo;
struct treeNode{
	vector<treeNode*> children;
}typedef treeNode;

double getDistance(circleInfo &c1, circleInfo &c2){
	return sqrt( (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y) );
}

bool isSuburb(vector<circleInfo> &circleSet, circleInfo &circle){
	int n = circleSet.size();
	for(int i = 0; i < n; i++)
		if(getDistance(circleSet[i],circle) + circle.r < circleSet[i].r) return false;
	return true;
}
bool isInclude(circleInfo &c1, circleInfo &c2){ // c2가 c1에 포함 되는가
	if(getDistance(c1,c2) + c2.r < c1.r) return true;
	return false;
}/*
void makeTree(treeNode *root, vector<circleInfo> &circleSet){
	int n = circleSet.size();
	for(int i = 0; i < n; i++){
		vector<circleSet> temp(circleSet.begin(),circleSet.end());
		temp.erase(temp.begin() + i);
		if(isSuburb(temp.circleSet[i])){
			
		}
	}
}*///외곽을 구하고 그에 포함 되는 집합 찾으려 했는데 시간이 오래 걸릴 거 같아서 포기.
treeNode* getTree(vector<circleInfo> &circleSet, circleInfo &circle){
	treeNode *root = new treeNode;
	
	int n = circleSet.size();
	vector<circleInfo> newSet;
	for(int i = 0; i < n; i++)
		if(isInclude(circle,circleSet[i])) newSet.push_back(circleSet[i]);
	
	int m = newSet.size();
	for(int i = 0; i < m; i++)
		if(isSuburb(newSet,newSet[i])) root -> children.push_back(getTree(newSet,newSet[i]));
	//cout<<" n : "<<n<<" m :"<<m<<endl;
	return root;
}
int longest;
int getLongestLenght(treeNode * root){
	if(root -> children.empty()) return 0;
	
	int n = root -> children.size();
	vector<int> depthList(n,0);
	for(int i = 0; i < n; i++)
		depthList[i] = getLongestLenght(root->children[i]) + 1;
	sort(depthList.begin(), depthList.end());
	longest = max(longest,(n > 1)? depthList[n - 1] + depthList[n - 2] : depthList[n - 1]);
	return depthList[n - 1];
}

void searchAndPrint(vector<circleInfo> &circleSet){
	treeNode * root = getTree(circleSet,circleSet[0]);
	longest = 0;
	int res = max(getLongestLenght(root),longest);
	cout<<res<<endl;
}

void test(vector<circleInfo> &circleSet){
	int n = circleSet.size();
	for(int i = 0; i < n; i++)
		cout<<circleSet[i].x<<" "<<circleSet[i].y<<" "<<circleSet[i].r<<endl;
}



int main(void){
	freopen("FortressInput.txt","r",stdin);
	int c,N;
	scanf("%d",&c);
	while(c--){
		vector<circleInfo> circleSet;
		int x,y,r;
		scanf("%d",&N);
		for(int i = 0;i<N;i++){
			scanf("%d %d %d",&x,&y,&r);
			circleSet.push_back(circleInfo(x,y,r));
		}
		searchAndPrint(circleSet);
		//test(circleSet);
	}
}
