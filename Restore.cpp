#include "stdConvert.h"
#define MAX_N 500
#include <sstream>
#include <algorithm>

int min(int a,int b){
	if(a < b) return a;
	return b;
}int max(int a,int b){
	if(a > b) return a;
	return b;
}
void setStd(){
	char in[] = "RestoreInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

int c,k;
string str[16];

int cache[16][1<<16];
int route[16][16];

int calcOverlap(string a, string b){
	int bStart = 0, bEnd = b.size();
	while(bEnd > 0){
		if(bStart+bEnd > a.size())
			bEnd--;
		else if(a.substr(bStart++,bEnd).compare(b.substr(0,bEnd)) == 0 )
			return bEnd;
	}
	return bEnd;
}
void overlap(){
	for(int i =  0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			route[i][j] = calcOverlap(str[i],str[j]);
		}
	}
}

int search(int last, int select){
	if(select == (1<<(k+1) -1) - 1) return 0;
	
	int &ret = cache[last][select];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int next = 1; next <= k; ++next){
		if((select & (1<<next)) == 0){
			int cand;
			if(str[last].size() >= str[next].size() + route[last][next] )
				cand = search(last, select + (1<<next));
			else 
				cand = route[last][next] + search(next, select + (1<<next));
			ret = max(ret, cand);
		}
	}
	return ret;
}

string completedString = "";
string conjString(string newStr, string addStr){
	int a = newStr.size() -1, b = 0;
	int count = 0;
	if(newStr.size() > addStr.size()){
		for(int i = 0; (i + addStr.size()) < newStr.size(); i++)
			if(newStr.substr(i,addStr.size()).compare(addStr) == 0)
				return newStr;
	}
	
	while( ( (a - count) >= 0 ) && ( (b + count) < addStr.size() ) ){
		if(newStr.at(a - count ) != addStr.at(b + count )) break;
		count++;
	}
	return newStr + addStr.substr(count, addStr.size() );
}

string reconstruct(int last, int select){
	if(select == (1<<(k+1 ) ) -1) return "";
	string res = str[last];
	for(int i = 1; i <=k; i++){
		if( (select & (1<<i)) ) continue;
		int temp = search(i,select + (1<<i) ) + route[last][i];
		if( temp == search(last, select) ){
			return (str[i].substr(route[last][i]) +
				   reconstruct(i,select + (1<<i) ) );
		}
	}
	return "##";
}

int main(void){
	setStd();
	scanf("%d",&c);
	str[0] = "";
	for(int i = 0; i < c; i++){
		scanf("%d",&k);
		memset(cache,-1,(sizeof(int)*16*(1<<16)));
		completedString = "";
		
		for(int j = 1; j <= k; j++){
			cin>>str[j];
		}
		
		overlap();
		cout<< reconstruct(0,1)<<endl;
		//cout<<"end : "<< ((1<<k) -1) << endl;
		//cout<<search(-1,0)<<endl;
	}
}