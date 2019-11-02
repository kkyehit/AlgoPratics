
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void test(vector< vector<bool> > &metrix){
	for(int i = 0; i < metrix.size(); i++){
		for(int j = 0; j < metrix[i].size(); j++)
			cout<<metrix[i][j];
		cout<<endl;
	}
}
int search(vector<vector<bool> > &metrix, vector<bool> &isfriend){
	int index = -1;
	for(int i = 0; i < isfriend.size(); i ++){
		if(!isfriend[i]){
			index = i;
			break;
		}	
	}
	if(index == -1) return 1;
	
	int res = 0;
	for(int i = 0; i < metrix[index].size(); i++){
		if(metrix[index][i] && !isfriend[i]){
			isfriend[i] = true;
			isfriend[index] = true;
			res += search(metrix,isfriend);
			isfriend[i] = false;
			isfriend[index] = false;
		}
	}
	return res;
}

int main(void){

	int C,n,m;
	int f1,f2;
	int res[50];	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d %d",&n,&m);
		vector<bool> isfriend(n,false);
		vector< vector<bool> > matrix(n,vector<bool>(n,false));
		for(int j = 0; j < m; j++){
			scanf("%d %d",&f1,&f2);
			matrix[f1][f2] = true;
			matrix[f2][f1] = true;
		}
		res[i] = search(matrix,isfriend);
	}
	for(int i = 0;i < C; i++)
		cout<<res[i]<<endl;
}

