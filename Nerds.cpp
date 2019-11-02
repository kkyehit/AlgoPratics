#include "stdConvert.h"
#include "vector2.h"
#include <assert.h>
#include <algorithm>
#define ok "THEORY HOLDS"
#define no "THEORY IS INVALID"

void setStd(){
	char in[] = "NerdsInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

typedef vector<vector2 > polygon;
vector<polygon> person(2);
void test(polygon p){
	for(int i = 0; i < p.size(); i++)
		cout<<" ["<<p[i].x<<","<<p[i].y<<"]"<<" ";
	cout<<endl;
}
polygon giftWrap(const vector<vector2> &points){
	int n = points.size();
	polygon hull;
	vector2 pivot = *min_element(points.begin(), points.end()); // min_element -> include<algorithm>
	hull.push_back(pivot);
	while(true){
		vector2 ph = hull.back(), next = points[0];
		for(int i = 0; i < n; i++){
			double cross = ccw(ph,next,points[i]);
			double dist = (next - ph).norm() - (points[i] - ph).norm();
			if(cross > 0 || (cross == 0 && dist < 0))
				next = points[i];
		}
		if(next == pivot) break;
		hull.push_back(next);
	}
	return hull;
}
bool polygonIntersects(const polygon &p, const polygon& q){
	int n = p.size(), m = q.size();
	if(isInside(p[0],q)||isInside(q[0],p)) return true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(segmentIntersection(p[i],p[(i+1)%n],q[j],q[(j+1)%m]))
				return true;
	return false;
}

int main(void){
	setStd();
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		person.clear();
		int n;
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			int isNerd,size,typing;
			scanf("%d %d %d",&isNerd,&size,&typing);
			person[isNerd].push_back(vector2(size,typing));
		}
		if(!polygonIntersects(giftWrap(person[0]),giftWrap(person[1])))
			cout<<ok<<endl;
		else
			cout<<no<<endl;
	}
}
