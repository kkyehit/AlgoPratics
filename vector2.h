#include <math.h>
const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;
const double INFTY = 1e200;
struct vector2{
	double x,y;
	explicit vector2(double x_ = 0, double y_ = 0) : x(x_),y(y_){}
	//두 벡터의 비교
	bool operator == (const vector2 &rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2 &rhs) const{
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	//벡터의 덧셈과 뺄셈
	vector2 operator +(const vector2 &rhs) const{
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator -(const vector2 &rhs) const{
		return vector2(x - rhs.x, y - rhs.y);
	}
	//실수 곱셈
	vector2 operator *(double rhs) const{
		return vector2(x * rhs, y * rhs);
	}
	//벡터의 길이 반환
	double norm() const {return hypot(x,y);}
	//방향이 같은 단위벡터 반환, 영벡터에 대해 호출한 경우 반환값은 정의되지 않는다.
	vector2 normalize() const{
		return vector2(x/norm(), y/norm());
	}
	//x축의 양의 방향으로 부터 이 벡터까지 반시계 방향으로 잰 각도
	double polar() const {return fmod(atan2(y,x) + 2*PI,2* PI);}
	//외적 , 내적
	double dot(const vector2& rhs) const{
		return x* rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const{
		return x*rhs.y - rhs.x*y;
	}
	//rhs 에 사영
	vector2 project(const vector2& rhs) const{
		vector2 r= rhs.normalize();
		return r * r.dot(*this);
	}
};

double ccw(vector2 a, vector2 b){// 원점에서 b가 a의 반시계 방향이면 양수, 평행이면 0, 시계 방향이면 음수반환
	return a.cross(b);
}

double ccw(vector2 p,vector2 a, vector2 b){//p를 기준으로 에서 b가 a의 반시계 방향이면 양수, 평행이면 0, 시계 방향이면 음수반환
	return ccw(a-p,b-p);
}
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &x){
	double det = (b - a).cross(d - c);
	if(fabs(det) < EPSILON) return false;
	x = a + (b - a) *( (c - a).cross(d - c) / det);
	return true;
}
bool parallelSegment(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p){//평행한 선분일때 한 점에서 곂치는지 확인
	if(b < a) swap(a,b);
	if(d < c) swap(c,d);
	if(ccw(a,b,c) != 0 || b < c || d < a) return false; // 한 직선 위에 없거나 겹치치 않는 경우 return false;
	if(a < c) p = c;//교차점 하나 찾기
	else p = a;
	return true;
}
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b){//a,b,p 가 일직선 상에 있다는 가정 하에 (a,b) 를 감싸며 각 변이 x,y축에 평핸한 최소 사각현 내부에 p가 있는지 확인
	if(b<a) swap(a,b);
	return p==a || p==b|| (a<p&&p<b);
}
bool segmentInterseation(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p){
	if(!lineIntersection(a,b,c,d,p))//두 직선이 평행한 경우
		return parallelSegment(a,b,c,d,p);
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);//p가 두 선분에 포함되어 있는 경우에만 참을 반환
}
bool segmentIntersection(vector2 a, vector2 b, vector2 c,vector2 d){
	double ab = ccw(a,b,c) * ccw(a,b,d);
	double cd = ccw(c,d,a) * ccw(c,d,b);
	if(ab == 0 && cd == 0){
		if(b < a) swap(a, b);
		if(d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}
bool isInside(vector2 q, const vector<vector2> &p){
	int crosses = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i + 1) % p.size();
		if((p[i].y > q.y) != (p[j].y > q.y)){
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if(q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}

double area(const vector<vector2> &p){
	double ret = 0;
	for(int i = 0; i < p.size(); i++){
		int j = (i + 1 ) % p.size();
		ret += p[i].x * p[j].y -p[j].x * p[i].y;
	}
	return fabs(ret) /2.0;
}