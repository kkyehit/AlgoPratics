#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
 
 
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