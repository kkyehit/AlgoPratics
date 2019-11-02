#include "stdConvert.h"
#define MAX_N 100

using namespace std;

void setStd(){
	char in[] = "FossilInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}
struct point{
	double y,x;
}typedef point;

vector<point> hull1,hull2;
vector<pair<point,point> > upper, lower;

void decompose(const vector<point>& hull){
	int n = hull.size();
	for(int i = 0; i < n; i++){
		if(hull[i].x < hull[(i+1)%n].x)
			lower.push_back(make_pair(hull[i],hull[(i+1)%n]));
		else if(hull[i].x > hull[(i+1)%n].x)
			upper.push_back(make_pair(hull[i],hull[(i+1)%n]));
	}
}
bool between(const point &a, const point &b, double x){
	return(a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point &a, const point &b, double x){
	double dy = b.y - a.y, dx = b.x - a.x;
	return a.y + dy*(x - a.y) / dx;
}

double vertical(double x){
	double minUp = 1e20, maxLow = -1e20;
	for(int i = 0; i < upper.size(); i++)
		if(between(upper[i].first, upper[i].second, x))
			minUp = min(minUp,at(upper[i].first, upper[i].second,x));
	for(int i = 0; i < lower.size(); i++)
		if(between(lower[i].first, lower[i].second, x))
			maxLow= min(maxLow,at(lower[i].first, lower[i].second,x));
	return minUp - maxLow;
}
double solve(){
	double lo = max(minX)
}

int n,m;
vector<pair<double,double> > A,B;
int main(void){
	int t;
	double x,y;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d %d",&n,&m);
		A.clear();
		B.clear();
		for(int j = 0; j < n; j++){
			scanf("%lf %lf",&x,&y);
			A.push_back(make_pair(x,y));
		}
		for(int j = 0; j < m; j++){
			scanf("%lf %lf",&x,&y);
			B.push_back(make_pair(x,y));
		}
	}
}