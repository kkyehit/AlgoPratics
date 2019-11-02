#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int init(vector<int> &tree, vector<int> &list, int node, int start, int end){
	if(start == end) return tree[node] = (list[start] < 0 )? -1 : (list[start] == 0) ? 0 : 1;
	return tree[node] = init(tree, list, node * 2, start , (start + end)/2) * init(tree, list, node * 2 + 1, (start +end)/2 + 1, end);
}

int update(vector<int> &tree, int node, int start, int end, int lo, int val){
	if(lo < start || end < lo) return tree[node];
	if(start == end) return tree[node] = val;
	return tree[node] = update(tree, node * 2, start, (start +end) / 2, lo, val) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, lo, val);
}

int getValue(vector<int> &tree, int node, int start, int end, int left, int right){
	if(end < left || right < start) return 1;
	if(left <= start && end <= right) return tree[node];
	return getValue(tree, node * 2, start, (start + end) / 2, left, right) * getValue(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right); 
}

int main(void){
	int N, K;
	char opt;
	int v1, v2;
	while(scanf("%d %d",&N, &K) != -1){
		vector<int>list(N, 0);
		vector<int>tree(N * 4, 0);
		vector<char> res;
		
		for(int i = 0 ;i < N; i++)scanf("%d",&list[i]);
		init(tree, list, 1, 0, N -1);
		
		while(K--){
			scanf("%c",&opt);
			if(opt == 'C'){
				scanf("%d %d",&v1, &v2);
				list[v1 - 1] = v2;
				update(tree, 1, 0, N -1, v1 - 1, (v2 < 0) ? -1 : (v2 == 0) ? 0 : 1);
		
			}
			else if(opt == 'P'){
				scanf("%d %d",&v1, &v2);
				int resVal = getValue(tree, 1, 0, N -1, v1 - 1, v2 - 1);
				if(resVal == 0) res.push_back('0');
				else if(resVal < 0) res.push_back('-');
				else if(resVal > 0) res.push_back('+');
			}else K++;
		}
		
		int resSize = res.size();
		for(int i = 0; i < resSize; i++) printf("%c",res[i]);
		printf("\n");
	}
}