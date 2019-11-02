#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++) scanf("%d",&v[i]);
	
	vector<int> res;
	for(int i = 0; i < n; i++){
		int pos = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
		if(res.size() <= pos) res.push_back(v[i]);
		else res[pos] = v[i];
	}
	printf("%d\n",(int)res.size());
}