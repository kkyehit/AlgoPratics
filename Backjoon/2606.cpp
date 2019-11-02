#include <stdio.h>
#include <vector>
#include <queue>
#define MAX_N 100

using namespace std;

int main(void){
	bool infect[MAX_N + 1] = {false};
	vector<int> net[MAX_N + 1];
	queue<int> q;
	int n, m;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d",&a,&b);
		net[a].push_back(b);
		net[b].push_back(a);
	}
	
	int res = 0;
	infect[1] = true;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		int net_n = net[x].size();
		for(int i = 0; i < net_n; i++){
			if(!infect[net[x][i]]){
				infect[net[x][i]] = true;
				q.push(net[x][i]);
				res++;
			}
		}
	}
	printf("%d\n",res);
}