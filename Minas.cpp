#include "stdConvert.h"
#define MAX_N 100
#include <sstream>
#include <algorithm>
#include <math.h>

int min(int a,int b){
	if(a < b) return a;
	return b;
}int max(int a,int b){
	if(a > b) return a;
	return b;
}
void setStd(){
	char in[] = "MinasInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int n;
double y[MAX_N],x[MAX_N],r[MAX_N]; 
//동적 계획법으로 풀어보자
int cache[MAX_N + 1][MAX_N + 1];
bool calc(int pre, int now){
	double dis = sqrt(pow(x[pre] - x[now],2) + pow(y[pre] - y[now],2));
	if(dis >= r[pre] + r[now])
		return true;
	return false;
}

int search(int pre, int now){
	int ret = cache[pre+1][now+1];
	if(ret != -1) return ret;
	
	ret = 1000;
	vector<double> vX;
	vector<double> vY;
	vector<double> vR;
	for(int i = 0; i < n; i++){
		if(pre == -1 || (r[i] != -1 && calc(now,i))){
			ret = min(ret,1+search(now,i));
			if(pre != -1){
				vR.push_back(r[i]);
				r[i] = -1;
			}
		}
	}// 문제점 : 양쪽을 교려해야 되고,, 다둘러 싸였는지 여부가 불확실, 많이 복잡하다
}
//가장 멀리 떨어진것 x

//책에서는 각도를 이용 atan()2 <- P=(y,x) 룰 입력맏아 x 축의 양의 방향과 선분 OP 사이의 각도를 반환[-ㅠ,ㅠ] 
//asin() <- 두 변의 길이가 8이고 반지름이 r 일때 이등분한 각도 세타 = sain(r/2 * 1/8)
// loc = atan2(y,x) / range = 2 * asin(r/16) <- 감시역역이 합이 [0,2ㅠ]를 덮는지 확인 함으로써 전체 덮는지 확인 가능
const double pi = 2.0 *acos(0);
pair<double,double> ranges[MAX_N];
void convertToRange(){
	for(int i = 0; i < n; ++i){
		double loc = fmod(2*pi + atan2(y[i],x[i]), 2*pi);
		double range = 2.0 *asin(r[i] / 2.0 / 8.0);
		ranges[i] = make_pair(loc - range, loc + range);
	}
	sort(ranges, ranges + n);
}
//선형 문제로 변환해서 풀기
const int INF = 987665431;
int solveLinear(double begin, double end){
	int used = 0, idx = 0;
	while(begin < end){
		double maxCover = -1;
		while(idx < n && ranges[idx].first <= begin){
			maxCover = max(maxCover, ranges[idx].second);
			++idx;
		}
		if(maxCover <= begin) return INF;
		begin = maxCover;
		++used;
	}
	return used;
}
int solveCircular(){
	int ret = INF;
	sort(ranges, ranges + n);
	for(int i =0; i < n; ++i){
		if(ranges[i].first <= 0 || ranges[i].second >= 2*pi){
			double begin = fmod(ranges[i].second, 2*pi);
			double end = fmod(ranges[i].first + 2*pi,2*pi);
			ret = min(ret, 1+ solveLinear(begin,end));
		}
	}
	return ret;
}
int main(void){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%lf %lf %lf",&x[j],&y[j],&r[j]);
		}
		//책 다시보기,
	}
}