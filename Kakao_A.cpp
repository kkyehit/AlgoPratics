#include<stdio.h>
#include<vector>

using namespace std;

const int price[2][6] ={{5000000,3000000,2000000,500000,300000,100000},
				  {5120000,2560000,1280000,640000,320000,0}};
const int person[2][6] = {{1,3,6,10,15,21},
					{1,3,7,15,31,0}};

int PriceA(int &a){
	if(a == 0 || a > person[0][5] ) {
		return 0;
	}
	for(int i = 0; i<6; i++){
		if(a <= person[0][i])
			return price[0][i];
	}
	return 0;
}
int PriceB(int &b){
	if(b == 0 || b > person[1][4] ) {
		return 0;
	}
	for(int i = 0; i<5; i++){
		if(b <= person[1][i])
			return price[1][i];
	}
	return 0;
}
int main(void){
	int T;
	scanf("%d",&T);
	vector<int> res;
	
	int a,b;
	for(int i = 0; i < T; i++){
		scanf("%d %d",&a,&b);
		
		//res.push_back((PriceA(a) + PriceB(b)));
		printf("%d\n",(PriceA(a) + PriceB(b)));
		//printf("%d\n",PriceA(a));
		//printf("%d\n",PriceB(b));
	}
	//for(int i = 0; i < res.size(); i++){
		//printf("%d",res[i]);
		//if(i+1 != res.size())
			//printf("\n");
	//}
	
}