#include<cstdio>
#include<vector>
#include "stdConvert.h"
#define MAX_N 100
#define MAX_M 100
void setStd(){
	char in[] = "DarpaInput.txt";
	char out[] = "Output2.txt";
	convertStd c(in,out);
}

using namespace std;
typedef int type;
vector<type> v;
int n;
int m;
int parametric_condition(type leng){
    int ret = 0;
    int batch = 0;
    type set_batch = 0;
    for(int i = 0 ; i < m ; i++){
        if(i == 0){
            batch++;
            set_batch = v[0];
        }
        else if(v[i] - set_batch >= leng){
            batch++;
            set_batch = v[i];
        }
    }
 
    if(batch >= n){ // more batch, leng increase
        return 1;
    }else if(batch < n){ // less batch, leng decrease
        return -1;
    }
    return 0;
}
 
type round(type data){
    type ret = int(data*100)/100.0;
    if(data - ret > 0.005001) ret += 0.01;
    return ret;
}
type floorr(type data){
    type ret = int(data*100)/100.0;
    return ret;
}
type parametric_search(){
    type start = 0;
    type end = v[m-1];
    type mid;
    while(start < end){
        //start = round(start);
        //end = round(end);
        mid = (start+end)/2;
 
        if(start == end) return mid;
        switch(parametric_condition(mid)){
        case -1: // batch < n
            end = mid-1;
            break;        
        case 1: // batch > n
            start = mid+1;
            break;
        }
        
    }
    return mid;
}


int dif[MAX_M][MAX_M],cache[MAX_M][MAX_M];
void pre(){
	for(int i = 0; i < m; i++)
		for(int j = i; j < m; j++)
			dif[i][j] = v[j] - v[i];
	memset(cache,-1,sizeof(cache));
}
int dynamic(int index,int select){// 선택의 최소가 최대가 되도록,
	if(select >= n) return 240*10000;
	
	int &ret = cache[index][select];
	if(ret > -1 )return ret;
	
	int res = 0;
	int minDes = -1;
	for(int i = index+1; i < m; i++){
		minDes = min(dif[index][i], dynamic(i,select + 1));
		res = max(res,minDes);
	}
	return ret = res;
}

int main(){
	setStd();
    int tc;
    for(scanf("%d", &tc) ; tc-- ; ){
        scanf("%d%d",&n,&m);
        v.resize(m);
        for(int i = 0 ; i < m ; i++){
            float temp;
            scanf("%f",&temp);
            v[i] = temp*10000;
        }
        //printf("%.2f\n",(parametric_search()/10000.0));
		pre();
        printf("%.2f\n",(dynamic(0,1)/10000.0));
    }
    return 0;
}
