#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 500

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	
	vector<pair<int, int> > v;
	int a, b;
	for(int i = 0; i < n; i++){
		scanf("%d %d",&a, &b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());
	
	vector<int> res;
	res.push_back(v[0].second);
	for(int i = 1 ; i < n; i++){
		int pos = lower_bound(res.begin(), res.end(), v[i].second) - res.begin();
	
		if(pos >= res.size()) res.push_back(v[i].second);
		else res[pos] = v[i].second;
	}
	printf("%d\n", (n - (int)res.size()) );
}