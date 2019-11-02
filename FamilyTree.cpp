#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#define MAX_N 100000
#define INVALID -9876543

using namespace std;

int N, Q;
int arr[MAX_N],pPath[MAX_N];

int searchRoot(int a){
	//cout<<a<<endl;
	if(a == -1) return 0;
	if(pPath[a] != -1) return pPath[a];
	return pPath[a] = (searchRoot(arr[a]) + 1);
}
void makepPath(){
	memset(pPath,-1,sizeof(pPath));
	for(int i = 0; i < N; i++)
		searchRoot(i);
}
struct RMQ{//구간의 공통 루트 구하기 / 오류 : 구간으로 LCA 찾는게 오류, 한쪽 구간의 LCA가 전체 구간의 LCA를 찾는데 도움이 되지 않음,
	vector<int> rangeRMQ;
	RMQ(){
		rangeRMQ.resize(N * 4);
		init(0,N-1,1);
	}
	int getLCA(int a, int b){
		if(a == INVALID) return b;
		if(b == INVALID) return a;
		if(a == -1 || b == -1) return -1;
		if(a == b ) return a;
		int tempB = b,tempA = a;
		while(tempB != -1){
			if(tempA == tempB) return tempB;
			tempB = arr[tempB];
		}
		return getLCA(arr[a],b);
	}
	int init(int left, int right, int node){
		if(left == right) return rangeRMQ[node] = left;
		int mid = (left + right) / 2;
		//return rangeRMQ[node] = getLCA(init(left,mid,node*2),init(mid+1,right,node*2+1));
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		if(nodeRight < left || right < nodeLeft) return INVALID;
		if(left <= nodeLeft && nodeRight <= right) return rangeRMQ[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return getLCA(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid + 1,nodeRight));
	}
	int query(int left, int right){
		if(left == -1 || right == -1) return -1;
		return query(left,right,1,0,N-1);
	}
}typedef RMQ;

void test(int c,int n, int q){
	cout<<c<<endl<<n<<" "<<q<<endl;
	for(int i = 0; i < N; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int getDistance(int a, int b,int LCA){
	if(a == -1) return pPath[b];
	if(b == -1) return pPath[a];
	if(LCA == -1) return pPath[a] + pPath[b];
	return pPath[a] + pPath[b] - 2*pPath[LCA];
}

int main(void){
	freopen("FamilyTreeInput.txt","r",stdin);
	freopen("FamilyTreeOutput.txt","w",stdout);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d",&N,&Q);
		N--;
		for(int i = 0 ; i < N; i++){
			scanf("%d",arr + i);
			arr[i]--;
		}
		makepPath();
		RMQ rmq;
		for(int i = 0; i < Q; i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(b<a) swap(a,b);
			int LCA = rmq.query(--a,--b);
			cout<<"a : "<<a+1<<" b "<<b+1<<" LCA : "<<LCA<<endl;
			printf("%d\n",getDistance(a,b,LCA));
		}
	}
}
	