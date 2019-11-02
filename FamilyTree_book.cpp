#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX_N 100000

using namespace std;

struct RMQ{
	int n;
	vector<int> rangeRMQ;
	RMQ(vector<int> &arr){
		n = arr.size();
		rangeRMQ.resize(4 * n);
		init(arr,1,0,n-1);
	}
	int init(vector<int> &arr, int node, int left, int right){
		//cout<<"left : "<<left<<" right "<<right<<" node "<<node<<endl;
		if(left == right) return rangeRMQ[node] = arr[left];
		int mid = (left + right )/ 2;
		return rangeRMQ[node] = min(init(arr,node*2,left,mid),init(arr,node*2+1,mid+1,right));
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight){
		//cout<<"left : "<<nodeLeft<<" right "<<nodeRight<<" node "<<node<<endl;
		if(right < nodeLeft || nodeRight < left) return 99999999;
		if(left <= nodeLeft && nodeRight <= right) return rangeRMQ[node];
		int mid = ( nodeLeft + nodeRight) /2;
		return min(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid+1,nodeRight));
	}
	int query(int left, int right){
		return query(left,right,1,0,n-1);
	}
};


int n;
vector<int> child[MAX_N];
int no2serial[MAX_N], serial2no[MAX_N];
int locInTrip[MAX_N], depth[MAX_N];

int nextSerial;
void travers(int here, int d, vector<int> & trip){
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	depth[here] = d;
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	for(int i = 0 ; i < child[here].size(); i++){
		travers(child[here][i],d+1,trip);
		trip.push_back(no2serial[here]);
	}
}

RMQ* prepareRMQ(){
	nextSerial = 0;
	vector<int>trip;
	travers(0,0,trip);
	return new RMQ(trip);
}

int distance(RMQ * rmq, int u, int v){
	int lu = locInTrip[u], lv = locInTrip[v];
	if(lu > lv) swap(lu,lv);
	int lca = serial2no[rmq -> query(lu,lv)];
	return depth[u] + depth[v] - 2* depth[lca];
}
int main(void){
	freopen("FamilyTreeInput.txt","r",stdin);
	freopen("FamilyTree_bookOutput.txt","w",stdout);
	int c,N,Q, temp;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d",&N,&Q);
		N--;
		for(int i = 1 ; i <= N; i++){
			scanf("%d",&temp);
			child[temp].push_back(i);
		}
		RMQ *rmq = prepareRMQ();
		for(int i = 0; i < Q; i++){
			int a,b;
			scanf("%d %d",&a,&b);
			printf("%d\n",distance(rmq,a,b));
		}
	}
}