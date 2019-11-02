#include "stdConvert.h"
#define MAX_K 15
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
/*
int k,T[MAX_K][MAX_K],cache[MAX_K][1<<MAX_K];
string inputStr[MAX_K];

int test(){
	
	for(int i =0; i < k; i++){
		for(int j = 0; j < k; j++)
			cout<<T[i][j]<<" ";
		cout<<endl;
	}
	
	for(int i =0; i < k; i++){
		for(int j = 0; j < (1<<k); j++)
			cout<<cache[i][j]<<" ";
		cout<<endl;
	}
	
}

int calc(int one, int two){
	int res = inputStr[one].size();
	
	string tempOne = inputStr[one],tempTwo = inputStr[two];
	cout<<tempOne<<" "<<tempTwo<<endl;
	while(tempOne.size() != 0 && tempTwo.size() != 0){
		if(tempOne.at(tempOne.size()-1) == tempTwo.at(0) ){
			tempOne = tempOne.substr(0,--res);
			tempTwo = tempTwo.substr(1);
		}
		else break;
	}
	return res;
}

void makeT(){
	for(int i =0; i < k; i++)
		for(int j = 0; j < k; j++){
			T[i][j] = calc(i,j);
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
			if(inputStr[last].size() >= inputStr[next].size() + T[last][next] )
				cand = search(last, select + (1<<next));
			else 
				cand = T[last][next] + search(next, select + (1<<next));
			ret = max(ret, cand);
		}
	}
	return ret;
}


string overlap(string a, string b){
//cout<<" a : "<<a<<" b : "<<b<<endl;

	if(b.size() == 0) return a;
	if(a.size() == 0) return b;
	if(b.size() < a.size() ){
		int bStart = 0, bEnd = b.size();
		while(bEnd > 0){
			if(bStart+bEnd > a.size())
				bEnd--;
			else if(a.substr(bStart++,bEnd).compare(b.substr(0,bEnd)) == 0 )
				break;
		}
		if(bEnd == 0) return a.substr(0,bStart) + b;
		else if( bStart+bEnd > a.size() ) return a.substr(0,--bStart) + b;
		return a;
	}else{
		int aStart = 0, aEnd = a.size();
		while(aEnd > 0){
			if(aStart+aEnd > b.size())
				aEnd--;
			else if(b.substr(aStart++,aEnd).compare(a.substr(0,aEnd)) == 0 )
				break;
		}
		if(aEnd == 0) return b.substr(0,aStart) + a;
		else if( aStart+aEnd > b.size() ) return b.substr(0,--aStart) + a;
		return b;
	}
}

string search2(string pre,int select){
	int stringSize = 99999999;
	string res=pre,temp;
	
	for(int i = 0; i < k; i++){
		if(select&(1<<i)) continue;
//cout<<"sel : "<<select<<" pre : "<<pre<<" temp : "<<temp<<endl;
		temp = overlap(pre,search2(inputStr[i],select | (1<<i) ) );
		if(temp.size() < stringSize){
			stringSize = temp.size();
			res = temp;
		}
	}
	return res;
}
string search3(){
	int stringSize = 99999999;
	string res,temp = "";
	
	for(int i = 0; i < k; i++){
		temp = overlap(temp,inputStr[i] );
	}
	return temp;
}*/

int k;
int overlap[MAX_K][MAX_K], cache[MAX_K][1<<MAX_K];


int test(vector<string> &a){
	for(int j = 0; j < a.size(); j++)
		cout<<a[j]<<endl;
	cout<<endl;
	
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a.size(); j++)
			cout<<overlap[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void preDel(vector<string> &a){
	
	for(int i = 0 ; i < k; i++){
		string temp = a[0];
		a.erase(a.begin());
		
		for(int j = 0; j < a.size(); j++){
			if(temp.size() >= a[j].size() ){
				int aStart = 0, aEnd = a[j].size();
				while(aStart + aEnd < temp.size() ){
//cout<<" "<<temp<<" // aStart : "<<aStart<<" aEnd : "<<aEnd<<" // "<<temp.substr(aStart,aEnd)<<" "<<a[j]<<endl;
					if(temp.substr(aStart++,aEnd).compare(a[j]) == 0 ){
						a.erase(a.begin() + j--);
						break;
					}
				}
			}
		}
		a.push_back(temp);
	}
	
}
int calOverlap(string a, string b){
	if(a.compare(b) == 0) return 0;
	int aEnd = a.size() -1, bStart = 1;
	int res = 0;
	while(aEnd >= 0 && bStart <= b.size() ){
		if(a.substr(aEnd--).compare(b.substr(0,bStart++)) == 0) res = bStart - 1;
	}
	return res;
}

void calc(vector<string> &a){
	for(int i = 0 ; i < a.size(); i++)
		for(int j = 0 ; j < a.size(); j++)
			overlap[i][j] = calOverlap(a[i],a[j]);
	
}

int search(vector<string> &a, int last, int selected){
	if(selected == (1<<a.size()) -1 ) return 0;
	
	int &ret = cache[last][selected];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i = 0; i < a.size(); i++){
		if(selected & (1<<i) ) continue;
		ret = max(ret, overlap[last][i] + search(a,i,selected | (1<<i) ) );
	}
	return ret;
}

string reconstruct(vector<string> &a, int last, int selected){
	if(selected == (1<<a.size()) -1 ) return "";
	for(int i = 0; i < a.size(); i++){
		if( (selected & (1<<i)) ) continue;
		int ifUse = overlap[last][i] + search(a,i, (selected | (1<<i) ) );
//cout<<" "<<overlap[last][i]<<" // last : "<<last<<" next : "<<i<<" // "<<search(a,i, (selected | (1<<i) ) )<<" "<<search(a,last, selected)<<endl;
		if(ifUse == search(a,last, selected) )
			return (a[i].substr(overlap[last][i]) + 
				   reconstruct(a,i, (selected | (1<<i)) ) );
	}
	return "##";
}

int main(void){
	setStd();
	
	int c;
	string temp;
	scanf("%d",&c);
	for(int i = 0; i< c; i++){
		vector<string> a;
		memset(cache,-1,sizeof(int)*(1<<MAX_K)*MAX_K);
		scanf("%d",&k);
		for(int j = 0; j < k; j++){
			cin>>temp;
			a.push_back(temp);	
		}
		preDel(a);
		calc(a);
		int MaxLength = -1, MaxIndex;
		for(int j = 0; j < a.size(); j++){
//cout<<"MaxLength : "<<MaxLength<<" search : "<<search(a,j,0)<<endl;
			if(MaxLength < search(a,j,(1<<j) ) ){
				MaxLength = search(a,j,(1<<j) );
				MaxIndex = j;
			}
		}
		cout<<a[MaxIndex]+reconstruct(a,MaxIndex,(1<<MaxIndex))<<endl;
		//test(a);
	}
}