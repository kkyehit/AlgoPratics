#include <stdio.h>
#include <queue>

using namespace std;


int main(void){
	freopen("./1966_in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		priority_queue<pair<int,int>, vector<pair<int,int> >, less<pair<int,int> > > pq;
		int N, M, in;
		scanf("%d %d",&N,&M);
		for(int i = 0 ; i< N; i++){
			scanf("%d",&in);
			pq.push(make_pair(in,i));
		}
		for(int i = 1 ; i<= N; i++){
			if(pq.top().second == M){
				printf("%d\n",i);
				break;
			} pq.pop();
		}
	}
}