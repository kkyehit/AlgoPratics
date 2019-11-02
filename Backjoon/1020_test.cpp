#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define xx first
#define yy second

string s;
const int lineCnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int dp[16][110][2];

int solve(int pos, int left, bool bigger){
	if(left < 0) return 10;
	if(pos == s.size()) return (bigger && !left ? 0 : 10);
	int &ret = dp[pos][left][bigger];
	if(ret != -1) return ret;

	ret = 10;
	for(int i=(bigger ? 0 : s[pos]-'0'); i<=9; ++i){
		int next = solve(pos+1, left - lineCnt[i], bigger || (i > s[pos]-'0'));
		if(next != 10){
			ret = i;
			break;
		}
	}
	return ret;
}

//dp 배열을 역추적하며 실제 수를 알아낸다.
ll goRet;
ll go(int pos, int left, bool bigger){
	if(pos == s.size()) return 0;
	int &ret = dp[pos][left][bigger]; 
	goRet = goRet * 10 + ret;
	go(pos+1, left - lineCnt[ret], bigger || (ret > s[pos]-'0'));
}

ll tenPow(int a){
	return (a ? 10 * tenPow(a-1) : 1);
}

long long int stringToInt(string &str){
	long long int  res = 0;
	for(int i = 0; i < str.size(); i++){
		res *= 10;
		res += (str[i] - '0');
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	
	int sum = 0;
	for(int i = 0 ; i < input.size(); i++)
		sum += lineCnt[input[i] - '0'];

	//순환 한 후의 답을 구한다.
	memset(dp, -1, sizeof(dp));
	s = string(input.size(), '0');
	solve(0, sum, 0);
	goRet = 0;
	go(0, sum, 0);
	ll ans = goRet - stringToInt(input) + tenPow(s.size());

	//순환하기 전의 답을 구한다.
	memset(dp, -1, sizeof(dp));
	s = input;
	if(solve(0, sum, 0) != 10){
		goRet = 0;
		go(0, sum, 0);
		ans = goRet - stringToInt(input);
	}

	cout << ans;
}