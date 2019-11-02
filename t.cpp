#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

using namespace std; 

int unpack(string s1){
	int hour, min, sec;
	hour = (s1[3]-'0')*10 + (s1[4]-'0');
	min = (s1[6]-'0')*10 + (s1[7]-'0');
	sec = (s1[9]-'0')*10 + (s1[10]-'0');
	if(s1[0] == 'p' || s1[0] == 'P' )
		hour += 12;
	return hour*3600 + min * 60 + sec;
}
string pack(int hour, int min, int sec){
	string res = "";
	int temp;
	temp = hour / 10;
    res.push_back(temp + '0');
    temp = hour % 10;
    res.push_back(temp + '0');
    
    res.push_back(':');    
    
    temp = min / 10;
    res.push_back(temp + '0');
    temp = min % 10;
    res.push_back(temp + '0');
    
    res.push_back(':');
        
    temp = sec / 10;
    res.push_back(temp + '0');
    temp = sec % 10;
    res.push_back(temp + '0');

	return res;
}

int main(void){
	string s1, s2, ramian;
	int dif;
	getline(cin,s1);
	getline(cin,s2);
	cout<<s1<<endl;
	cout<<s2<<endl;
	dif = unpack(s2)- unpack(s1);
	if(dif < 0)
		dif = 24 * 3600 + dif;
	cout<<pack(dif / 3600, dif % 3600 / 60,  dif % 3600 % 60)<<endl;
}