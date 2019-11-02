#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 100000
#define MAX_Q 10000

using namespace std;

struct pathInfo{
	int minh,maxh;
}typedef pathInfo;
struct RMQ{
	int n;
	vector<pathInfo> rangeRMQ;
	pathInfo inVaildPath;
	RMQ(const vector<int> &array){
		n = array.size();
		rangeRMQ.resize(n * 4);
		inVaildPath.minh = 20001;
		inVaildPath.maxh = -1;
		init(array,1,0,n-1);
	}
	pathInfo getInfoUsingTwo(pathInfo left, pathInfo right){
		pathInfo res;
		res.minh = min(left.minh , right.minh);
		res.maxh = max( right.maxh ,left.maxh);
		return res;
	}
	pathInfo init(const vector<int> &array,int node,int left, int right){
		if(left == right){
			rangeRMQ[node].minh = rangeRMQ[node].maxh = array[left];
			return rangeRMQ[node];
		}
		int mid = (left + right) / 2;
		return rangeRMQ[node] = getInfoUsingTwo(init(array,node*2,left,mid), init(array,node*2 + 1, mid + 1, right));
	}
	pathInfo query(int left, int right, int node, int nodeLeft, int nodeRight){
		if(right < nodeLeft || nodeRight < left) return inVaildPath;
		if(left <= nodeLeft && nodeRight <= right) return rangeRMQ[node];
		int mid = ( nodeLeft + nodeRight ) / 2;
		return getInfoUsingTwo(query(left,right,node*2,nodeLeft,mid), query(left,right,node*2 + 1,mid + 1,nodeRight));
	}
	pathInfo query(int left,int right){
		return query(left,right,1,0,n-1);
	}
	pathInfo update(int index, int newValue, int node, int nodeLeft, int nodeRight){
		if(index < nodeLeft || index > nodeRight) return rangeRMQ[node];
		if(nodeLeft == nodeRight) {	
			rangeRMQ[node].minh = rangeRMQ[node].maxh = index;
			return rangeRMQ[node];
		}
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeRMQ[node] = getInfoUsingTwo(
			update(index,newValue,node*2,nodeLeft,mid),
			update(index,newValue,node*2+1,mid + 1, nodeRight)
		);
	}
	pathInfo update(int index, int newValue){
		return update(index,newValue,1,0,n-1);
	}
}typedef RMQ;

int main(void){
	freopen("MordorInput.txt","r",stdin);
	int c;
	int inp1,inp2,N,Q;
	scanf("%d",&c);
	pathInfo ret;
	while(c--){
		vector<int> h;
		scanf("%d %d",&N,&Q);
		for(int i = 0; i < N; i++){
			scanf("%d",&inp1);
			h.push_back(inp1);
		}
		RMQ rmq(h);
		for(int i = 0; i < Q; i++){
			scanf("%d %d",&inp1,&inp2);
			ret = rmq.query(inp1,inp2);
			printf("%d\n",ret.maxh - ret.minh);
		}
		/*for(int i = 0; i < Q; i++){
			scanf("%d %d",&inp1,&inp2);
			vector<int>::iterator it = min_element(h.begin() + inp1,h.begin() + inp2 + 1);
			int minh = *it;
			it = max_element(h.begin() + inp1,h.begin() + inp2 + 1);
			int maxh = *it;
			printf("%d\n",maxh - minh);
		}*/
	}
	
}