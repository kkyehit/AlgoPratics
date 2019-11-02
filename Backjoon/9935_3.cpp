#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){
	freopen("./9935_in","r",stdin);
	string s1,s2;
	cin>>s1;
	cin>>s2;
	
	stack<pair<char, int> > s; // first : sentence, second : matched;
	int n = s1.size(), m = s2.size();
	
	int matched;
		   
	for(int i = 0; i < n; i++){
		matched = (!s.empty())? s.top().second : 0;
		s.push(make_pair(s1[i],(s1[i] == s2[matched])? matched + 1 : ((s1[i] == s2[0])? 1 : 0)));
		if( s.top().second == m)
			for(int j = 0; j < m; j++)
				s.pop();
	}
	
	n = s.size();
	if(n > 0){
		vector<char> v;
		while(!s.empty()){
			v.push_back(s.top().first);
			s.pop();
		}
		for(int i = v.size() - 1; i >= 0; i--)
			printf("%c",v[i]);
		printf("\n");
	}
	else printf("FRULA\n");
}