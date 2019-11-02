#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int n, m;
int main(void){
	freopen("./2623_in","r",stdin);
	scanf("%d %d",&n,&m);
	
	vector<int> v[MAX_N + 1];
	int cnt[MAX_N + 1] = {0};
	
/*	int a = -1, b, tmp = 0;
	char c;
	scanf("%c",&c);
	for(int i = 0 ; i < m; i++){
		a = -1;
		while(true){
			if(scanf("%c",&c)==-1) c= -1;
			if(c == -1 || c == ' '||c == '\n'){
					printf("%d ",tmp);
				if(a == -1) a = b = tmp;
				else{
					a = b;
					b = tmp;	
					if(a != b){
						v[a].push_back(b);
						cnt[b]++;	
					}
				}
				tmp = 0;
				if(c == -1 || c == '\n') break;
			}else{
				tmp *= 10;
				tmp += c - '0';	
			}
		}	
		printf("\n");
	}
*/
	for(int i = 0; i < m ; i++){
		int k, a, b;
		scanf("%d",&k);
		if(k <= 0) continue;
		scanf("%d",&a);
		for(int j = 1; j < k; j++){
			scanf("%d",&b);
			v[a].push_back(b);
			cnt[b]++;
			a = b;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		 if(cnt[i] == 0)
			q.push(i);
		vector<int> res;
		while(!q.empty()){
			int p = q.front();
			int pn = v[p].size();
			q.pop();
			res.push_back(p);
			for(int i = 0; i < pn; i++)
				if(--cnt[v[p][i]] == 0)
					q.push(v[p][i]);
		}
		if(res.size() != n) printf("0\n");
		else
			for(int i = 0; i < n; i++)
				printf("%d\n",res[i]);
}
