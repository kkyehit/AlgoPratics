#include <iostream>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef long long int int64;

bool check[30];

int main(void){
	int T;
	string str;
	cin>>T;
	for(int i = 1; i <= T; i++){
		cin>>str;
		
		int64 kind = 0, res = 1;
		for(int j = 0; j < str.length(); j++){
			memset(check,0,sizeof(check));
			for(int k = j - 1; k <= j + 1; k++){
				if(k < 0 || k>= str.length()) continue;
				check[str[k]- 'a'] = true;
			}
			kind = 0;
			for(int k = 0; k < 30; k++){
				if(check[k]){
					kind++;
				}
			}
			res = ( res * kind ) % MOD;
		}
		
		cout<<"#"<<i<<" "<<res<<endl;
	}
}