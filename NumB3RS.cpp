#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>

using namespace std;
int C,n,d,p,t,q;
int A[51][51],Pos[51];
double B[101][51];

void test(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i= 0 ; i < n; i++)
		cout<<Pos[i]<<" ";
}

double search(int nowLocate,int nowDay){
	if(nowDay == d) return (nowLocate == p)? 1 : 0;
	
	double &ret = B[nowDay][nowLocate];
	if(ret >= 0) return ret;
	
	ret = 0;
	for(int i = 0; i < n; i++){
		if(A[nowLocate][i] == 1){
			ret += search(i,nowDay+1) / Pos[i];
//cout<<" "<<nowLocate<<" "<<i<<" "<<nowDay<<" "<<ret<<endl;
		}
	}
	return ret;
}

int main(void){
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		memset(B,-1,sizeof(double)*101*51);
		memset(Pos,0,sizeof(int)*51);
		scanf("%d %d %d",&n,&d,&p);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++){
				scanf("%d",&A[j][k]);
				if(A[j][k] == 1) Pos[j]++;
			}
		scanf("%d",&t);
		for(int j = 0; j < t; j++){
			scanf("%d",&q);
			printf("%0.8lf ",search(q,0));
		}
		cout<<endl;
	}
}