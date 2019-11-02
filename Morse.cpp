#include "stdConvert.h"

void setStd(){
	char in[] = "MorseIn.txt";
	char out[] = "MorseOut.txt";
	convertStd c(in,out);
}
/*
int n,m;
unsigned long long k;
int cache[100][100];

unsigned long long factorial(int restN,int restM){
	int big = restM , small = restN;
	if( restN > restM){
		big = restN;
		small = restM;
	}
	unsigned long long seq = 1;
	for(int i = restN + restM; i > big; i--){
		seq *= i;
		if((small != 0) && (seq % small == 0)) seq /= small--;
		if(seq == 0) return 1000000000;
	}
//cout<<"	"<<restN<<" "<<restM<<" "<<seq<<endl;
	return seq;
}

string search(int restN,int restM, string res){
	if((restN == 0 || restM == 0 )&& k == 1){
		while(restN-- > 0)
			res += "-";
		while(restM-- > 0)
			res += "o";
		return res;
	}else if(restN == 0 || restM == 0 ){
//cout<<k<<" ";
		return 0;
	}
	unsigned long long one = factorial(restN-1,restM);
	
	if(k <= one){
		res += "-";
		return search(restN-1,restM,res);
	}else{
		k -= one;
//cout<<"	k : "<<k<<endl;
		res += "o";
		return search(restN,restM-1,res);
	}
}

int main(void){
	setStd();
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		string res;
		scanf("%d %d %lld",&n,&m,&k);
		memset(cache,-1,sizeof(int)*100*100);
		res = search(n,m,res);
		cout<<res<<endl;
	}
}
*/

int n,m;
int k;
int cache[100][100];

void generate(int n, int m, string s){
	if( n == 0 && m == 0){
		cout<< s <<endl;
		return;
	}
	if(n > 0) generate(n-1,m, s+"-");
	if(m > 0) generate(n,m-1, s+"o");
}
void generate2(int n, int m, string s){
	if(k < 0) return;
	if( n == 0 && m == 0){
		if(k == 0) cout<< s <<endl;
		--k;
		return;
	}
	if(n > 0) generate2(n-1,m, s+"-");
	if(m > 0) generate2(n,m-1, s+"o");
}

int min(int a, int b){
	if(a < b) return a;
	return b;
}
const int M = 1000000000 + 100;
int bino[201][201];
void calcBino(){
	memset(bino, 0, sizeof(bino));
	for(int i = 0; i <= 200; ++i){
		bino[i][0] = bino[i][i] = 1;
		for(int j = 1; j < i; ++j)
			bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
	}
}
void generate3(int n, int m, string s){
	if(k < 0) return;
	if( n == 0 && m == 0){
		if(k == 0) cout<< s <<endl;
		--k;
		return;
	}
	if(bino[n+m][n] <= k){
		k -= bino[n+m][n];
		return;
	}
	if(n > 0) generate3(n-1,m, s+"-");
	if(m > 0) generate3(n,m-1, s+"o");
}
string kth(int n, int m, int skip){
	if(n == 0) return string(m,'o');
	if(skip < bino[n+m-1][n-1])
		return "-" + kth(n-1, m, skip);
	return "o" +kth(n,m-1,skip - bino[n+m-1][n-1]);
}
int main(void){
	setStd();
	int C;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		string res;
		scanf("%d %d %d",&n,&m,&k);
		memset(cache,-1,sizeof(int)*100*100);
		calcBino();
		cout<<kth(n,m,k-1)<<endl;
	}
}