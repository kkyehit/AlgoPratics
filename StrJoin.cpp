#include "stdConvert.h"
#define MAX_N 500
#include <algorithm>

int n;
void test(vector<int> &a){
	for(int i = 0; i < a.size(); i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int search(vector<int> &a){
	if(a.size() == 1) return 0;
	sort(a.begin(), a.end() );
	int one = a[0];
	int two = a[1];
	
	a.erase(a.begin());
	a.erase(a.begin());
	
	a.push_back(one+two);
	return one+ two + search(a);
}

int main(void){
	int c, temp;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		vector<int> a; 
		for(int j = 0; j < n; j ++){
			scanf("%d",&temp);
			a.push_back(temp);
		}
		cout<<search(a)<<endl;
	}
}