#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

#define MAX_N 300

using namespace std;

const int horizon[2][2] = {{0, 1}, {0, -1}};
const int vertical[2][2] = {{1, 0}, {-1, 0}};

struct point{
	int y, x, level;
	bool isHorizon;
	point(int _y, int _x, int _level, bool _isHorizon){
		y = _y; x = _x; level = _level; isHorizon = _isHorizon;
	}
};

int x1, y1, x2, y2;

bool isRange(int y, int x){
	//printf("range %d < %d  <%d  && %d < %d <%d\n", min(y1, y2), y, max(y1,y2) + 1, min(x1, x2), x, max( x1, x2) + 1 );
	if(min(x1, x2) <= x && x <= max(x1, x2) + 1 && min(y1, y2) <= y &&  y <= max(y1,y2) + 1) return true;
	return false;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int t = 1 ; t <= T; t++){
		bool visited[MAX_N + 1][MAX_N + 1][2] = {false};
		queue<point> q;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 100;y1 += 100;x2 += 100;y2 += 100;
		q.push(point(y1, x1, 0, false));
		q.push(point(y1, x1, 0, true));
		visited[y1][x1][0] = visited[y1][x1][1] = true;
		
		int res = 0;
		while(!q.empty()){
			int y = q.front().y, x = q.front().x, level = q.front().level;
			bool isHorizon = q.front().isHorizon;
			q.pop();
			
			//printf("%d %d :%d %d %d %d\n",y2, x2, y,x,level,isHorizon);
			if(y == y2 && x == x2){
				res = level;
				break;
			}
			
			if(isHorizon){
				for(int i = 0; i < 2; i++){
					//printf("check %d %d\n",y + vertical[i][0], x + vertical[i][1]);
					if(isRange(y + vertical[i][0], x + vertical[i][1]) && !visited[y + vertical[i][0]][x + vertical[i][1]][isHorizon]){
						visited[y + vertical[i][0]][x + vertical[i][1]][isHorizon] = true;
					//	printf("push %d %d\n",y + vertical[i][0], x + vertical[i][1]);
						q.push(point(y + vertical[i][0], x + vertical[i][1], level + 1, !isHorizon));
					}
				}
			}else{
				for(int i = 0; i < 2; i++){
					//printf("check %d %d\n",y + horizon[i][0], x + horizon[i][1]);
					if(isRange(y + horizon[i][0], x + horizon[i][1]) && !visited[y + horizon[i][0]][x + horizon[i][1]][isHorizon]){
						visited[y + horizon[i][0]][x + horizon[i][1]][isHorizon] = true;
					//	printf("push %d %d\n",y + horizon[i][0], x + horizon[i][1]);
						q.push(point(y + horizon[i][0], x + horizon[i][1], level + 1, !isHorizon));
					}
				}
			}
		}
		printf("#%d %d\n",t,res);
	}
}