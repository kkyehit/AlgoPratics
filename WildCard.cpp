#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<string.h>

using namespace std;

void test1(char *pattern){
	int i=0;
	while(pattern[i] != '\0'){
		printf("%c",pattern[i++]);
	}
	printf("\n");
}
bool check(string a){
	for(int i = 0; i<a.size(); i++)
		if(a.at(i) != '*') return false;
	return true;
}
bool search(string p, string s,int index){
	while(((p.size() > index ) && (s.size() > index)) && ((p.at(index) == s.at(index)) || (p.at(index) == '?') )){
		index++;
	}
	if(p.size() <= index){
		if(s.size() <= index) return true;
	}
	 if (p[index] == '*')
               for (int skip = 0; index + skip <= s.size(); skip++)
                       if (search(p.substr(index + 1), s.substr(index + skip),0))
                            return true;
	return false;
}
//book
int cache[101][101];
string W, S;
bool mathMemoized(int w, int s){
	int& ret = cache[w][s];
	if(ret != -1) return ret;
	
	while((s < S.size() && w < W.size()) && 
		  (W[w] == '?' || W[w] == S[s])){
		return ret = mathMemoized(w+1,s+1);
	}
	if(w == W.size()) return ret = (s == S.size());
	if(W[w] == '*')
		if(mathMemoized(w+1,s) || 
		   (s<S.size() && mathMemoized(w,s+1)))
			return ret = 1;
	return ret = 0;
}
void initCache(){
	for(int i =0; i < 101; i++){
		for(int j = 0; j< 101; j++){
			cache[i][j] = -1;
		}
	}
}
int main(void){
	int C,n;
	char temp;
	string pattern;
	string *str;
	
	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
	vector<string> res;
		cin>>pattern;
		scanf("%d",&n);
		str = new string[n];
		for(int j=0; j < n; j++){
			cin>>str[i];
			if(search(pattern, str[i],0)) {
				res.push_back(str[i]);
			}
		}
		
	sort(res.begin(), res.end());
	for(int j =0; j < res.size(); j++)cout<<res[j]<<endl;
	cout<<endl;
	}
/*
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		cin>>W;
		scanf("%d",&n);
		for(int j=0; j < n; j++){
			initCache();
			cin>>S;
			if(mathMemoized(0,0)) {
				res.push_back(S);
			}
		}
	}
*/
	
}

