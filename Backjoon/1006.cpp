#include<stdio.h>
#include<iostream>
#define MAX_N 10001
#define MAX_W 10001

using namespace std;
const int search[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int n,w;
int Area[2*MAX_N];

void test(){
	for(int j = 0; j < 2 * n; j++){
		cout<<Area[j]<<" ";
		if((j+1)%n == 0) cout<<endl;
	}
	cout<<endl;
}

bool isClear(){
	for(int j = 0; j < 2*n; j++)
		if(Area[j] != 0 ) return false;
	return true;
}

int cache[MAX_N * 2];
int next(){
	//if(isClear()) return 0;
	test();
	
	int x = -1;
	for(int i = 0; i < 2*n; i++)
		if(Area[i] != 0){
			x = i;
			break;
		} 
	if(x == -1) return 0;
	
	int restW = w - Area[x];
	int res = MAX_N;
	Area[x] = 0;
	
	int nextX = -1;
	if(x < n){
		//case 1: (x - 1 + n ) % n
		//case 2: (x + 1 ) % n
		//case 3: (n + x)
		int temp,nextValue;
		if(Area[(x - 1 + n ) % n] != 0 && Area[(x - 1 + n ) % n] <= restW){
			temp = Area[(x - 1 + n ) % n];
			Area[(x - 1 + n ) % n] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX = ( x - 1 + n ) % n;
			}
			Area[(x - 1 + n ) % n] = temp;
		}
		if(Area[(x + 1 ) % n] != 0 && Area[(x + 1 ) % n] <= restW){
			
			temp = Area[(x + 1 ) % n];
			Area[(x + 1 ) % n] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX = (x + 1 ) % n;
			}
			Area[(x + 1 ) % n] = temp;
		}
		if(Area[(n + x)] != 0 && Area[(n + x)] <= restW){
			
			temp = Area[(n + x)];
			Area[(n + x)] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX = (n + x);
			}
			Area[(n + x)] = temp;
		}
	}else{
		//case 1: (x - 1 + n )
		//case 2: n + (x + 1 ) % n
		//case 3: (x - n)
		int temp,nextValue;
		if(Area[(x - 1 + n )] != 0 && Area[(x - 1 + n )] <= restW){
			temp = Area[(x - 1 + n )];
			Area[(x - 1 + n )] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX = (x - 1 + n );
			}
			Area[(x - 1 + n )] = temp;
		}
		if(Area[ n + (x + 1 ) % n] != 0 && Area[ n + (x + 1 ) % n] <= restW){
			
			temp = Area[ n + (x + 1 ) % n];
			Area[ n + (x + 1 ) % n] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX =  n + (x + 1 ) % n;
			}
			Area[ n + (x + 1 ) % n] = temp;
		}
		if(Area[(x - n)] != 0 && Area[(x - n)] <= restW){
			
			temp = Area[(x - n)];
			Area[(x - n)] = 0;
			nextValue = next();
			if(res > nextValue){
				res = nextValue;
				nextX = ((x - n));
			}
			Area[(x - n)] = temp;
		}
	}
	cout<<res<<endl;
	if(nextX == -1 ) return 1+next();
	return 1+res;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&n,&w);
		for(int j = 0; j < 2*n; j++)
			scanf("%d",&Area[j]);
		cout<<next()<<endl;
	}
}