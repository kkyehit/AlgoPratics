#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 500001
#define INF 2123456789

using namespace std;

struct Score{
	int x[3];
};
bool cmp(Score s1, Score s2){
	if(s1.x[0] < s2.x[0]) return true;
	 return false;
}

int update(vector<int> &tree, int node, int start, int end, int pos, int val){
	if(pos < start || end < pos) return tree[node];
	if(start == end) return tree[node] = val;
	return tree[node] = min(update(tree, node * 2, start , (start + end) / 2, pos, val), update(tree, node * 2 + 1, (start + end) / 2 + 1, end, pos, val));
}
int getValue(vector<int> &tree, int node, int start, int end, int left, int right){
	if(end < left || right < start ) return INF;
	if(left <= start && end <= right) return tree[node];
	return min(getValue(tree, node * 2, start, (start + end) / 2, left, right), getValue(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int n;
Score score[MAX_N];

int main(void){
	scanf("%d",&n);
	int tmp;
	for(int j = 0; j < 3; j++){
		for(int i = 1; i <= n; i++){
			scanf("%d",&tmp);
			(score[tmp].x[j]) = i;
		}
	}
	sort(score + 1, score + n + 1, cmp);
	vector<int> tree (MAX_N * 4, INF);
	
	/*for(int j = 0; j < 3; j++){
		for(int i = 1; i <= n; i++){
			printf("%2d ",(score[i].x[j]));
		}
		printf("\n");
	}*/
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		//printf("x[1] %d, x[2] %d, getValue() %d\n",score[i].x[1],score[i].x[2],getValue(tree, 1, 0, n, 0, score[i].x[1]));
		if(getValue(tree, 1, 0, n, 0, score[i].x[1]) > score[i].x[2]) res++;
		update(tree, 1, 0, n, score[i].x[1], score[i].x[2]);
	}
	printf("%d\n",res);
}