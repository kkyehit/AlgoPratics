#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

class convertStd{
	public:
	convertStd(char *in,char *out){
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
	}
};