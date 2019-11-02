#include<stdio.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>

using namespace std;

void MatchOrderInput(){
	
	srand( (unsigned int) time(NULL) );
	freopen("MatchOrderInput.txt","w",stdout);
	int T = rand()%50 + 1;
	printf("%d\n",T);
	for(int i = 0; i < T; i++){
		int N = rand()%100 + 1;
		printf("%d\n",N);
		for(int j = 0 ; j < N; j++){
			printf("%d", (rand()%4000 + 1) );
			if(j != N-1)printf(" ");
		}
		printf("\n");
		
		for(int j = 0 ; j < N; j++){
			printf("%d", (rand()%4000 + 1) );
			if(j != N-1)printf(" ");
		}
		printf("\n");
	}
}

void DarpaInput(){
	srand( (unsigned int) time(NULL));
	freopen("DarpaInput.txt","w",stdout);
	int C = rand()%50 + 1;
	cout<<C<<endl;
	int pre = -1;
	for(int i = 0; i < C; i++){
		vector<int> res;
		int n = rand()%99 + 2;
		int m = rand()%(200 - n) + n;
		for(int j = 0; j < m; j++){
			int next = rand()%24000 + 1;
			if(res.size() > 0 && res[res.size() - 1] == 24000) break;
			if(res.size() > 0 && res[res.size() - 1] >= next){
				j--;
				continue;
			}
			res.push_back(next);
		}
		n =  rand()%res.size() + 1;
		cout<<n<<" "<<res.size()<<endl;
		for(int j = 0; j < res.size(); j++){
			cout<<((double)res[j])/100<<" ";
		}
		cout<<endl;
	}
}

void ArcticInput(){
	srand( (unsigned int) time(NULL));
	freopen("ArcticInput.txt","w",stdout);
	int C = rand()%20 + 1;
	cout<<C<<endl;
	for(int i =0; i < C; i++){
		int n = rand()%20 +1;
		cout<<n<<endl;
		for(int j = 0; j < n; j++){
			cout<< (double)(rand()%100000)/100 <<" "<< (double)(rand()%100000)/100<<endl;
		}
	}
	
}

void potionInput(){
	srand((unsigned int) time(NULL) );
	freopen("PotionInput.txt","w",stdout);
	int c = 1;
	cout<<c<<endl;
	for(int i = 0 ; i < c; i++){
		int n = rand()%10 + 1;
		cout<<n<<endl;
		for(int j = 0 ; j < n; j++)
			cout<<rand()%10 + 1<<" ";
		cout<<endl;
		for(int j = 0 ; j < n; j++)
			cout<<rand()%10<<" ";
		cout<<endl;
	}
}
void MaxSumInput(){
	srand((unsigned int) time(NULL) );
	freopen("MaxSumInput.txt","w",stdout);
	int c = rand()%10 + 1;
	cout<<c<<endl;
	for(int i = 0 ; i < c; i++){
		int n = rand()%10 + 1;
		cout<<n<<endl;
		for(int j = 0 ; j < n; j++)
			cout<<rand()%201 - 100<<" ";
		cout<<endl;
	}
}
void FamilyTreeInput(){
	srand((unsigned )time(NULL));
	freopen("FamilyTreeInput.txt","w",stdout);
	int c = 1;
	printf("%d\n",c);
	while(c--){
		//int n = rand()%100000 + 1;
		//int q = rand()%10000 + 1;
		int n = 20;
		int q = rand()%100+1;
		printf("%d %d\n",n,q);
		int tempn = n;
		n--;
		for(int i = 0; i < 5; i++,n--){
			printf("%d ",i);
		}
		while(n--)
			printf("%d ",rand()%5);
		printf("\n");
		while(q--)
			printf("%d %d\n",rand()%tempn,rand()%tempn);
	}
}
int main(){
	FamilyTreeInput();
}