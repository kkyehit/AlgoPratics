#include "stdConvert.h"
#define MAX_N 100
#define MAX_M 200

using namespace std;

void setStd(){
	char in[] = "DarpaInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int n,m;
float list[MAX_M];

//원점에서 제일 먼 점 - > 제일 가까운점 순으로 탐색,
//n개를 선택 할 수 있는 방법이 있으면 return,
//거리 기준,


//다시 생각ㅈ하자,

bool isOk(double minDistance){
	int count = 1, index = 0;
	for(int i = 0; i < m; i++){
		//cout<<minDistance<<" "<<list[i]-list[index]<<" "<<i<<" "<<index<<endl;
		if(list[i]-list[index] >= minDistance){
			index = i;
			count++;
		}
	}
	if(count >= n) return true;
	return false;
}

bool decision(double gap){
	double limit = -1;
	int installed = 0;
	for(int i = 0; i < m; i++){
		if(limit <= list[i]){
			++installed;
			limit = list[i] + gap;
		}
	}
	return installed >= n;
}

float search(){
	float lo = 0, hi = 240;
	for(int i = 0; i<100; i++){
		float mid = (lo + hi) / 2;
		if(decision(mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

float dif[MAX_M][MAX_M],cache[MAX_M][MAX_M];
void pre(){
	for(int i = 0; i < m; i++)
		for(int j = i; j < m; j++)
			dif[i][j] = list[j] - list[i];
	memset(cache,-1,sizeof(cache));
}
float dynamic(int index,int select){// 선택의 최소가 최대가 되도록,
	if(select >= n) return 240;
	
	float &ret = cache[index][select];
	if(ret > -1 )return ret;
	
	float res = 0;
	float minDes = -1;
	for(int i = index+1; i < m; i++){
		minDes = min(dif[index][i], dynamic(i,select + 1));
		res = max(res,minDes);
	}
	return ret = res;
}

int main(void){
	setStd();
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		n = 0; m = 0;
		scanf("%d %d",&n,&m);
		for(int j = 0; j < m; j++)
			scanf("%f",&list[j]);
		//cout<<c<<" "<<n<<" "<<m<<endl;
		//printf("%.2f\n",search());
		pre();
		printf("%.2f\n",dynamic(0,1));
	}
}