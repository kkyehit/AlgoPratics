#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#define ACKSTR "MAX PARTY SIZE IS "
#define DISSTR "CONTRADICTION AT "
#define MAX_N 10000


using namespace std;

struct unionFindTree{
	int group[MAX_N], enermy[MAX_N], size[MAX_N], depth[MAX_N];
	int n;
	unionFindTree(int _n){
		n = _n;
		for(int i = 0; i < n; i++){
			group[i] = i;
			size[i] = 1;
		}
		memset(enermy,-1,sizeof(enermy));
		memset(depth,0,sizeof(depth));
	}
	int unionTree(int r1, int r2){
		if(r1 == -1) return r2;
		if(r2 == -1) return r1;
		r1 = findTreeRoot(r1); r2 = findTreeRoot(r2);
		if(depth[r1] < depth[r2]) swap(r1,r2);
		size[r1] += size[r2];
		group[r2] = r1;
		if(depth[r1]==depth[r2]) depth[r1]++;
		return r1;
	}
	int findTreeRoot(int node){
		if(node == group[node]) return node;
		return findTreeRoot(group[node]);
	}
	bool ACK(int node1, int node2){
		int root1 = findTreeRoot(node1), root2 = findTreeRoot(node2);
		if(root1 == root2) return true;
		if(root1 == enermy[root2]) return false;
		int newRoot = unionTree(root1,root2);
		int newEnermy = unionTree(enermy[root1],enermy[root2]);
		enermy[newRoot] = newEnermy;
		if(newEnermy != -1) enermy[newEnermy] = newRoot;
		return true;
	}
	bool DIS(int node1, int node2){
		int root1 = findTreeRoot(node1), root2 = findTreeRoot(node2);
		if(root1 == root2) return false;
		if(root1 == enermy[root2]) return true;
		int a = unionTree(enermy[root1],root2);
		int b = unionTree(root1,enermy[root2]);
		enermy[a] = b; enermy[b] = a;
		return true;
	}
	int getMax(){
		int res = 0;
		for(int node = 0; node < n; node++){
			if(node == group[node]){
				int enermyRoot = enermy[node];
				if(node < enermyRoot) continue;
				int nodeSize = size[node];
				int enermySize = (enermyRoot == -1) ? 0 : size[enermyRoot];
				res += max(nodeSize,enermySize);
				//cout<<"node "<<node<<" enermyRoot "<<enermyRoot;
				//cout<<" nodeSize "<<size[node]<<" enermyRootSize "<<size[enermyRoot];
				//printf(" res : %d\n",res);
			}
		}
		return res;
	}
	void test(){
		for(int i = 0 ; i < n; i++)
			cout<<size[i]<<" ";
		cout<<endl;
	}
};


int main(void){
	freopen("EditerWarInput.txt","r",stdin);
	int C;
	int N,M,cnt;
	char input[3];
	int a,b;
	scanf("%d",&C);
	const int no = C;
	for(int i = 0; i < no; i++){
		scanf("%d %d",&N,&M);
		unionFindTree tree(N);
		bool isOk = true;
		int errorPos = -1;
		//tree.test();
		for(cnt = 1; cnt <= M; cnt++){
			scanf("%s %d %d",input,&a,&b);
			if(input[0] == 'A'){
				if(errorPos == -1 && !tree.ACK(a,b) ) errorPos = cnt;
			}else{
				if(errorPos == -1 && !tree.DIS(a,b)) errorPos = cnt;
			}
			//cout<<input<<" "<<a<<" "<<b<<"           "<<C<<endl;
		}
		//tree.test();
		if(errorPos != -1) cout<<DISSTR<<errorPos;
		else cout<<ACKSTR<<tree.getMax();
		printf("\n");
	}
}