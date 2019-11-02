#include "stdConvert.h"
#include "vector2.h"
#include <assert.h>
#define MAX_N 20

void setStd(){
	char in[] = "TresureInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

typedef vector<vector2> polygon;
void test(polygon p){
	for(int i = 0; i < p.size(); i++)
		cout<<" ["<<p[i].x<<","<<p[i].y<<"]"<<" ";
	cout<<endl;
}
polygon cutPoly(const polygon &p, const vector2& a, vector2& b){
	int n = p.size();
	vector<bool> inside(n);
	for(int i = 0; i < n; i++)
		inside[i] = ccw(a,b,p[i]) >= 0;
	polygon ret;
	for(int i = 0; i < n; i++){
		int j = (i + 1) % n;
		if(inside[i]) ret.push_back(p[i]);//포함되는 점 결과 다각형에 포함
		if(inside[i] != inside[j]){ // 한점은 포함되고 한점은 포함이 안된다 -> 교차한다.
			vector2 cross;
			assert(lineIntersection(p[i],p[j],a,b,cross));
			ret.push_back(cross);
		}
	}
	return ret;
}

polygon intersection(const polygon &p, double x1, double y1, double x2, double y2){
	vector2 a(x1,y1) , b(x2, y1) , c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p,a,b);
	ret = cutPoly(ret, b,c);
	ret = cutPoly(ret, c,d);
	ret = cutPoly(ret, d,a);
	return ret;
}

int main(void){
	setStd();
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		polygon poly;
		int x1,y1,x2,y2,N;
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&N);
		for(int j = 0; j < N; j++){
			int pointX,pointY;
			scanf("%d %d",&pointX,&pointY);
			poly.push_back(vector2 (pointX,pointY) );
		}
		printf("%0.10lf\n",area( intersection(poly,x1,y1,x2,y2) ));
	}
}