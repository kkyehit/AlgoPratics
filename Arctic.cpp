#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool checkPass(vector<bool> &pass){
	for(int i = 0; i<pass.size(); i++)
		if(!pass[i]) return false;
	return true;
}

void test(vector<bool> &pass){
	for(int i =0; i < pass.size(); i++)
		cout<<pass[i]<<" ";
	cout<<endl;
}

double search1(vector< vector<double> > &v, vector<bool> &pass,int index, double mindest){
	int nextIndex;
	double temp,temp2=9999999999;
	test(pass);
	if(checkPass(pass)) return mindest;
	for(int i = 1; i<pass.size(); i++){
		if((!pass[i]) && (i != index)){
			temp = (v[index][0] - v[i][0])*(v[index][0] - v[i][0]) + (v[index][1] - v[i][1]) * (v[index][1] - v[i][1]);
			if(temp < temp2){
				temp2 = temp;
				nextIndex = i;
			}
		} 
	}
	
cout<<" Index ("<<index<<") -> nextIndex ("<<nextIndex<<") "<<temp2;
	temp = (v[0][0] - v[nextIndex][0])*(v[0][0] - v[nextIndex][0]) + (v[0][1] - v[nextIndex][1]) * (v[0][1] - v[nextIndex][1]);
cout<<" 0 -> nextIndex "<<temp;
	if(temp < temp2) temp2 = temp;
	pass[nextIndex] = true;
cout<<" temp2 "<<temp2<<" mindest "<<mindest<<endl;
	double ret;
	if(temp2 < mindest) ret = search1(v,pass,nextIndex,mindest);
	else ret = search1(v,pass,nextIndex,temp2);
	return ret;
}

int main(void){
	int C, N;
	double input;
	scanf("%d",&C);
	for(int i = 0 ; i < C ; i++){
		scanf("%d",&N);
		vector< vector<double> > v(N, vector<double>(2) );
		vector<bool> pass(N,false);
		pass[0] = true;	
		for(int j = 0; j < N; j++){
			for(int k = 0; k <2; k++){
				scanf("%lf",&input);
				v[j][k] = input;
			}
		}
		cout<<sqrt(search1(v,pass,0,-1))<<endl;	
	}
}
