#include<math.h>
#include "stdConvert.h"
const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;
const double INFTY = 1e200;

void setStd(){
	char in[] = "PinballInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

struct vector2{
	double x,y;
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_),y(y_){}
	bool operator == (const vector2 &rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	bool operator < ( const vector2 &rhs) const{
		return (x != rhs.x) ? x < rhs.x : y < rhs.y;
	}
	
	vector2 operator + (const vector2 &rhs) const{
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2 &rhs) const{
		return vector2(x - rhs.x, y - rhs.y);
	}
	vector2 operator * (double rhs) const{
		return vector2(x * rhs , y * rhs);
	}
	
	double norm() const{
		return hypot(x,y);
	}
	vector2 normalize() const{
		return vector2(x/norm(),y/norm());
	}
	
	double polar() const{
		return fmod(atan2(y,x) + 2*PI, 2*PI);
	}
	
	double dot(const vector2 &rhs) const{
		return rhs.x*x + rhs.y*y;
	}
	double cross(const vector2 &rhs) const{
		return rhs.y*x - rhs.x*y;
	}
	vector2 project(const vector2 & rhs) const{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};
double ccw(vector2 &a, vector2 &b ){
	return a.cross(b);
}double ccw(vector2 &p,vector2 &a, vector2 &b ){
	return (a-p).cross(b-p);
}

vector<pair<vector2,int> > circle;
vector2 now, dirction;
int N;

vector<double> solve2(double a, double b, double c){
	double d = b*b - 4*a*c;
	if(d < -EPSILON) return vector<double>(); // 해가 없는 경우
	if(d < EPSILON) return vector<double>(1, -b / (2*a) ); // 중근인 경우
	vector<double> ret;
	ret.push_back((-b - sqrt(d)) / (2*a));
	ret.push_back((-b + sqrt(d)) / (2*a));
	return ret;
}

/*
	f(t) = p + td; - > t는 시간, p는 현제위치, d는 방향 벡터
	중심이 c 이고 반지름이 r인 원과 교차하는 시간 - > | c - f(t) | = r , 제곱하면 (c - f(t))^2 = r^2;
	위 식을 풀어서 t 에대해 정리하면 -> d*d*t^2 + 2(p-c)*d*t +c*c + p*p - 2*c*p -r^2 = 0;
*/
double hitCircle(vector2 here, vector2 dir, vector2 center, int radius){
	double a = dir.dot(dir); // |d|^2
	double b = 2 * dir.dot(here - center); //2*|p-c|*|d|;
	double c = center.dot(center) + here.dot(here) - 2*here.dot(center) - radius*radius;//c*c + p*p - 2*c*p -r^2
	
	vector<double> sols = solve2(a,b,c);
	if(sols.empty() || sols[0] <EPSILON ) return INFTY;
	return sols[0];
}

vector2 reflect(vector2 dir, vector2 center, vector2 contact){
	return (dir - dir.project(contact - center) * 2).normalize();
}

void simulate(vector2 here, vector2 dir){
	dir = dir.normalize();
	int hitCount = 0;
	while(hitCount < 10){
		int circleNum = -1;
		double time = INFTY * 0.5;
		for(int i = 0; i < N; i++){
			double cand = hitCircle(here,dir, circle[i].first, circle[i].second);
			if(cand < time){
				time = cand;
				circleNum = i;
			}
		}
		if(circleNum == -1) break;
		if(hitCount++) cout<<" ";
		cout<<circleNum;
		vector2 contact = here + dir * time;
		dir = reflect(dir,circle[circleNum].first,contact);
		here = contact;
	}
	cout<<endl;
}

int main(void){
	setStd();
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%lf %lf %lf %lf %d",&now.x,&now.y,&dirction.x,&dirction.y,&N);
		circle.clear();
		for(int j = 0; j < N; j++){
			double x,y,r;
			scanf("%lf %lf %lf",&x,&y,&r);
			circle.push_back(make_pair(vector2(x,y),r + 1));
		}
		simulate(now,dirction);
	}
}