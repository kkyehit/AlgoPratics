#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

#define MAX_L 30
#define MAX_R 30
#define MAX_C 30

using namespace std;

const int d[6][3] ={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

struct point{
	int x,y,z;
	point(){
		
	}
	point(int _x, int _y, int _z){
		x =_x; y = _y; z = _z;
	}
	void setPoint(int _x, int _y, int _z){
		x =_x; y = _y; z = _z;
	}
	bool operator ==(point &p) const{
		if(x == p.x && y == p.y && z == p.z) return true;
		return false;
	}
	void print_point(){
		printf("z : [%d] y : [%d] x : [%d]\n",z,y,x);
	}
};

struct point start_p, end_p;
int L, R, C;
char build[MAX_L][MAX_R][MAX_C];
bool cache[MAX_L][MAX_R][MAX_C];

bool canMove(point p, int i){
	if(p.z + d[i][0] < 0 || L <= p.z + d[i][0] )  return false;
	if(p.y + d[i][1] < 0 || R <= p.y + d[i][1] )  return false;
	if(p.x + d[i][2] < 0 || C <= p.x + d[i][2] )  return false;
	if(build[p.z + d[i][0]][p.y + d[i][1]][p.x + d[i][2]] == '#') return false;
	return true;
}

int search(){
	memset(cache,false,sizeof(cache));
	queue<pair<point, int> > q;
	q.push(make_pair(start_p,0));
	
	while(!q.empty()){
		point p = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(p == end_p) return cnt;
		
		if(cache[p.z][p.y][p.x]) continue;
		cache[p.z][p.y][p.x] = true;
		
		for(int i = 0; i < 6; i++)
			if(canMove(p,i)){
				q.push(make_pair(point(p.x + d[i][2],p.y + d[i][1],p.z + d[i][0]),cnt + 1));
			}
	}
	return -1;
}

int main(void){
	freopen("./6593_in","r",stdin);
	
	while(1){
		memset(build,0,sizeof(build));
		scanf("%d %d %d",&L, &R, &C);
		
		if(!L && !R && !C) break;
	
		for(int z = 0; z < L; z++){
			for(int y = 0; y < R; y++){
				for(int x = 0; x < C; x++){
					scanf("%c",&build[z][y][x]);
					if(build[z][y][x] == '\n') x--;
					else if(build[z][y][x] == 'S') start_p.setPoint(x,y,z);
					else if(build[z][y][x] == 'E') end_p.setPoint(x,y,z);
				}
			}
		}
		int res = search();
		if(res != -1) printf("Escaped in %d minute(s).\n",res);
		else printf("Trapped!\n");
	}
}