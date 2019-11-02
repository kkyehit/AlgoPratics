#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> v;
vector<int> input;
int cache[50][50];

int op2(int a,int& point);
int op3(int a,int& point);
int search(int index,int& point);

int main(void){
	int in;
	int point = 0;
	memset(cache, -1, sizeof(cache));
	scanf("%d %d",&N, &M);
	for(int i = 1 ; i <= N; i++)
		v.push_back(i);
	for(int i = 0; i < M; i++){
		scanf("%d",&in);
		input.push_back(in);
	}
	printf("%d\n",search(0,point));
}
int search(int index,int& point){
	if(index >= M)
		return 0;
	int res = 0;
	int p2 = point, p3 = point;
	int v2 = 0, v3 = 0;
	if(point >= N)
		point = 0;
	while(v[point] == 0){
		point++;
		if(point >= N)
			point = 0;
	}
	int &ret = cache[index][point];
	if(ret != -1)
		return ret;
	if(v[point] == input[index]){
		v[point] = 0;
		point++;
		res = 0 + search(index + 1, point);
		v[point] = input[index];
	}else{
		v2 = op2(input[index],p2);
		v3 = op3(input[index],p3);
		
		v[input[index] - 1] = 0;
		p2++;p3++;
		v2 += search(index+1, p2);
		v3 += search(index+1, p3);
		v[input[index] - 1] = input[index];
		
		res = (v2 < v3) ? v2 : v3;
	}
	return ret = res;
}
int op2(int a,int& point){
	int res = 0;
	while(v[point] != a){
		if(v[point] == 0){
			point++;
			if(point >= N)
				point = 0;
			continue;
		}
		point++;
		if(point >= N)
			point = 0;
		res++;
		
	}
	return res;
}
int op3(int a,int& point){
	int res = 0;
	while(v[point] != a){
		if(v[point] == 0){
			point--;
			if(point < 0)
				point = N -1;
			continue;
		}
		point--;
		if(point < 0)
			point = N -1;
		res++;
		
	}
	return res;
}