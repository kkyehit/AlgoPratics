#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 1000

using namespace std;

int N, K;

struct medal{
	int g, s, b, num, rank;
	medal(int _g, int _s, int _b, int _n, int _r){
		g = _g; s = _s; b = _b; num = _n; rank = _r;
	}
	bool operator < (struct medal & m){
		if(g < m.g) return false;
		else if(g == m.g){
			if(s < m.s) return false;
			else if(s == m.s){
				if(b < m.b) return false;
			}
		}
		return true;
	}
	bool operator == (struct medal & m){
		if(g == m.g && s == m.s && b == m.b) return true;
		return false;
	}
};

int main(void){
	scanf("%d %d",&N, &K);
	vector<medal> v;
	int a, b, c, d;
	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d",&a, &b, &c, &d);
		v.push_back(medal(b, c, d, a, -1));
	}
	sort(v.begin(), v.end());
	
	int v_size = v.size();
	for(int i = 0; i < v_size; i++){
		if(i == 0) v[i].rank = 1;
		else{
			if(v[i-1] == v[i]) v[i].rank = v[i -1].rank;
			else v[i].rank = i + 1;
		}
	}
	
	/*for(int i = 0; i < v_size; i++){
		printf("gold %d, silver %d, bronse %d, rank %d, num %d\n",v[i].g,v[i].s,v[i].b,v[i].rank,v[i].num);
	}*/
	for(int i = 0; i < v_size; i++){
		if(v[i].num == K){
			printf("%d\n",v[i].rank);
			break;
		}
	}
	
}