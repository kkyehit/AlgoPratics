#include "stdConvert.h"
#include <cassert>
#define MAX_N 50
#define MAX_M 10
#define MAX_K 1000000


 
struct SquareMatrix {
    int N;
    vector<vector<double> > v;
    SquareMatrix(int _N);
    ~SquareMatrix();
    static SquareMatrix identity(int N);
    SquareMatrix operator * (const SquareMatrix& rhs) const;
    SquareMatrix pow(int n) const;
    double* operator [] (int idx);
};
 
SquareMatrix::SquareMatrix(int _N) {
    N = _N;
    v.resize(N, vector<double>(N, 0));
}
 
SquareMatrix::~SquareMatrix() {
}
 
SquareMatrix SquareMatrix::identity(int N) {
    SquareMatrix ret = SquareMatrix(N);
    for(int i = 0; i < N; i++) ret.v[i][i] = 1;
    return ret;
}
 
SquareMatrix SquareMatrix::operator * (const SquareMatrix& rhs) const {
    assert(N == rhs.N);
 
    SquareMatrix ret = SquareMatrix(N);
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                ret.v[i][j] += v[i][k] * rhs.v[k][j];
    return ret;
}
 
SquareMatrix SquareMatrix::pow(int n) const {
    if(n == 0) return identity(N);
    if(n % 2 > 0) return (*this) * pow(n-1);
    SquareMatrix half = pow(n/2);
    return half * half;
}
 
double* SquareMatrix::operator [] (int idx) {
    return &v[idx][0];
}

void setStd(){
	char in[] = "GeniusInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int n,k,m;
int Li[MAX_N],Qi[MAX_M];
double T[MAX_N][MAX_N];

vector<double> getProb2(){
	SquareMatrix w(4*n);
	
	for(int i = 0; i < 3*n; ++i)
		w[i][i+n] = 1.0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			w[3*n+i][(4-Li[j])*n + j] = T[j][i];
	SquareMatrix Wk = w.pow(k);
	vector<double> ret(n);
	for(int song = 0; song < n; ++song)
		for(int start = 0; start < Li[song]; ++start)
			ret[song] += Wk[(3-start)*n+song][3*n];
	return ret;
}

int main(void){
	setStd();
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d %d",&n,&k,&m);
		for(int j = 0; j < n; j++)
			scanf("%d",Li+j);
		for(int j = 0; j < n; j++)
			for(int l = 0; l < n; l++)
				scanf("%lf",&T[j][l]);
		for(int j = 0; j < m; j++)
			scanf("%d",Qi+j);
		
		vector<double> a = getProb2();
		for(int j = 0; j < m; j++){
			printf("%0.8lf",a[j]);
			if(j != m -1) printf(" ");
		}
		cout<<endl;
	}
}