#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void test (vector<int> &a, int begin, int size){
	for(int i = begin; i < size; i++)
		cout<< a[i]<<" ";
	cout<<endl;
}

int max(int a, int b){
	if(a>b) return a;
	return b;
}	
int min(int a, int b){
	if(a<b) return a;
	return b;	
}

int search(vector<int> &a, int left, int right){
	int size = right - left;
	if(size == 0  || size == 1) {
		return a[left]; 
	}

	int half,low,high;
	int a0,a1,a2;
	half = (left+right)/2;
	low = half-1;
	high = low +1;
	
	a0 = a[low];
	a1 = a[high];
	a2 = 0;
	int temp = min(a0,a1);
	int temp2 = 0;

	a0 = max(a0,a1);
	a1 = search(a,left,half);
	a2 = search(a,half,right);
	a0 = max(a0,max(a1,a2));
	
	while((low >= left) || (high < right)){
		if((high<right)&&(temp <= a[high])) high++;
		else if((low>=left)&&(temp <= a[low])) low--;
		else {
			temp2 = temp *(high-low -1);
			if(a0<temp2) a0 = temp2;
			if(high>right) temp = a[low];	
			else if(low<left) temp = a[high];	
			else temp = max(a[high],a[low]);
		}

	}
	if(temp * size > a0) a0 = temp2;
	return a0;
}

int solve(vector<int> &h, int left, int right){
	if(left == right) return h[left];
	int mid = (left + right)/2;
	int ret = max(solve(h,left,mid),solve(h,mid+1,right));
	
	int lo = mid, hi = mid+1;
	int height = min(h[lo],h[hi]);
	ret = max(ret, height * 2);
	
	while(left < lo || hi < right){
		if(hi < right &&(lo == left || h[lo-1] < h[hi+1])){
			++hi;
			height = min(height,h[hi]);
		}else{
			--lo;
			height = min(height,h[lo]);
		}
		ret = max(ret, height * (hi-lo+1));
	}
	return ret;
}

int main(void){
	int C, N, input;
	scanf("%d",&C);
	int res[50];
	for(int i = 0; i<C; i++){
		scanf("%d",&N);	
		vector<int> v(N);
		for(int j = 0; j < N; j++){
			scanf("%d",&input);
			v[j] = input;
		}
		res[i] = solve(v,0,N);
	}
	for(int i = 0; i < C; i++){
		printf("%d\n",res[i]);
	}
}
