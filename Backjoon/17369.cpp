#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point{
	int y, x;
	char c;
	point(int _x, int _y, char _c){
		y = _y; x = _x; c = _c;
	}
}

const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<point> v;
int n, m, k, q;

int stringToInt(string &str){
	int res = 0;
	for(int i = 0; i < str.size(); i++)
		res = res * 10 + (str[i] - '0');
	return res;
}

int main(void){
	scanf("%d %d %d %d",&n, &m, &k, &q);
	
	int y, x;
	char c;
	
	for(int i = 0;i < k; i++){
		scanf("%d %d %c",&x, &y, &c);
		v.push_back(point(x, y, c));
	}
	
	for(int i = 0; i < q; i++){
		string str;
		cin>>str;
		int y, x, dis;
		if( str[0] == 'U' ){
			y = 0; x = stringToInt(str.substr(1, str.size() - 1)); dis = 0;
		}else if( str[0] == 'D' ){
			y = n - 1; x = stringToInt(str.substr(1, str.size() - 1)); dis = 2;
		}else if( str[0] == 'L' ){
			y = stringToInt(str.substr(1, str.size() - 1)); x = 0; dis = 1;
		}else if( str[0] == 'U' ){
			y = stringToInt(str.substr(1, str.size() - 1)); x =  m - 1; dis = 3;
		}
	}
}