#include<stdio.h>
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int m,q,n;
char str[500][11],input[100][11];
double B[500],T[500][500],M[500][500];
double cache[102][502];
int choice[102][502],R[500];
int root[500];

int matchIndex(char *a){
	for(int i = 0; i < m; i++)
		if( !strcmp(a,str[i]) ) return i;
	return -1;
}
double max(double a, double b){
	if(a > b) return a;
	return b;
}
/*double search(int pre, int now){
	if(pre == n) return 1;
	int index = matchIndex(input[pre+1]);
	int tempindex = index;
	
	double &ret = cache[pre+1][now];
	if(ret >= 0) return ret;
	
	if(pre == -1){
		double one = 0;
		double two = 0;
		for(int i = 0; i < m; i++){
			two = M[i][index] * B[i] * search(pre+1,i);
			if(one < two){
				one = two;
				tempindex = i;
			}
		}
		root[pre+1] = tempindex;
		return one;
	}
	double one = 0;
	double two = 0;
	for(int i = 0; i < m; i++){
		two = M[i][index] * T[now][i] * search(pre+1,i);
		if(one < two){
			one = two;
			tempindex = i;
		}
	}
	root[pre+1] = tempindex;
	return ret = one;
}*/

double recognize(int segment, int previousMatch){
	if(segment == n) return 0;
	double &ret = cache[segment][previousMatch];
	if(ret != 1.0) return ret;
	ret = -1e200;
	int &choose = choice[segment][previousMatch];
	for(int thisMatch = 0; thisMatch < m; ++ thisMatch){
		double cand = T[previousMatch][thisMatch] 
			+M[thisMatch][R[segment]]
			+recognize(segment+1, thisMatch);
		if(ret < cand){
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}
string corpus[501];
string reconstruct(int segment, int previousMatch){
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if(segment < n-1)
		ret = ret + " " + reconstruct(segment + 1,choose);
	return ret;
}
string middleware(){
	for(int j = 0; j < n; j++)
		for(int i = 0; i < m; i++)
			if( !strcmp( input[j],str[i]) ) R[j] = i;
	memset(cache,1.0,sizeof(double)*502*102);
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			T[i][j] = log10(T[i][j]);
			M[i][j] = log10(M[i][j]);
		}
	}
	recognize(0,0);
	return reconstruct(0,0);
}

void test(){
	printf("%d %d\n",m,q);
	for(int i = 0; i < m; i++)
		printf("%s ",str[i]);
	printf("\n");
	for(int i = 0; i < m; i++)
		printf("%lf ",B[i]);
	printf("\n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			printf("%lf ",T[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			printf("%lf ",M[i][j]);
		}
		printf("\n");
	}
}
void stdRelocate(){
	freopen("OCRinput.txt","r",stdin);
	freopen("OCRoutput.txt","w",stdout);
}
int main(void){
	stdRelocate();
	scanf("%d %d",&m,&q);
	for(int i = 0; i < m; i++)
		scanf("%s",str[i]);
	for(int i = 0; i < m; i++)
		scanf("%lf",B+i);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			scanf("%lf",&T[i][j]);
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			scanf("%lf",&M[i][j]);
		}
	}
	for(int i = 0; i < q; i++){
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%s",input[j]);
		}
		cout<<middleware();
		/*memset(cache,-1,sizeof(double)*502*102);
		printf("%lf ",search(-1,0));
		for(int j = 0; j < n; j++)
			printf("%s ",str[root[i]]);
		printf("\n");*/
	}
	//test();
}