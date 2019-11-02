#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solve(const string &a){
	string res = "", temp = "";
	int iter = 0, n = a.size(), flag = 0;
	while(iter < n){
		if(flag == 0 ){
			if(a.at(iter++) == '('){
				flag = 1;
				continue;
			}
			res += a.at(iter - 1);
		}else if(flag == 1){
			if(a.at(iter++) == ')') continue;
			if(a.at(iter - 1) == '^'){
				flag = 2;
				continue;
			}
			temp += a.at(iter - 1);
		}else if(flag == 2){
			int t = a.at(iter) - '0';
			while((++iter < n )&&('0'<=a.at(iter) && a.at(iter) <= '9')){
				t *= 10;
				t += a.at(iter);
			}
			for(int i = 0; i < t; i++)
				res += temp;
			temp = "";
			flag = 0;
		}
	}
	return res;
}
void getLocate(const string & a,int &iter, int &start, int &end, int &count, int &next){
	start = iter + 1;
	end = start;
	while(a.at(++iter) != ')')
		end++;
	count = 0;
	++iter;
	while((++iter < a.size() )&&('0'<=a.at(iter) && a.at(iter) <= '9')){
		count *= 10;
		count += a.at(iter) - '0';
	}
	next = iter;
	iter = start;
}
bool solve2(const string &a, const string &b){
	int n = a.size(), m = b.size();
	int aiter = 0, astart = 0, aend = n, acount = 0, anext = n;
	int biter = 0, bstart = 0, bend = m, bcount = 0, bnext = m;
	vector< vector<bool> > cache(n,vector<bool>(m,false));
	while(true){
		if(aiter == n) return (biter == m)? true: false;
		if(biter == m) return false;
		
		if(a.at(aiter) == '(')
			getLocate(a,aiter,astart,aend,acount,anext);
		if(b.at(biter) == '(')
			getLocate(b,biter,bstart,bend,bcount,bnext);
		//cout<<"before count "<<acount<<" : "<<bcount<<endl;
		if(acount > 1 && bcount > 1)
			if(cache[aiter][biter]){
				if(acount > bcount) {
					acount = acount - bcount + 1;
					bcount = 1;
				}else{
					bcount = bcount - acount + 1;
					acount = 1;
				}
			}
		//cout<<"after count "<<acount<<" : "<<bcount<<endl;
		//cout<<"iter "<<aiter<<" : "<<biter<<" : "<<cache[aiter][biter]<<endl;
		//cout<<"compare "<<a.at(aiter)<<" : "<<b.at(biter)<<endl;
		if(a.at(aiter) == b.at(biter)){
			cache[aiter][biter] = true;
			if(++aiter == aend){
				if(--acount > 0){
					aiter = astart;
				}
				else
					aiter = anext;
			}
			if(++biter == bend){
				if(--bcount > 0)
					biter = bstart;
				else
					biter = bnext;
			}
		}else
			return false;
	}
	return false;
}

int main(void){
	freopen("DecualInput.txt","r",stdin);
	string A,B;
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>A;
		cin>>B;
		//A = solve(A);
		//B = solve(B);
		//printf("%d %d\n",'0','9');
		//if(A.compare(B) == 0 ) cout<<"YES"<<endl;
		//else cout<<"NO"<<endl;
		if(solve2(A,B)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}