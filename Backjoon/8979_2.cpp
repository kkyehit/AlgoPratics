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
	int k_g,k_s,k_b;
	for(int i = 0; i < N; i++){
		scanf("%d %d %d %d",&a, &b, &c, &d);
		v.push_back(medal(b, c, d, a, -1));
		if(a == K){
			k_g = b; k_s = c; k_b = d;
		}
		
	}
	int rank = 1;
	int v_size = v.size();
	for(int i = 0; i < v_size; i++){
		if(v[i].g > k_g) rank++;
		else if(v[i].g == k_g){
			if(v[i].s > k_s) rank++;
			else if(v[i].s == k_s)
				if(v[i].b > k_b) rank++;
		}
	}
	printf("%d\n",rank);
}