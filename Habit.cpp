#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 4000

using namespace std;

struct Comperater{
	vector<int> &group;
	int t;
	Comperater(vector<int> &_group, int _t) : group(_group), t(_t){
		group = _group; t = _t;
	}
	bool operator()(int a, int b){
		if(group[a] != group[b] ) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

vector<int> getSuffixArray(const string &s){
	int n = s.size();
	int t = 1;
	
	vector<int> group(n + 1);
	for(int i = 0; i < n; i++) group[i] = s.at(i);
	group[n] = -1;
	
	vector<int> perm(n);
	for(int i = 0; i < n; i++) perm[i] = i;
	
	while(t < n){
		Comperater comperateUining2T(group,t);
		sort(perm.begin(), perm.end(), comperateUining2T);
		
		t *= 2;
		if(t >= n) break;
		
		vector<int> newGroup(n + 1);
		newGroup[perm[0]] = 0;
		newGroup[n] = -1;
		for(int i = 1; i < n; i++){
			if(comperateUining2T(perm[i-1],perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
	}
	return perm;
}

int commonPrefix(const string &s, int i, int j){
	int k = 0, n = s.size();
	while(i < n && j < n && s.at(i) == s.at(j)){
		i++;j++;k++;
	}
	return k;
}

int countSubstring(const string &s){
	int n = s.size(), ret = 0;
	vector<int> a = getSuffixArray(s);
	for(int i = 0; i < n; i++){
		int cp = 0;
		if(i > 0) cp = commonPrefix(s,a[i - 1], a[i]);
		ret += n -a[i] -cp;
	}
	return ret;
}

string str;
int k;

int countSubStringMaxLength(){
	int n = str.size(), ret = 0;
	vector<int> a = getSuffixArray(str);
	for(int i = 0; i + k< n; i++)
		ret = max(ret, commonPrefix(str,a[i],a[i + k - 1]));
	return ret;
}
int main(void){
	freopen("HabitInput.txt","r",stdin);
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&k);
		cin>>str;
		cout<<countSubStringMaxLength()<<endl;
	}
}